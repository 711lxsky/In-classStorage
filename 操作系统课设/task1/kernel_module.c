#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/rcupdate.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/sched/signal.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZhaoYuyang");
MODULE_DESCRIPTION("A simple kernel module with a list and two threads.");

// 链表
static struct list_head my_list;
// 两个线程任务
static struct task_struct *thread1, *thread2;

// 自旋锁
spinlock_t lock;

// 进程信息
struct pid_node {
    int pid;
    char comm[TASK_COMM_LEN];
    struct list_head list;
};

// 线程1执行函数
static int thread1_func(void *data) {
    struct task_struct *task;
    struct pid_node *node;

    while (!kthread_should_stop()) {
        for_each_process(task) {
            // 手动申请内存
            node = kmalloc(sizeof(*node), GFP_KERNEL);
            if (!node) {
                // 申请失败
                printk(KERN_INFO "--------------- Memory allocation failed for new node\n");
                continue;
            }

            node->pid = task->pid;
            get_task_comm(node->comm, task);
            // 获取锁
            spin_lock(&lock);
            // 添加节点
            list_add_tail(&node->list, &my_list);
            // 释放锁
            spin_unlock(&lock);
            printk(KERN_INFO "========== Added PID: %d, Comm: %s\n", node->pid, node->comm);
            msleep_interruptible(100); // 手动睡眠 100ms
        }
    }

    return 0;
}

// 线程2执行函数
static int thread2_func(void *data) {
    struct pid_node *node;
    struct list_head *pos, *n;

    printk(KERN_INFO "Thread 2 starting\n");

    while (!kthread_should_stop()) {
        // 获取锁
        spin_lock(&lock);
        list_for_each_safe(pos, n, &my_list) {
            // 取出节点并打印
            node = list_entry(pos, struct pid_node, list);
            printk(KERN_INFO "++++++++++ PID: %d, Comm: %s\n", node->pid, node->comm);
            list_del(pos);
            // 手动释放内存
            kfree(node);
        }
        // 释放锁
        spin_unlock(&lock);
        msleep_interruptible(1000); // Sleep for 1000ms
    }


    printk(KERN_INFO "+++++++++ Thread 2 stopping\n");
    return 0;
}

// 模块加载时执行的函数
static int kernel_module_init(void) {
    printk(KERN_INFO "============= List and thread module init\n");

    // 加载链表和锁
    INIT_LIST_HEAD(&my_list);
    spin_lock_init(&lock);

    // 创建线程1
    thread1 = kthread_create(thread1_func, NULL, "thread1");
    if (IS_ERR(thread1)) {
        printk(KERN_INFO "------------ Failed to create thread1\n");
        return PTR_ERR(thread1);
    }

    // 创建线程2
    thread2 = kthread_create(thread2_func, NULL, "thread2");
    if (IS_ERR(thread2)) {
        printk(KERN_INFO "------------ Failed to create thread2\n");
        return PTR_ERR(thread2);
    }

    // 唤醒线程并执行
    wake_up_process(thread1);
    wake_up_process(thread2);

    return 0;
}

// 模块卸载时执行函数
static void kernel_module_exit(void) {
    struct pid_node *node;
    struct list_head *pos, *n;

    printk(KERN_INFO "############# List and thread module exit starting\n");
    // 手动停止线程
    if (thread1) {
        kthread_stop(thread1);
    }
    if (thread2) {
        kthread_stop(thread2);
    }
    // 手动清理没有释放的线程内存
    spin_lock(&lock);
    list_for_each_safe(pos, n, &my_list) {
        node = list_entry(pos, struct pid_node, list);
                printk(KERN_INFO "############ Cleaning up PID: %d, Comm: %s\n", node->pid, node->comm);
        list_del(pos);
        kfree(node);
    }
    spin_unlock(&lock);

    printk(KERN_INFO "########## List and thread module exit\n");
}

module_init(kernel_module_init);
module_exit(kernel_module_exit);
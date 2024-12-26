#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/workqueue.h>
#include <linux/atomic.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZhaoYuyang");
MODULE_DESCRIPTION("延迟队列实验");

// 声明工作队列
static struct workqueue_struct *my_workqueue;

// 定义工作上下文结构体
struct work_ctx {
    struct work_struct work;
    int current_id;
};

// 声明延迟工作的结构体
struct delayed_work my_work;

// 声明工作上下文数组
struct work_ctx works[10];

// 声明内核线程数组
struct task_struct *threads[10];

// 默认学号，可以作为模块参数传入
static int student_id = 439;
module_param(student_id, int, 0644);
MODULE_PARM_DESC(student_id, "Student ID for the experiment");

/**
 * kthread_handler - 内核线程处理函数
 * @data: 传递给线程的数据指针
 *
 * 此函数用于处理内核线程中的任务，并打印当前处理的ID。
 */
int kthread_handler(void *data) {
    struct work_ctx *ctx = (struct work_ctx *)data;
    printk(KERN_INFO "====[Deferred Work] Kernel Thread for ID: %d is running\n", ctx->current_id);
    return 0;
}

/**
 * work_queue_handler - 工作队列处理函数
 * @work: 工作结构体指针
 *
 * 此函数用于处理工作队列中的任务，并打印当前处理的ID。
 */
void work_queue_handler(struct work_struct *work) {
    struct work_ctx *ctx = container_of(work, struct work_ctx, work);
    printk(KERN_INFO "====[Deferred Work] Work Queue handling ID: %d\n", ctx->current_id);
}

/**
 * delayed_work_handler - 延迟工作处理函数
 * @work: 工作结构体指针
 *
 * 此函数用于处理延迟工作，并打印执行信息。
 */
void delayed_work_handler(struct work_struct *work) {
    printk(KERN_INFO "====[Deferred Work] Delayed Work executed!\n");
}

/**
 * deferred_work_init - 模块初始化函数
 *
 * 此函数用于初始化模块，创建工作队列、工作项和内核线程，并调度延迟工作。
 * 返回值:
 *   0 - 成功
 *   -ENOMEM - 内存不足
 */
int deferred_work_init(void) {
    printk(KERN_INFO "====[Deferred Work] Module Init - Student ID starts from: %d\n", student_id);
    int i;

    // 创建工作队列
    my_workqueue = create_workqueue("my_deferred_workqueue");
    if (!my_workqueue) {
        printk(KERN_ALERT "====[Deferred Work] Failed to create workqueue\n");
        return -ENOMEM;
    }

    // 初始化并排队工作项，创建内核线程
    for (i = 0; i < 10; i++) {
        works[i].current_id = student_id + i;
        INIT_WORK(&works[i].work, work_queue_handler);
        printk(KERN_INFO "====[Deferred Work] Queuing work for ID: %d\n", works[i].current_id);
        queue_work(my_workqueue, &works[i].work);

        threads[i] = kthread_create(kthread_handler, &works[i], "kthread_worker_%d", i);
        if (!IS_ERR(threads[i])) {
            printk(KERN_INFO "====[Deferred Work] Starting kernel thread for ID: %d\n", works[i].current_id);
            wake_up_process(threads[i]);
        } else {
            printk(KERN_ALERT "====[Deferred Work] Failed to create kernel thread for ID: %d\n", works[i].current_id);
        }
    }

    // 初始化并调度延迟工作
    INIT_DELAYED_WORK(&my_work, delayed_work_handler);
    printk(KERN_INFO "====[Deferred Work] Scheduling delayed work to run after 5 seconds\n");
    schedule_delayed_work(&my_work, msecs_to_jiffies(5000));

    return 0;
}

/**
 * deferred_work_exit - 模块退出函数
 *
 * 此函数用于清理模块，停止内核线程，销毁工作队列，并取消延迟工作。
 */
void deferred_work_exit(void) {
    int i;

    // 停止内核线程
    for (i = 0; i < 10; i++) {
        if (threads[i]) {
            printk(KERN_INFO "====[Deferred Work] Stopping kernel thread for ID: %d\n", works[i].current_id);
            kthread_stop(threads[i]);
        }
    }

    // 销毁工作队列
    if (my_workqueue) {
        printk(KERN_INFO "====[Deferred Work] Destroying workqueue\n");
        destroy_workqueue(my_workqueue);
    }

    
    cancel_delayed_work(&my_work);
    printk(KERN_INFO "====[Deferred Work] Module Exit\n");
}

module_init(deferred_work_init);
module_exit(deferred_work_exit);

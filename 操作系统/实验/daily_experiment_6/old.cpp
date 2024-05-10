#include <iostream>
#include <pthread.h> // POSIX 线程库
#include <semaphore.h> // 信号量
#include <vector>
#include <unistd.h>

// 定义缓冲区大小
const int BUFFER_SIZE = 10;

// 产品数量
const int PRODUCT_SIZE = 20;

// 模拟缓冲区，用于存放“产品”
std::vector<int> buffer;

// 信号量
sem_t product;  // 已经生产的产品数量
sem_t empty; // 缓冲区剩余空间数量
sem_t mutex; // 互斥信号量，用于缓冲区的互斥访问

// 生产者函数
void* producer(void* arg) {
    for (int i = 0; i < PRODUCT_SIZE; ++i) {
        // 检查缓冲区是否已满
        int cur_buffer_size;
        sem_getvalue(&empty, &cur_buffer_size);
        if (cur_buffer_size <= 0) {
            std::cout << "++++ Buffer is full, Producer is waiting..." << std::endl;
        }
        // 阻塞等待缓冲区有空间
        // 尝试减少空间数量，如果空间数量小于0，则阻塞
        sem_wait(&empty);
        // 进入临界区，获取互斥锁
        sem_wait(&mutex);
        // 生产产品并放入缓冲区
        buffer.push_back(i);
        std::cout << "---- Producer produced: $" << i << std::endl;
        // 离开临界区
        sem_post(&mutex);
        // 增加已生产产品的数量
        // 缓冲区有新产品可用，唤醒等待的消费者
        sem_post(&product);
        // 模拟生产耗时
        sleep(0.5);
    }
    std::cout << "---- Producer finished producing all products." << std::endl;
    return nullptr;
}

// 消费者函数
void* consumer(void* arg) {
    for (int i = 0; i < PRODUCT_SIZE; ++i) {
        // 检查缓冲区是否为空
        int cur_buffer_size;
        sem_getvalue(&empty, &cur_buffer_size);
        if(cur_buffer_size >= BUFFER_SIZE) {
            std::cout << "++++ Buffer is empty, Consumer is waiting...\n" << std::endl;
        }
        // 等待有产品可以消费
        sem_wait(&product);
        // 进入临界区
        sem_wait(&mutex);
        std::cout << "\n#### Before consumption, buffer contents: ";
        for (const auto& product : buffer) {
            std::cout << product << " ";
        }
        std::cout << std::endl;
        // 从缓冲区取出产品消费
        int product = buffer.back();
        buffer.pop_back();
        std::cout << "==== consumer consumed: $" << product << std::endl;
        std::cout << "#### After consumption, buffer contents: ";
        for (const auto& product : buffer) {
            std::cout << product << " ";
        }
        std::cout << std::endl << std::endl;
        // 离开临界区
        sem_post(&mutex);
        // 增加缓冲区空间数量
        sem_post(&empty);
        // 模拟消费耗时
        sleep(1);
    }
    std::cout << "==== Consumer finished consuming all products." << std::endl;
    return nullptr;
}

int main() {
    // 初始化信号量, 第二个参数表示互斥量非命名，只能在当前进程使用
    sem_init(&product, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);
    // 初始值为1, 表示只允许有一个线程持有该锁，此处是一个线程访问缓冲区
    sem_init(&mutex, 0, 1);

    // 创建生产者和消费者线程
    pthread_t prod, cons;
    pthread_create(&cons, nullptr, consumer, nullptr);
    pthread_create(&prod, nullptr, producer, nullptr);

    // 等待线程结束
    pthread_join(prod, nullptr);
    pthread_join(cons, nullptr);

    // 销毁信号量
    sem_destroy(&product);
    sem_destroy(&empty);
    sem_destroy(&mutex);

    return 0;
}

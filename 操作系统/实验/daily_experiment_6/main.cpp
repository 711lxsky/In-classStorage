#include <iostream>
#include <pthread.h>  // 线程库
#include <semaphore.h> // 信号量
#include <vector>
#include <unistd.h>
#include <atomic> // 原子操作， 类似Java里的线程安全类型变量

// 全局设定
const int BUFFER_SIZE = 10; // 缓冲区大小
const int MAX_PRODUCTS = 50; // 产品上限数量
std::atomic<int> productsProduced(0); // 已生产的产品数量
std::atomic<int> productsConsumed(0); // 已消费的产品数量

std::vector<int> buffer; // 缓冲区
sem_t product, empty, mutex; // 信号量

std::atomic<bool> stopRequested(false); // 停止标志

// 生产者和消费者数量、耗时设置
const int NUM_PRODUCERS = 2; // 生产者数量
const int NUM_CONSUMERS = 3; // 消费者数量
const int PRODUCER_SLEEP_TIME = 1; // 生产者耗时（秒）
const int CONSUMER_SLEEP_TIME = 2; // 消费者耗时（秒）

// 生产者函数
void* producer(void* arg) {
    int id = *(int*)arg;
    while (!stopRequested && productsProduced < MAX_PRODUCTS) {
        // 检查缓冲区是否已满
        int cur_buffer_size;
        sem_getvalue(&empty, &cur_buffer_size);
        if (cur_buffer_size <= 0) {
            std::cout << "++++! Buffer is full, Producer is waiting..." << std::endl;
        }
        // 阻塞等待缓冲区有空间
        // 尝试减少空间数量，如果空间数量小于0，则阻塞
        sem_wait(&empty);
        sem_wait(&mutex);
        if(stopRequested) break;
        if (productsProduced < MAX_PRODUCTS) { // 在锁内部检查
            int product = productsProduced.fetch_add(1) + 1;
            buffer.push_back(product);
            std::cout << "----! Producer " << id << " produced: " << product << std::endl << std::endl;
        }
        sem_post(&mutex);
        sem_post(&product);
        sleep(PRODUCER_SLEEP_TIME);  // 生产者耗时
        // if (productsProduced >= MAX_PRODUCTS) {
        //     // 如果所有产品都已生产，则释放所有阻塞的生产者
        //     // for (int i = 0; i < NUM_PRODUCERS - 1; ++i) {
        //     //     sem_post(&empty);
        //     // }
        //     break;
        // }
    }
    // std::cout << "----! Producer " << id << " finished produce all products." << std::endl << std::endl;
    return nullptr;
    
}

// 消费者函数
void* consumer(void* arg) {
    int id = *(int*)arg;
    while (!stopRequested && productsConsumed < MAX_PRODUCTS) {
        // 检查缓冲区是否为空
        int cur_buffer_size;
        sem_getvalue(&empty, &cur_buffer_size);
        if(cur_buffer_size >= BUFFER_SIZE) {
            std::cout << "++++! Buffer is empty, Consumer is waiting...\n" << std::endl;
        }
        sem_wait(&product);
        sem_wait(&mutex);
        if (stopRequested) break;
        if (!buffer.empty()) {
            std::cout << "####! Before consumption, buffer contents: ";
            for (const auto& product : buffer) {
                std::cout << product << " ";
            }
            std::cout << std::endl;

            int product = buffer.back();
            buffer.pop_back();
            productsConsumed.fetch_add(1);
            std::cout << "====! Consumer " << id << " consumed: " << product << std::endl;

            std::cout << "####! After consumption, buffer contents: ";
            for (const auto& product : buffer) {
                std::cout << product << " ";
            }
            std::cout << std::endl << std::endl;
        }
        sem_post(&mutex);
        sem_post(&empty);
        sleep(CONSUMER_SLEEP_TIME); // 消费者耗时
        // if (productsConsumed >= MAX_PRODUCTS) {
        //     // 如果所有产品都已消费，则释放所有阻塞的消费者
        //     // for (int i = 0; i < NUM_CONSUMERS - 1; ++i) {
        //     //     sem_post(&product);
        //     // }
        //     break;
        // }
    }
    // std::cout << "====! Consumer " << id << " finished consuming all products." << std::endl << std::endl;    
    return nullptr;
}

// 监听器函数
void* stopListener(void*) {
    std::cin.get();
    stopRequested = true;
    // 中断可能因等待资源而阻塞的生产者和消费者
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        sem_post(&product);
        sem_post(&empty);
    }
    return nullptr;
}

int main() {
    sem_init(&product, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&mutex, 0, 1);

    // 打印生产者、消费者数量和耗时
    std::cout << "生产者数量: " << NUM_PRODUCERS << ", 消费者数量: " << NUM_CONSUMERS << std::endl;
    std::cout << "生产者耗时: " << PRODUCER_SLEEP_TIME << "秒, 消费者耗时: " << CONSUMER_SLEEP_TIME << "秒" << std::endl;

    pthread_t producers[NUM_PRODUCERS], consumers[NUM_CONSUMERS], stopThread;
    int ids[NUM_PRODUCERS + NUM_CONSUMERS];

    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        ids[i] = i + 1;
        pthread_create(&producers[i], nullptr, producer, &ids[i]);
    }
    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        ids[NUM_PRODUCERS + i] = i + 1;
        pthread_create(&consumers[i], nullptr, consumer, &ids[i]);
    }
    pthread_create(&stopThread, nullptr, stopListener, nullptr);
    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        pthread_join(producers[i], nullptr);
    }
    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        pthread_join(consumers[i], nullptr);
    }
    pthread_join(stopThread, nullptr);

    sem_destroy(&product);
    sem_destroy(&empty);
    sem_destroy(&mutex);

    return 0;
}

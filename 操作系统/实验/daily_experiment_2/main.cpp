#include <iostream>
#include <vector>
#include <thread> // 提供了std::thread类，允许创建和管理线程
#include <mutex> // 提供了多种互斥锁类型

// 定义全局变量
int sharedData = 711;
const int threadNum = 10;

// 互斥锁，用于线程间的同步
std::mutex mtx;

// 线程函数，修改并输出全局变量
void modifyAndPrint(int id) {
    // 加锁以防止数据竞争
    mtx.lock();
    // 修改全局变量
    sharedData += 11;
    // 输出全局变量和线程ID
    std::cout << "Thread " << id << " modified sharedData to " << sharedData << std::endl;
    // 解锁
    mtx.unlock();
}

int main() {

    std::cout << "Initial sharedData: " << sharedData << std::endl << std::endl;

    std::vector<std::thread> threads;
    // 创建多个线程
    for (int i = 0; i < threadNum; ++i) {
        std::cout << "Creating thread " << i + 1 << std::endl;
        threads.emplace_back(modifyAndPrint, i + 1);
    }
    std::cout << std::endl;
    // 等待所有线程完成
    for (int i = 0; i < threadNum; ++i) {
        std::thread &t = threads[i];
        // join()函数会阻塞主线程，直到当前遍历线程执行完成
        // 这里的意思就是防止main函数里的主线程先于子线程结束
        std::cout << "Waiting for thread " << i << " ---- " << t.get_id() << " to complete" << std::endl;
        t.join();
    }

    return 0;
}

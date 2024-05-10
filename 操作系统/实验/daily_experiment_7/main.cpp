#include <iostream>
#include <sys/shm.h> // 共享内存
#include <sys/stat.h> // 文件状态信息访问
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

// 定义共享内存的大小
const int SHARED_MEMORY_CHUNK_SIZE = 1024;

// 定义一个结构体来存放共享数据
struct SharedData {
    char text[SHARED_MEMORY_CHUNK_SIZE]; // 存放文本数据
};

// 共享内存的键值, 用以唯一标识共享内存
const key_t SHM_KEY = 0x1234;

// 写者函数
void writer() {
    // 创建共享内存， 后四个参数是权限设置
    int shm_id = shmget(SHM_KEY, sizeof(SharedData), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

    // 错误检查
    if (shm_id < 0) {
        perror(" shared memory creation failed\n");
        exit(1);
    }

    // 将共享内存映射到虚拟地址空间, 0 表示不进行任何特殊操作
    void* shm_ptr = shmat(shm_id, nullptr, 0);
    if (shm_ptr == (void*)-1) {
        // 映射失败
        perror("shared memory attach failed\n");
        exit(1);
    }

    // 获取指向共享数据的指针
    // static_cast 是 C++ 中的一种类型转换运算符，用于在类层次结构中进行显式类型转换，可以将一个类型转换为它的基类或派生类类型
    SharedData* shared_data = static_cast<SharedData*>(shm_ptr);

    // 写入数据
    strcpy(shared_data->text, "==========! Hello, this is a message from the Parent Writer process! ======");

    // 将映射的共享内存从当前进程的地址空间中分离
    shmdt(shm_ptr);
    // 此时，写者进程已经完成数据写入，但共享内存仍存在，可供其他进程访问
}

// 读者函数
void reader() {
    // 打开共享内存
    int shm_id = shmget(SHM_KEY, sizeof(SharedData), 0);

    // 错误检查
    if (shm_id < 0) {
        perror("shared memory open failed\n");
        exit(1);
    }

    // 将共享内存映射到虚拟地址空间
    void* shm_ptr = shmat(shm_id, nullptr, 0);
    if (shm_ptr == (void*)-1) {
        perror("shared memory attach failed\n");
        exit(1);
    }

    // 获取指向共享数据的指针
    SharedData* shared_data = static_cast<SharedData*>(shm_ptr);

    // 读取数据
    std::cout << "Reader process reads: " << shared_data->text << std::endl;

    // 分离共享内存
    shmdt(shm_ptr);

    // 删除共享内存
    shmctl(shm_id, IPC_RMID, nullptr);
}

// 主函数
int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // 创建进程失败
        perror("create process failed\n");
        return 1;
    } else if (pid == 0) {
        // 子进程
        sleep(1); // 确保写者先运行
        reader();
    } else {
        // 父进程
        writer();
        // 等待子进程结束
        wait(nullptr);
    }

    return 0;
}

#include <iostream>
#include <sys/stat.h> // 文件状态信息访问
#include <sys/types.h> 
#include <fcntl.h> // 文件控制选项
#include <unistd.h> 
#include <cstring>
#include <cstdlib>
#include <sys/wait.h> // 进程等待

int main() {
    const char* fifoPath = "/tmp/myfifo"; // 进程间通信管道文件
    const char* message = "----- Hello, this is a message from child! -----";
    char readbuffer[100];
    int fd; // 存放打开FIFO文件时返回的文件描述符

    // 创建命名管道
    // 0666:权限模式，所有用户都有读写权限
    if (mkfifo(fifoPath, 0666) == -1) {
        perror("create fifo error");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("create child process error");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // 子进程: 向 FIFO 写数据
        // O_WRONLY: 只写方式打开
        fd = open(fifoPath, O_WRONLY);
        if (fd == -1) {
            perror("open fifo error");
            exit(EXIT_FAILURE);
        }
        write(fd, message, strlen(message) + 1); // 写入
        close(fd);
        exit(EXIT_SUCCESS);
    } else {
        // 父进程: 从 FIFO 读数据
        // O_RDONLY: 只读方式打开
        fd = open(fifoPath, O_RDONLY);
        if (fd == -1) {
            perror("open fifo error");
            exit(EXIT_FAILURE);
        }
        read(fd, readbuffer, sizeof(readbuffer)); // 读取
        std::cout << "Parent received: " << readbuffer << std::endl;
        close(fd);

        // 等待子进程结束
        wait(NULL);

        // 删除 FIFO 文件
        unlink(fifoPath);
    }

    return 0;
}

#include <iostream> 
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <cstdlib> // 动态内存分配、进程控制

int main() {
    // 创建管道，pipefd[0] 为读端，pipefd[1] 为写端
    int pipefd[2];
    pid_t pid;

    // 创建管道
    if (pipe(pipefd) == -1) {
        std::cerr << "Failed to create pipe\n";
        return 1;
    }

    // 创建子进程并执行 Child 程序
    pid = fork();
    if (pid == -1) {
        std::cerr << "Failed to fork\n";
        return 1;
    }

    if (pid == 0) {
        // 子进程
        close(pipefd[1]); // 关闭写端
        dup2(pipefd[0], STDIN_FILENO); // 将标准输入重定向到管道读端
        close(pipefd[0]); // 不再需要额外的管道文件描述符
        // 执行 Child 程序
        execl("./Child", "Child", (char*)NULL);
        std::cerr << "Failed to exec Child\n";
        exit(1);
    } else {
        // 父进程
        const char* msg = "------- Hello, this message from Parent! ------- ";
        close(pipefd[0]); // 关闭读端
        write(pipefd[1], msg, strlen(msg)); // 向管道写数据
        close(pipefd[1]); // 关闭写端

        wait(NULL); // 等待子进程结束
    }

    return 0;
}

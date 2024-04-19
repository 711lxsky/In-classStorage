#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <cstdlib>

int main() {
    int pipefd1[2];  // 父写子读
    int pipefd2[2];  // 子写父读
    pid_t pid;

    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) {
        std::cerr << "Failed to create pipes\n";
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        std::cerr << "Failed to create Child\n";
        return 1;
    }

    if (pid == 0) {
        // 子进程
        close(pipefd1[1]); // 关闭父写子读管道的写端
        close(pipefd2[0]); // 关闭子写父读管道的读端

        // 执行子进程程序
        dup2(pipefd1[0], STDIN_FILENO);
        dup2(pipefd2[1], STDOUT_FILENO);
        execl("./Child", "Child", (char*)NULL);

        std::cerr << "Failed to exec Child program\n";
        exit(1);
    } else {
        // 父进程
        close(pipefd1[0]); // 关闭父写子读管道的读端
        close(pipefd2[1]); // 关闭子写父读管道的写端

        std::ofstream record("record2");

        const char* msg = "Message from Parent to Child";
        write(pipefd1[1], msg, strlen(msg) + 1); // 向子进程写数据

        char buf[1024] = {0};
        read(pipefd2[0], buf, sizeof(buf)); // 从子进程读取数据
        record << "Parent received: " << buf << std::endl;

        close(pipefd1[1]); // 关闭写端
        close(pipefd2[0]); // 关闭读端
        record.close(); // 关闭文件

        wait(NULL); // 等待子进程结束
    }

    return 0;
}

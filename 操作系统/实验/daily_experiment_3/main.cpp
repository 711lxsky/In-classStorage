/* 
    当前程序命令行运行编译后文件，在vscode中直接运行被拦截，
    有异常User defined signal 1
*/

#include <iostream>
#include <signal.h> // 信号处理
#include <unistd.h> // POSIX操作系统(UNIX)API
#include <sys/wait.h> // 进程控制

// 信号处理函数
void signal_handler(int sig) {
    std::cout << "Received signal: " << sig << " in process " << getpid() << std::endl << std::endl;
}

int main() {
    // 设置信号处理函数
    signal(SIGUSR2, signal_handler);

    pid_t pid1 = fork(); // 创建第一个子进程
    if (pid1 == 0) {
        // 第一个子进程代码
        std::cout << "---- Child 1 process started, PID: " << getpid() << std::endl << std::endl;
        // 这里也会设置信号处理函数，为兄弟进程通信做准备
        signal(SIGUSR1, signal_handler);
        sleep(2); // 等待确保父进程设置好信号处理函数
        std::cout << "---- Child 1 process sending signal to parent process" << std::endl << std::endl;
        kill(getppid(), SIGUSR2); // 父子通信
        exit(0);
    } else {
        pid_t pid2 = fork(); // 创建第二个子进程
        if (pid2 == 0) {
            // 第二个子进程代码
            std::cout << "==== Child 2 process started, PID: " << getpid() << std::endl << std::endl;
            sleep(1); // 确保第一个子进程已经设置好信号处理函数
            std::cout << "==== Child 2 process sending signal to Chiled 1 process" << std::endl << std::endl; // 兄弟通信
            kill(pid1, SIGUSR1); // 兄弟
            sleep(3); // 延时，确保第一个子进程已经向父进程发送了信号
            std::cout << "==== Child 2 process sending signal to parent process" << std::endl << std::endl;
            kill(getppid(), SIGUSR2); // 父子通信
            exit(0);
        } else {
            // 父进程代码
            std::cout << "#### Parent process, PID: " << getpid() << std::endl << std::endl;
            wait(NULL); // 等待一个子进程结束
            wait(NULL); // 等待另一个子进程结束
        }
    }

    return 0;
}

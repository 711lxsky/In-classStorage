#include <iostream>
#include <unistd.h> // 包含POSIX操作系统API
#include <sys/wait.h> // 包含进程控制相关的API
#include <fstream>
#include <string>

const std::string fileReadName = "data";

int main() {
    // 创建子进程, 返回子进程pid
    // 注意，这里fork()在父进程中得到的是子进程pid(随机)， 而在子进程中执行时返回的是0,
    // 在子进程中，fork()返回0作为一种约定，表示当前进程是新创建的子进程。
    pid_t subProcessId = fork(); 
    std::cout << "==== currently, Child Process pid : " << subProcessId << " ====" << std::endl;
    if (subProcessId == -1) {
        // 创建子进程失败
        std::cerr << "~~~~ Failed to create process ~~~~" << std::endl;
        return 1;
    } else if (subProcessId == 0) {
        // 子进程执行
        std::cout << "~~~~ Child Process: start reading the file. ~~~~\n" << std::endl;
        std::ifstream file(fileReadName);
        if (!file.is_open()) {
            std::cerr << "~~~~ Failed to open the file! ~~~~" << std::endl;
            return 2;
        }
        
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
        
        std::cout << "\n~~~~ Child Process: file reading complete. ~~~~" << std::endl;
        return 0;
    } else {
        // 父进程执行的代码
        std::cout << "==== Parent Process: waiting for child process to complete. ====\n" << std::endl;
        int status;
        // 等待子进程结束, 参数0表示阻塞等待
        // 再到main()中重头执行，所以整个代码会被执行两次，只是进不同条件语句
        waitpid(subProcessId, &status, 0); 
        std::cout << "\n==== Parent Process: child process completed. ====" << std::endl;
    }
    
    return 0;
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>

int main() {
    // 创建命名管道
    const char* fifo_name = "/tmp/myfifo";
    mkfifo(fifo_name, 0666);

    pid_t pid = fork(); // 创建子进程
    if (pid < 0) {
        std::cerr << "Fork failed" << std::endl;
        return 1;
    }

    if (pid == 0) { // 子进程
        // 打开命名管道用于写入
        int fd = open(fifo_name, O_WRONLY);
        if (fd < 0) {
            std::cerr << "Child: Open failed" << std::endl;
            return 1;
        }

        // 从用户获取输入并写入命名管道
        std::string message;
        bool flag = true;
        while (true) {
            if(flag){
                std::cout << "\nChild: Enter message to send (type 'end' to quit): ";
                flag = false;
            }
            std::getline(std::cin, message);
            if (message == "end") {
                break; // 用户输入 "end" 时退出循环
            }
            // 写入数据到命名管道
            write(fd, message.c_str(), message.length() + 1); // +1 是为了写入字符串结束符 '\0'
        }

        // 关闭文件描述符
        close(fd);
    } else { // 父进程
        // 打开命名管道用于读取
        int fd = open(fifo_name, O_RDONLY);
        if (fd < 0) {
            std::cerr << "Parent: Open failed" << std::endl;
            return 1;
        }

        // 循环读取数据
        char buffer[256];
        while (true) {
            std::cout << "Parent: Waiting for data..." << std::endl;
            ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0'; // 确保字符串以 null 结尾
                std::cout << "Parent: Received message: " << buffer << std::endl << std::endl;
            } else if (bytes_read == 0) {
                std::cout << "Parent: End of file reached, exiting." << std::endl;
                break; // EOF reached, exit the loop
            } else {
                std::cerr << "Read failed" << std::endl;
                break; // Read error, exit the loop
            }
        }

        // 关闭文件描述符并删除命名管道
        close(fd);
        unlink(fifo_name);
    }

    return 0;
}

#include <iostream>
#include <unistd.h> // POSIX操作系统(UNIX)API
#include <cstdio>

int main() {
    char buf[1024];

    // 从标准输入读取数据
    // STDIN_FILENO是标准输入文件描述符
    ssize_t num_read = read(STDIN_FILENO, buf, sizeof(buf));
    if (num_read == -1) {
        std::cerr << "Failed to read from stdin\n";
        return 1;
    }

    std::cout << "Child received: " << buf << std::endl;
    return 0;
}

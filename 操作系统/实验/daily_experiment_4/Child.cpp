#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>

int main() {
    char buf[1024];

    // 从标准输入读取数据
    read(STDIN_FILENO, buf, sizeof(buf));

    std::ofstream record("record1", std::ios::app); // Append mode

    record << "Child received: " << buf << std::endl;

    const char* msg = "Message from Child to Parent";
    write(STDOUT_FILENO, msg, strlen(msg) + 1); // 向标准输出写数据

    record.close();

    return 0;
}

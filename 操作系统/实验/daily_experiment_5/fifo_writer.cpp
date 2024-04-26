#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 打开命名管道用于写入
    const char* fifo_name = "/tmp/myfifo";
    // 只写方式打开
    int fd = open(fifo_name, O_WRONLY);
    if (fd < 0) {
        cerr << "Open failed" << endl;
        return 1;
    }

    // 从用户获取输入并写入命名管道
    string message;
    while (true) {
        cout << "Enter message to send (type 'end' to quit): ";
        getline(cin, message);
        if (message == "end") {
            break; // 用户输入 "end" 时退出循环
        }
        // 写入数据到命名管道
        write(fd, message.c_str(), message.length() + 1); // +1 是为了写入字符串结束符 '\0'
    }

    // 关闭文件描述符并删除命名管道
    close(fd);

    return 0;
}

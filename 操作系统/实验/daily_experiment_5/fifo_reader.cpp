#include <sys/types.h>
#include <sys/stat.h> // 文件状态
#include <fcntl.h> // 文件描述符
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
    // 创建命名管道
    const char* fifo_name = "/tmp/myfifo";
    // 0666, 所有用户具有读写权限
    mkfifo(fifo_name, 0666);

    // 打开命名管道用于读取
    int fd = open(fifo_name, O_RDONLY);
    if (fd < 0) {
        cerr << "Open failed" << endl;
        return 1;
    }

    // 循环读取数据
    char buffer[256];
    while (true) {
        cout << "\nParent: Waiting for data..." << endl;
        ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0'; // 确保字符串以 null 结尾
            cout << "Parent: Received message: " << buffer << endl;
        } else {
            cerr << "Read failed" << endl;
            break;
        }
    }

    // 关闭文件描述符并删除命名管道
    close(fd);
    unlink(fifo_name);

    return 0;
}

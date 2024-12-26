#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdint> // For uint64_t
#include <cstdlib> // For atoi
using namespace std;

int main() {
    int fd = open("/dev/edu", O_RDONLY);
    if (fd == -1) {
        cerr << "Cannot open /dev/edu" << endl;
        return -1;
    }

    string input;
    uint64_t result;

    while (true) {
        cout << "Enter a number to calculate its factorial (or 'q' to quit): ";
        cin >> input;
        if (input == "q") {
            cout << "Exiting program." << endl;
            break;
        }

        int value = atoi(input.c_str()); // 将输入转换为整数
        if (value < 0) {
            cout << "Please enter a positive number or 'q' to quit." << endl;
            continue;
        }

        cout << "ioctl write: " << value << endl;
        int ret = ioctl(fd, 0, value);
        sleep(1); // 等待计算完成

        // 获取计算结果
        ret = ioctl(fd, 1, &result);
        if (ret == 0) {
            cout << "Factorial result: " << result << endl;
        } else {
            cerr << "Failed to read result" << endl;
        }
    }

    close(fd);
}

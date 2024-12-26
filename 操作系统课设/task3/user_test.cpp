#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdint> // For uint64_t
using namespace std;

int main() {
    int fd = open("/dev/edu", O_RDONLY);
    if (fd == -1) {
        cerr << "Cannot open /dev/edu" << endl;
        return -1;
    }

    uint64_t result;

    for (int value = 1; value <= 10; ++value) {
        cout << "Calculating factorial of " << value << endl;

        cout << "ioctl write: " << value << endl;
        int ret = ioctl(fd, 0, value);
        sleep(1); // 等待计算完成

        // 获取计算结果
        ret = ioctl(fd, 1, &result);
        if (ret == 0) {
            cout << "Factorial result: " << result << endl;
        } else {
            cerr << "Failed to read result for " << value << endl;
        }
    }

    close(fd);
    return 0;
}
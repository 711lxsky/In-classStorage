#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h> // For uint64_t

int main() {
    int fd = open("/dev/edu", O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannot open /dev/edu\n");
        return -1;
    }

    char input[100];
    uint64_t result;

    while (1) {
        printf("Enter a number to calculate its factorial (or 'q' to quit): ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "q") == 0) {
            printf("Exiting program.\n");
            break;
        }

        int value = atoi(input); // 将输入转换为整数
        if (value < 0) {
            printf("Please enter a positive number or 'q' to quit.\n");
            continue;
        }

        printf("ioctl write: %d\n", value);
        int ret = ioctl(fd, 0, value);
        sleep(1); // 等待计算完成

        // 获取计算结果
        ret = ioctl(fd, 1, &result);
        if (ret == 0) {
            printf("Factorial result: %llu\n", result);
        } else {
            fprintf(stderr, "Failed to read result\n");
        }
    }

    close(fd);
    return 0;
}
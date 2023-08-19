#include <stdio.h>

int main(void) {
    int num, i = 2 ;
    scanf("%d", &num);
    while (num != 1) {

        if (num % i == 0) {
            num /= i;
            printf("%d", i);

            if (num != 1) {
                putchar('*');
            }

        }

        else {
            i++;
        }
    }
    return 0;
}
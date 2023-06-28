#include <stdio.h>

int main(void) {
    int m, n, yue, bei, max, min, i, j, rep;
    scanf("%d %d", &m, &n);
    if (m > n) {
        max = m;
        min = n;
    }
    else {
        max = n;
        min = m;
    }
    for (i = 1; i <= min; i++) {
        if (max % i == 0 && min % i == 0) {
            yue = i;
        }
    }
   // printf("%d", yue);
    for (j = max * min; j >= max; j -= min) {
        if (j % min == 0 && j % max == 0) {
            bei = j;
        }
    }
    //bei = j;
    printf("%d %d", yue, bei);
    return 0;
}
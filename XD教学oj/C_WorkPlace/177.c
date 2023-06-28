#include <stdio.h>

int main(void)
{
    int res;
   unsigned char ch, i = 0, n, sum = 0;
   unsigned char mys[101] = { '0' };
    gets(mys);// 注意此处不能用scanf，否则无法读取空格' ' 
    for (i = 0; i <= 100; i++) {
        sum += mys[i];
    }
    res = (int)sum;
    printf("%d", res);
    return 0;
}
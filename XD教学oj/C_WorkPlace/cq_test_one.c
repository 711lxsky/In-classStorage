#include <stdio.h>

int main(void)
{
    float num = 10.234 ;
    for(int i = 0 ; i < 11; i++){
        printf("%6.2f\n" , num * i * 2 ) ;
    }

    return 0 ;
}
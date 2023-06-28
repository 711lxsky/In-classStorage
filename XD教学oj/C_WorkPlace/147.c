#include <stdio.h>

int main ( void )
{
    int num = 1 , sum = 0;
    while ( num != 0){
        scanf ("%d" , &num) ;
        if ( num % 2 != 0){
            sum += num ;
        }
    }

    printf("%d", sum) ;

    return 0;
}
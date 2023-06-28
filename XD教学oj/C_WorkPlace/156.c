#include <stdio.h>

int main ( void )
{
    int i , num ,sum = 0;

    for ( i = 100 ; i <500 ; i ++){
        num = i ;
        if ( (num % 7 == 0 || num % 11 == 0 ) && num % 77 != 0){
            sum ++ ;
        }
    }
    printf("%d" ,sum) ;

    return 0;
}
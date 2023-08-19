#include <stdio.h>

int main ( void )
{
    int num1[12] = { 0 } , num2[11] = { 0} ;
    for ( int i = 0 ; i < 10 ; i ++){
        scanf("%d" , &num1[i]) ;
    }
    for ( int i = 1 ; i < 10 ; i ++){
        num2[i-1] = num1[i] / num1[i-1] ;
        printf("%d " , num2[i-1]) ;
    }

    return 0 ;
}
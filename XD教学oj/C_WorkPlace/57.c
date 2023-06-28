#include <stdio.h>

int fib ( int n) ;

int main ( void )
{
    int n ;
    scanf("%d" , &n) ;
    printf("%d" , fib(n)) ;

    return 0 ;
}

int fib ( int n)
{
    int  i , j , num3 ,num1 = 7 , num2 = 11 ;
    if ( n == 0){
        num3 = num1 ;
    }
    else if ( n == 1) num3 = num2 ;
    else {
    for ( i = 2 ; i <= n ; i ++){
        num3 = num1  + num2;
        num1= num2 ;
        num2 = num3 ;
    }
    }
    return num3 ;
}
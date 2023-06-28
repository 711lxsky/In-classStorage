#include <stdio.h>

int Isprime ( int x) ;

int main ( void )
{
    int n , i , j ,num3 ,num1 = 1 , num2 = 0 ;
    scanf("%d" , &n) ;
    for ( i = 1 ; i <= n ; i ++){
        num3 = num1  + num2;
        num1= num2 ;
        num2 = num3 ;
    }
    if ( Isprime(num3)){
        printf("yes") ;
    }
    else {
        printf("%d" , num3) ;
    }
    return 0 ;
}

int Isprime(int x)
{
    int i , res = 1 ;
    for ( i = 2 ; i <= x/2 ; i ++){
        if ( x % i == 0){
            res = 0 ;
        }
    }

    return res ;
}
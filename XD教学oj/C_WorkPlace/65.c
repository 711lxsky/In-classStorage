#include <stdio.h>

int main ( void )
{
    int n , i , num , rep , res ;
    scanf("%d" , &n) ;
    num = n ;
    while ( num >= 10){
        rep = 0 ;
        while ( num != 0){
            rep += num % 10 ;
            num /= 10 ;
        }
        num = rep ;
    }
    printf("%d" , num) ;

    return 0 ;
} 
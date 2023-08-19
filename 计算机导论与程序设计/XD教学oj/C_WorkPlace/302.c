#include <stdio.h>

int main ( void )
{
    int n , num  = 0, x = 1, sum  = 0, i , j ;
    scanf("%d" , &n) ;
    for ( i = 2 ; x <= n + 10 ; i ++){
        num = 0 ;
        for ( j = 2 ; j < i ; j ++){
            if ( i % j == 0 ){
                num ++ ;
            }
        }
        if ( num == 0 ){
            x ++ ;  
        if ( x > n ){
            sum += i ;
        }
    }
    }
    printf("%d" , sum) ;
    return 0;
}
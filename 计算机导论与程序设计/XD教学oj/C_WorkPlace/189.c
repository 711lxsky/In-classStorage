#include <stdio.h>

int main ( void )
{
    int n , i  ;
    double s = 0 , h = 100 , res ;
    scanf("%d" , &n) ;
    s += h ;
    for ( i = 1 ; i <= n ; i ++){
        h /= 2 ;
        s += h * 2 ;
    }
    s -= h * 2 ;
    printf("S=%.3lf h=%.3lf" , s , h) ;

    return 0 ;
}
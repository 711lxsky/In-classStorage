#include <stdio.h>

int main ( void )
{
    int m , n , i , j ;
    double res , res_m = 1, res_n = 1 , res_mn = 1 ;
    scanf("%d %d" , &m , &n) ;
    for ( i = 1 ; i <= m ; i ++){
          res_m *= i ;
    }
    for ( i = 1 ; i <= n ; i ++ ){
        res_n *= i ;
    }
    for ( i = 1 ; i <= m - n ; i ++){
        res_mn *= i ;
    }
    res = res_m / res_n / res_mn ;

    printf("%.2f" , res) ;

    return 0 ;
}
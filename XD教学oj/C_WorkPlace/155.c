#include <stdio.h>

int main ( void )
{
    int n , res_n = 1 ,res_num = 1 , sum = 0 , i , j ;
    scanf("%d" ,&n) ;
    for ( i = 1 ; i <= n ; i ++){
          res_n *= i ; 
    }
    for ( i =1; i <= n; i ++){
        res_num = 1 ;
        for( j =1 ; j <= i ; j ++){
           res_num *= j ;
        }
        sum += res_num ;
    }
    printf("%d %d %d" , n , res_n , sum) ;
}
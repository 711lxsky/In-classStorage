#include <stdio.h>

int main (void){
    int m , n , i , num_m = 0 , num_n = 0 ,sum_m  = 0, sum_n = 0 ;
    scanf("%d %d" , &m , &n) ;
    for( i = 1 ; i < m ; i ++){
        if ( m % i == 0){
            sum_m += i ;
            num_m ++ ;
        }
    }
    for ( i = 1 ; i < n ; i ++){
        if ( n % i == 0){
            sum_n += i ;
            num_n ++ ;
        }
    }
    if (  sum_m == n && sum_n == m){
        printf("yes %d %d" , num_m , num_n) ;
    }
    else {
        printf("no %d %d" , num_m , num_n) ;
    }

    return 0;
}
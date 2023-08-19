#include <stdio.h>
#include <math.h>

int main ( void )
{
    int num[1001] = {1000000} ;
    int i , j , rep , min1 = 1000000 , min2 = 1000000 , x , num1  , num2 , n ;
    scanf("%d" ,&n) ;
    for ( i=0 ; i <= n - 1 ; i ++){
        scanf("%d" , &num[i]) ;
    }
    for ( i = 0 ; i <= n -1 ; i ++){
         for ( j = i + 1 ; j <= n-1 ; j ++){
            rep = abs ( num[j] - num[i]);
            if ( min1 >= rep ){
                min1 = rep ;
            }
         }
    }
    printf("%d" , min1) ;
   
    return 0;
    
}
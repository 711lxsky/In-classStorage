#include <stdio.h>

int main ( void )
{
    int a ,b , num , i ,n ,j,sum = 0 ;

    scanf("%d %d" , &a ,&b ) ;

    for ( i = a ; i <= b ; i ++ ) {
       num = i ;
       sum = 0 ;

       for ( j = 1 ; j < num ; j ++){

        if ( num % j == 0){
            sum += j ;
        }
        
       }

       if ( num == sum){
        printf("%d\n" ,num) ;
       }
    }
       return 0;
}
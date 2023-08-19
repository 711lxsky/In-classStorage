#include <stdio.h>

int main ( void )
{
    int n , num1 , num2 , i , sum = 1 ;
    scanf("%d" , &n) ;
    scanf("%d" , &num1) ;
    for ( i = 2 ; i <= n ; i ++){
        scanf("%d" , &num2) ;
        if ( num1 != num2){
            sum ++ ;
        }
        num1 = num2 ;
    }

    printf("%d" ,sum) ;

    return 0;
}
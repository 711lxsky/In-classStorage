#include <stdio.h>

double function ( int n) ;
int main ( void )
{
    double res = 0 ;
    int i , n ;
    scanf("%d" ,&n) ;
    res = function(n) ;
    printf("%.6lf" , res ) ;

}

double function ( int n)
{
    double res  , num1 = 0, num2 = 0;
    int i  ;
    for ( i = 1 ;i <= n ; i++){
        num1 += 1 ;
        num2 = 1 / num1 ;
        num1 = num2 ;
    }
    res = num2 ;
    return res ;
}
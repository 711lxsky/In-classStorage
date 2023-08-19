#include <stdio.h>

int fib( int x ) ;
int main ( void )
{
   int n ;
   scanf("%d" , &n) ;
   int num1 = 1 , num2 = 1 ;
   for ( int i = 1 ; i <= n ; i ++){
    printf("%d " , num1) ;
    int rep = num2 ;
    num2 += num1 ;
    num1 = rep ;
   }

   return 0 ;

}
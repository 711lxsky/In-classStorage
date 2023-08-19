#include <stdio.h>
#include <math.h>

int Isprime(int x) ;

int main ( void )
{
      int n , num1 , num2 ;
      scanf("%d" , &n) ;
      for ( int i = 2 ; i <= n / 2 ; i ++){
           num1 = i ;
           num2 = n - num1 ;
           if ( Isprime(num1) && Isprime(num2)){
            break ;
           } 
      }
      printf("%d %d" , num1 , num2) ;
      return 0;   
}

int Isprime(int x)
{
    int i , res = 1 ;
    for ( i = 2 ; i <= x/2 ; i ++){
        if ( x % i == 0){
            res = 0 ;
        }
    }

    return res ;
}
#include <stdio.h>
#include <math.h>

int Isprime(int x) ;
int main ( void )
{
    int a , b , i , j ,sum = 0  , num = 0 , rep ;
    scanf("%d %d" , &a , &b) ;
    if ( a >= b){
        rep = b ;
        b = a ;
        a = rep ;
    }

    for ( i = 2 ; num < b ; i ++){
          rep = i ;

          if ( Isprime(rep)){
            num ++;
           // printf("%d " , rep) ;

          if ( num >= a){
            sum += rep ;
           // printf("%d\n " ,sum) ;
          }
          }
    }
       printf("%d" ,sum) ;
    return 0 ;
}

int Isprime ( int x){

    int sum =  1 ;

    for ( int i = 2 ; i <= x/2 ; i ++){
        if ( x % i == 0 ) {
            sum = 0 ;
            break ;
        }
    }
    return sum ;
}
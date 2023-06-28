#include <stdio.h>

void fun ( int x) ;
int Isprime ( int num) ;

int main ( void )
{
   int x , i ;
   scanf("%d" , &x) ;
   fun(x) ;
   return 0 ;
}

void fun ( int x)
{
    int mys[1000] = { 0 } ;
    int i  ,sum = 0 ;
    for ( i = 2 ; i <= x ; i ++){
        if (Isprime(i)){
            mys[sum] = i ;
            sum ++ ;
        }
    }
    printf("%d\n" , sum) ;
    for ( i = 0 ; i < sum  ; i ++){
        printf("%d " , mys[i]) ;
    }
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
#include <stdio.h>

int Isprime ( int x) ;
int main ( void )
{
    int n ;
    scanf("%d" , &n) ;
    if ( Isprime(n)) printf("YES") ;
    else printf("NO") ;

    return 0 ;
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
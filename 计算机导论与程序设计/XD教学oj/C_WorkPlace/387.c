#include <stdio.h>

int main ( void )
{
    int a, b ,res ;
    scanf("%d %d" , &a , &b) ;
    if ( a > b){
        int rep = a ;
        a = b ;
        b = rep ;
    }
    int i = a ;
    while ( i % a != 0 || i % b != 0){
        i += a ;
    }
    res = i ;
    printf("%d" , res) ;

    return 0 ;
}
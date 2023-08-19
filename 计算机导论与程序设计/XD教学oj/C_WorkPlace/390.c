#include <stdio.h>

int fact ( int n) ;

int main ( void )
{
    int num ;
    scanf("%d" , &num) ;
    //int res = fact(num) ;


    for ( int j = 1 ; j <= num ; j ++){
        int res = fact(j) ;
        printf("%d " , res) ;

    }
    //printf("%d " , res) ;

    return 0 ;
}

int fact ( int x) {
    int rep = 1;
    for ( int i = 1 ; i <= x ; i ++){
           rep *= i ;
    }

    return rep ;
}
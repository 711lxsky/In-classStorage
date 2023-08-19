#include <stdio.h>

int main ( void )
{
    int num[22][22] = { 0 } ;
    int n , sum = 0  ;
    scanf("%d" , &n) ;
    int lab = n - 1 ;
    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < n ; j ++){
            scanf("%d" , &num[i][j]) ;
            if ( i + j == lab || i == j ) {
                sum += num[i][j] ;
            }
        }
    }
    /*if ( n % 2 != 0) {
        int jud = (n - 1) / 2 ;
        sum -= num[jud][jud] ;
    }*/
    printf("%d" , sum) ;
    return 0 ;
}
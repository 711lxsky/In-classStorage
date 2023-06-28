#include <stdio.h>

int main (void)
{
    int light[101] = {0} ;
    int n , m ;
    scanf("%d %d" , &n , &m) ;
    for ( int i = 1 ; i <= m ; i ++){
        for ( int j = 1 ; j <= n ; j ++)
        if ( 0 == j % i ) {
            if (0 == light[j] ) light[j] = 1 ;
            else light[j] = 0 ;
        }
    }
    for ( int i = 1 ; i <= n ; i ++){
        if (1 == light[i]) printf("%d " , i) ;
    }
}
#include <stdio.h>

int main ( void )
{
    int tri[12][12] = {0} ;
    int n ; 
    scanf("%d" ,&n) ;
    for ( int i = 0 ; i < n ; i ++){
        tri[i][0] = 1 ;
        tri[i][i] = 1 ;
    }
    for ( int i = 2 ; i < n ; i ++){
        for (int j = 1 ; j < i ; j ++){
            tri[i][j] = tri[i-1][j-1] + tri[i-1][j] ;
        }
    }

    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j <= i ; j ++){
            printf("%d " ,tri[i][j]) ;
        }
        printf("\n") ;
    }

    return 0 ;
}
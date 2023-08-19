#include <stdio.h>

int main ( void )
{
    int num[1003] = { -1 } ;
    int n , des ;
    scanf("%d" , &n) ;
    for ( int i = 0 ;i < n ; i ++){
        scanf("%d" , &num[i]) ;
    }
    int lab ;
    int jud = -1 ;
    for ( int i = 0 ; i < n ; i ++){
        int big = 0 ;
        int sma = 0 ;
        for ( int j = 0 ; j < n ; j ++){
            if ( num[i] > num[j]) big ++ ;
            else if ( num[i] < num[j]) sma ++ ; 
        }
        if ( big == sma) {lab = i ;
        jud = 0 ; 
    }
    }
    if ( jud == 0) printf("%d" , num[lab]) ;
    else printf("-1") ;
    return 0 ;
}
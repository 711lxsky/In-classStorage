#include <stdio.h>

int main ( void )
{
    int num[102] = { -1000000 } ;
    int k , n ,pla ;
    scanf("%d %d" , &n , &k) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d" , &num[i]) ;
    }
    int jud = 0 ;
    for ( int j = 0 ; j < n ; j ++){
        if ( k == num[j]) {
            printf("%d " , j  ) ;
            jud ++ ;
    }
    }
    if ( jud == 0) printf("-1") ;

    return 0 ;
}
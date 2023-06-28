#include <stdio.h>

int main ( void )
{
    int n , m ;
    int a[31][31] = { 0 } , b[31][31] = {0} ;
    scanf("%d %d" , &n , &m) ;
    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < m ; j ++){
            int num ;
            scanf("%d" , &num) ;
            a[i][j] = b[i][j] = num ;
        }
    }

    for ( int i = 0 ; i < n ; i ++ ){
        for ( int j = 1 ; j < m - 1 ; j ++){
            if ( a[i][j] == a[i][j+1] && a[i][j] == a[i][j-1]){
                b[i][j] = b[i][j+1] = b[i][j-1] = 0 ;
            }
        }
    }
    
    for ( int l = 0 ; l < m ; l ++ ){
        for ( int k = 1 ; k < n - 1 ; k ++){
            if ( a[k][l] == a[k+1][l] && a[k][l] == a[k-1][l]){
               b[k][l] = b[k+1][l] = b[k-1][l] = 0 ;
}
        }
    }

    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j <= m ; j ++){
           if ( j == m) printf("\n") ;
           else printf("%d " ,b[i][j] ) ;
        }
    }

    return 0 ;
}
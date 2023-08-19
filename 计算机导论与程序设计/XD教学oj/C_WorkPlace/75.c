#include <stdio.h>

int main ( void )
{
    int squ[300][300] = { 0 } , gray[16] = { 0 } ; 
    int m , n ;
    scanf("%d %d" , &m , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < m ;j ++){
            scanf("%d" , &squ[i][j]) ;
            int rep = squ[i][j] ;
            gray[rep] ++ ;
        }
    }
    for ( int i = 0 ; i < 16 ; i ++){
        if ( gray[i] != 0){
            printf("%d %d\n" , i ,gray[i]) ;
        }
    }

   return 0 ;
}
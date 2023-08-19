#include <stdio.h>

int main ( void )
{
    int squ[102][102] = {0} ;
    int row , line ;
    scanf("%d %d" , &row , &line) ;
    for ( int i = 0 ; i < row ; i ++){
        for ( int j = 0 ; j < line ; j ++){
            scanf("%d" , &squ[i][j]) ;
        }
    }
    for ( int y = line-1 ; y >= 0 ; y -- ){
        for ( int x = 0 ; x < row ; x ++){
            printf("%d " , squ[x][y]) ;
        }
        printf("\n") ;
    }

    return 0 ;
}
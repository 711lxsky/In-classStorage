#include <stdio.h>

int main ( void )
{
    int squ[3][3] = { 0 } , des[3][3] ;
    for ( int i = 0 ; i < 3 ; i ++){
        for ( int j = 0 ; j < 3 ; j ++){
            scanf("%d" , &squ[i][j]) ;
        }
    }
    for ( int i = 0 ; i < 3 ; i ++){
        for (int j = 0 ; j < 3 ; j ++){
           des[i][j] =  squ[i][j] + squ[j][i] ;
           printf("%d " , des[i][j]) ;
           if ( j == 2 ) printf("\n") ;
        }
    }

    return 0 ;
}
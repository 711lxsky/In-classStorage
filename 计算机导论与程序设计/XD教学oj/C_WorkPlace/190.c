#include <stdio.h>

int main ( void )
{
    int squ[3][3] = { 0 } ;
    for ( int i = 0 ; i < 3 ; i ++){
        for ( int j = 0 ; j < 3 ; j ++){
            scanf ("%d" , &squ[i][j]) ;
        }
    }
    printf("%d" , squ[0][0] + squ[1][1] + squ[2][2]) ;

    return 0 ;
    
}
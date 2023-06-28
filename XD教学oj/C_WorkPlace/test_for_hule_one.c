#include <stdio.h>

int main ( void )
{
    int squ[3][4] = { 0 } ;
    int sum_max = 0 ;
    for ( int i = 0 ; i < 3 ; i ++){
        for ( int j = 0 ;j < 4 ; j ++){
            scanf("%d" , &squ[i][j]) ;
        }
    }
    for ( int row = 0 ; row < 3 ; row ++){
        int max_row = -1 ;
        for ( int line = 0 ; line < 4 ; line ++){
            int rep = squ[row][line] ;
            if ( max_row < rep){
                max_row = rep ;
            }
        }
        sum_max += max_row ;
    }
    printf("%d" , sum_max) ;

    return 0 ;
}
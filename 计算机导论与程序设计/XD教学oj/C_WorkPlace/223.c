#include <stdio.h>

int main (void )
{
    int squ[3][3] ;
    int sum = 0 ;
    for ( int i = 0 ; i < 3 ; i ++){
       for ( int j = 0 ; j < 3 ; j ++){
        scanf("%d" , &squ[i][j]) ;
        if ( i == j ) {
            sum += squ[i][j] ;
        }
       }
    }
    printf("%d" , sum) ;

    return 0 ;
}
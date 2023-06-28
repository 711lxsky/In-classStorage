#include <stdio.h>

int main ( void )
{
    int A[2][3] , B[3][2] , C[2][2] ;
    for ( int i = 0 ; i < 2 ; i ++){
        for ( int j = 0 ; j < 3 ; j ++){
            scanf("%d" , &A[i][j]) ;
        }
    }
    for ( int i = 0 ; i < 3 ; i ++){
        for ( int j = 0 ; j < 2 ; j ++){
            scanf("%d" , &B[i][j]) ;
        }
    }

        for ( int i = 0 ; i < 2 ; i ++){
        for ( int x = 0 ; x < 2 ; x ++){
            int sum = 0 ;
            for ( int y = 0 ; y < 3  ; y ++){
                sum += A[i][y] * B[y][x] ;
            }
            C[i][x] = sum ;
    }
}
        for ( int i = 0 ; i <  2; i ++){
        for ( int j = 0 ; j < 2 ; j ++){
            printf("%d " , C[i][j] ) ;
            if ( j == 1 ) printf("\n") ;
        }
      }
return 0 ;
}
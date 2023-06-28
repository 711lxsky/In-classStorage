#include <stdio.h>

int main ( void )
{
    int num[102][102] = { 0 } ;
    int n ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ;j < n ; j ++){
            scanf("%d" , &num[i][j]) ;
        }
    }

    for ( int i = 0  ; i < n ; i ++){
        if ( i % 2 == 0){
            for ( int row = i , line = 0 ;row >= 0 ; row -- , line ++ ){
                printf("%d " , num[row][line]) ;
            }
        }
        else {
           for ( int row = 0 , line = i ; line >= 0 ; row ++ , line --){
              printf("%d " ,num[row][line]) ;
           }
        }
    }

    for ( int i = n  ; i < 2 * n - 1 ; i ++){
        int rep = i - ( n - 1) ;
        if ( i % 2 != 0){
            for ( int row = rep , line = i - rep ;row < n ; row ++ , line -- ){
                printf("%d " , num[row][line]) ;
            }
        }
        else {
           for ( int row = i - rep , line = rep ; line < n ; row -- , line ++){
              printf("%d " ,num[row][line]) ;
           }
        }
    }
    return 0 ;
}
#include <stdio.h>

int main ( void )
{
    int m ;
    int num[22][22] = { 0 } , res[52] = { 0 } ;
    scanf("%d" , &m) ;
    for ( int i = 0 ; i < m ; i ++){
        int sum_row = 0 ;
        for ( int j = 0 ; j < m ; j ++){
            scanf("%d" , &num[i][j]) ;
            sum_row += num[i][j] ;
            if ( j == m - 1 ){
                res[i] = sum_row ;
                sum_row = 0 ;
            }
        }
    }
    for ( int row = 0 ; row < m ; row ++){
        int sum_line = 0 ;
        for ( int line = 0 ; line < m ; line ++){
          sum_line += num[line][row] ;
          if ( line == m - 1 ){
            res[row+m] = sum_line ;
            sum_line = 0 ;
          }
        }
    }
    int sum_ru1 = 0 , sum_ru2 = 0  ;
    for ( int i = 0 , j = 0 ; i < m; i ++ , j ++){
        sum_ru1 += num[i][j] ;
    }
    res[m*2] = sum_ru1 ;
    for (  int i = 0 , j = m - 1 ; i < m ; i ++ , j -- ){
        sum_ru2 += num[i][j] ;
    }
    res[2*m+1] = sum_ru2 ;
    for ( int k  = 2 * m + 1 ; k >= 0 ; k --){
        for ( int l = 0 ; l < k ; l ++){
            if ( res[l] < res[l+1]){
                int rep = res[l+1] ;
                res[l+1] = res[l] ;
                res[l] = rep ;
            }
        }
    }
    for ( int i = 0 ; i <= 2*m + 1 ; i ++){
        printf("%d " , res[i]) ;
    }

    return 0 ;
}
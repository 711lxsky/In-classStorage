#include <stdio.h>

int main ( void )
{
    int squ[4][5] = {0} ;
    for ( int i = 0 ; i < 4 ; i ++){
        for ( int j = 0 ; j < 5; j ++){
            scanf("%d" ,&squ[i][j]) ;
        }
    }
    int jud = 0  ;
    for ( int row = 0 ; row < 4 ; row ++){
        for ( int line = 0 ; line < 5 ; line ++){
            int jud_max = 0 , jud_min = 0;
            int rep = squ[row][line] ;
            for ( int j = 0 ; j < 5; j++ ){
                if ( rep < squ[row][j]) jud_max ++ ;
            }
            for  ( int i = 0 ; i < 4 ; i ++){
                if ( rep > squ[i][line]) jud_min ++ ;
            }
            if ( jud_max == 0 && jud_min == 0) {
                jud ++ ;
                printf("%d %d %d\n" , rep , row+1 , line+1) ;
            }
        }
    }
    if ( jud == 0) printf("鞍点不存在\n");

     return 0 ;
}
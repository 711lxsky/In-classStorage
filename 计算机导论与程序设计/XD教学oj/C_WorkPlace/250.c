 #include <stdio.h>

 int main (void)
 {
    int squ[102][102] = {0} ;
    int m , n , num = 1 ;
    scanf("%d %d", &m , &n) ;
    int last = m *n ;
    int row_sta = 0  , row_end = m-1 , line_sta = 0  ,line_end = n- 1 ;
    while(row_end >= row_sta && line_end >= line_sta){
        for ( int line = line_sta ; line <= line_end ; line++){
            squ[row_sta][line] = num ;
            num ++ ; 
        }
        row_sta ++ ;
        for ( int row = row_sta ; row <= row_end ; row ++){
            squ[row][line_end] = num ;
            num ++ ;
        }
        line_end -- ;
        if ( row_end >= row_sta ) {
            for ( int line = line_end ; line >= line_sta ; line --){
                squ[row_end][line] = num ;
                num ++ ;
            }
            row_end -- ;
        }  
        if ( line_end >= line_sta){
            for ( int row = row_end ; row >= row_sta ; row --){
                squ[row][line_sta] = num ;
                num ++ ;
            }
            line_sta ++ ;
        }
    }
    for ( int i = 0 ; i < m ; i ++){
        for ( int j = 0 ; j < n ; j ++){
            printf("%d " , squ[i][j]) ;
        }
        printf("\n") ;
    }

    return 0 ;
 }
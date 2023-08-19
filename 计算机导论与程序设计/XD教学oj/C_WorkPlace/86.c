#include <stdio.h>

int main ( void )
{
    int area[102][102] = { 0 } ;
    int n ;
    scanf("%d" , &n) ;
    for ( int i = 1 ; i <= n ; i ++){
        int x1 , y1 , x2 , y2 ;
        int max_x , min_x , max_y , min_y ;
        scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2) ;
       //  (x1 > x2) ? (max_x = x1 , min_x = x2) : (max_x = x2 , min_x = x1) ;
        if ( x1 > x2){
            max_x = x1 ;
            min_x = x2 ;
        }
        else {
            max_x = x2 ;
            min_x = x1 ;
        }

        if ( y1 > y2 ){
            max_y = y1 ;
            min_y = y2 ;
        }
        else {
            max_y = y2 ;
            min_y = y1 ;
        }
        for ( int row = min_x ; row <  max_x ; row ++){
            for ( int line = min_y ; line < max_y ; line ++ ){
                area[row][line] = 1 ;
            }
        }
    }
    int sum = 0 ;
    for ( int lon = 0 ; lon < 102 ; lon ++){
        for ( int wid = 0 ; wid < 102 ; wid ++){
            sum += area[lon][wid] ;
        }
    }

    printf("%d" , sum) ;

    return 0 ;
}
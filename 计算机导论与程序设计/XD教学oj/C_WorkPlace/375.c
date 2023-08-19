#include <stdio.h>

int main ( void )
{
    int n  , sum = 0;
    float cen ,  deg , sum_deg = 0 , min = 10000 , max = -10000;
    scanf("%d" , &n) ;
    for ( int i = 1 ; i <= n ; i++){
        scanf("%f" , &cen) ;
        deg = 9 * cen / 5 + 32.0 ;
        if ( min > deg )  min = deg ;
        if ( max < deg )  max = deg ;
        sum_deg += deg ;
        printf("%.1f" , deg) ;
        sum ++ ;
        if ( sum == 5){
            putchar('\n') ;
            sum = 0 ;
        }
        else {
            putchar(' ') ;
        }
    }if ( n % 5 != 0) putchar('\n') ;
    printf("%.1f %.1f %.1f" , min , max , sum_deg / n) ;

    return 0 ;
}
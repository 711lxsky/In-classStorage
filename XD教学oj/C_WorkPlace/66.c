#include <stdio.h>

int main ( void )
{
    int  i ,n ,num ,sum=0 ;
    float res  = 0;
    scanf("%d" ,&n) ;
    for ( i = 1; i <= n ; i ++){
        scanf("%d" , &num) ;
        sum += num ;
    }
    res = (float) sum / n ;

    printf("%.2f" , res) ;
    return 0;
}
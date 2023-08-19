#include <stdio.h>

int main ( void )
{
    int num  ,i , sum = 0 ;
    scanf("%d" ,&num) ;
    if ( num == 0){
        sum ++ ;
    }

    while ( num != 0){
        sum ++ ;
        num /= 10 ;
    }
    printf("%d" , sum) ;

    return 0;
}
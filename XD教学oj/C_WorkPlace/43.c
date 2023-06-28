#include <stdio.h>

int main (void)
{
    int rep ,num , max = -1 , min = 10 , sum = 0 ;
    scanf("%d" ,&num) ;
    if (num == 0){
        sum = 1 ;
        max = 0 ;
        min = 0 ;
    }
    while ( num != 0){
        rep = num % 10 ;
        if ( max <= rep ){
            max = rep ;
        }
        if ( min >= rep){
            min = rep ;
        }
        num /= 10 ;
        sum ++ ;
    } 
    printf("%d %d %d" , sum , max , min) ;

    return 0;
}
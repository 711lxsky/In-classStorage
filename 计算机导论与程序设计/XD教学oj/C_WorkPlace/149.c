#include <stdio.h>

int main ( void )
{
    int i , j ,n ,dec = -1;
    float sum =1 , num1 = 1,rep = 1 , num2 = 1 , num  ;
    scanf("%d" , &n) ;
    
    for (i = 2; i <= n ; i ++){
         dec = -1 ;
        for (j=1 ; j <= i ; j ++ ){
            dec *= -1 ;
        }
        num2 += 2 ;
        num =  dec * i / num2 ;
        sum += num ;
       // printf("%d %f %f\n" ,dec ,sum ,num ) ;

        
    }
    printf("%.3f" , sum) ;
    return 0;
}
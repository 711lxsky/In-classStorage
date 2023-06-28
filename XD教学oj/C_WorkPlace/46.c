#include <stdio.h>
#define true 1 ;
#define false 0 ;
int main ( void )
{
    
    int num1 , num2 , gap , n ,sum =0,gap1 , gap2  = 2, i ;
    scanf("%d" , &n) ;
    scanf("%d" ,&num1 );
     for ( i = 2 ; i <= n ; i ++){
        scanf("%d" , &num2) ;
        gap = num2 - num1 ;
        if( gap > 0){
            gap1 = true ;
        }
        else {
            gap1 = false ;
        }

        if(gap1 != gap2){
            sum ++ ;
        }
        gap2 = gap1 ;
        num1 = num2 ;
     }
     printf("%d" ,sum -1) ;

     return 0;
}
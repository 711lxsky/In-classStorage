#include <stdio.h>

int main ( void )
{
   int i , n , sum1 = 0,sum2 =0  , sum3 =0  , sum5 = 0 , sum7 = 0;
   scanf("%d" ,&n) ;
   for ( i=1 ; i <= n ;i ++){
    if ( i % 2 != 0){
        sum1 ++ ;
        
    }
    else {
        sum2 ++ ;
    }
    if ( i % 3 == 0 ){
            sum3 ++ ;
        }
        if ( i % 5 == 0){
            sum5 ++ ;
        }
        if ( i % 7 == 0){
            sum7 ++ ;
        }
   }
   printf("%d %d %d %d %d" , sum1 , sum2 ,sum3 ,sum5 ,sum7);

   return 0;
}
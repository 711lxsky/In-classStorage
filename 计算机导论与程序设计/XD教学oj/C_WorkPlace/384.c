#include <stdio.h>
#include <math.h>

int main (void)
{
   int sta ,num , end ,n ,i ,x, rep , sum = 0 , max = -1 ;
   scanf("%d" , &n) ;
   scanf("%d" , &sta) ;
   for ( i = 1 ; i <= n ; i ++){
        scanf("%d" , &num) ;
        rep = abs (num) ;
        sum += rep ;
        if ( max <= rep){
            max = rep ;
            x = i ;
        }
   }
   end = sta - sum ;
   printf("%d %d" , end , x) ;
   return 0;
}
#include <stdio.h>

int main (void)
{
      int num[102] = { 0 } , res[1002] = { 0 } ;
      int n , x ;
      scanf("%d" , &n) ;
      for ( int i = 0 ; i < n ; i ++){
        scanf("%d" , &x) ;
        num[i] = x ;
        res[x] ++ ;
      }
     
      for ( int k = 0 ; k < 1002 ; k ++){
        if ( res[k] != 0){
            printf("%d %d\n" , k , res[k]) ;
        }
      }

      return 0 ;
}
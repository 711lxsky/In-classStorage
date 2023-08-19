#include <stdio.h>

int main (void)
{
    int num[100] = {0} ;
   int qq_num , rep_num , n , i , j , sum = 0 , max_sum = -1 , max_num = -1;

   scanf("%d" , &n) ;

   for ( i = 0 ; i <= n - 1 ; i ++){
    scanf("%d" , &num[i]) ;
   }

   for ( i = 0 ; i <= n-1 ; i ++){

    rep_num = num[i] ;
    sum  = 0 ;

    while(rep_num != 0){
        sum += rep_num % 10 ;
        rep_num /= 10 ;
    }

    if (max_sum < sum){
        max_sum = sum ;
        max_num = num[i] ;
    }

    else if ( max_sum == sum && max_num < num[i]){
            max_num = num[i];
    }
   }

   printf("%d" , max_num) ;
   return 0;
}
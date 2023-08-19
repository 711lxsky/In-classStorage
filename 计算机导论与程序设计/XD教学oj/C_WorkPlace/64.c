#include <stdio.h>

int main (void)
{
    int res , rep ,  num , sum = 0 ,i , j , k , odd ;
    scanf("%d" , &num) ;
    res = num * num * num ;
    
    for ( i = 1 ; i <= res ; i += 2){
        sum  = 0 ;
        odd = i ;
       for ( j = 1 ; j <= num ; j ++ ){
        sum += odd ;
        odd += 2 ;
       }
       rep = i ;

       if (sum == res){
        for( k = 1 ;k <= num ; k ++){
            printf("%d " , rep) ;
            rep += 2 ;
        }

       }
    }
    return 0 ;
}
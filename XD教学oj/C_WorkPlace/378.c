#include <stdio.h>
#include <math.h>

int main ( void )
{
    int num , n ,res ;
    scanf("%d" ,&num) ;
    if ( num % 2 != 0) printf("-1") ;
    else {
            for (int i = 19 ; i >= 1 ; i --){
                 if ( pow(2,i) <= num){
                    res = pow(2,i) ;
                    num -= res ;
                    printf("%d " , res) ;
                 }
            }
    }
    return 0 ;
}
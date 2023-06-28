#include <stdio.h>

int main ( void )
{
    int i , j , n , x = 1 , num  = 1, sum1 = 0 , g = 0 , s = 0 , b = 0 , q = 0 ,sum2 = 0 , sum3 = 0 ;
    scanf("%d" , &n) ;

    for ( i =1 ; num <= n ; i ++){
        if ( i >= 10 && i < 100){
            g = i % 10 ;
            s = i / 10 ;
        }
        else if ( i >= 100 && i < 1000 ){
           g= i % 10 ;
           s = i / 10 % 10 ;
           b = i / 100 ;
        }
        else if ( i >=1000 && i <10000){
            g = i % 10 ;
            s = i / 10 % 10 ;
            b = i /100 % 10 ;
            q = i / 1000 ;
        }
        if ( i % 7 == 0 || g == 7 || s == 7 || b == 7 || q == 7){
            if ( x % 3 == 1){
            
                sum1 ++ ;
            }
            else if ( x % 3 == 2){
                sum2 ++ ;
            }
            else if ( x % 3 == 0){
                sum3 ++ ;
            }
            x ++ ;
        }
        else {
            x ++ ;
            num ++ ;
        }
    }
    printf("%d %d %d" , sum1 , sum2 , sum3 );

    return 0;
}
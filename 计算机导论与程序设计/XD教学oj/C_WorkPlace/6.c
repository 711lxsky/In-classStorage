#include <stdio.h>

int main ( void )
{
    int num1[1002] = { -1 } , num2[1002] = { -2 } ;
    int n , num , sum_max = -1 , num_max = -2 ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d" , &num1[i]) ;
        int rep = num1[i] ;
        int sum = 0 ;
        while ( rep != 0){
          sum += rep % 10 ;
          rep /= 10 ;
        }
        num2[i] = sum ;
    }
    int lab ;
    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < n ; j ++){
            if ( sum_max < num2[j]){
                sum_max = num2[j] ;
                num_max = num1[j] ;
                lab = j ;
            }
            else if ( sum_max == num2[j] && num_max > num1[j]){
                num_max = num1[j] ;
                lab = j ;
            }
        }
        num1[lab] = -1 ;
        num2[lab] = -2 ;
        printf("%d %d\n" , num_max , sum_max) ;
        num_max = -2 ;
        sum_max = -1 ;
    }
    return 0 ;
}
#include <stdio.h>

int main (void)
{
    int num[10002] = {0} ;
    int n ; 
    scanf("%d" , &n) ;
    for (int i = 0 ; i <n ; i ++){
        scanf("%d" ,&num[i] );
    }
    for (int i = n - 1 ; i >= 0 ; i --){
        for ( int j = 0 ; j < i ; j ++){
            if ( num[j] > num[j+1]){
                int rep = num[j] ;
                num[j] = num[j+1] ;
                num[j+1] = rep ;
            }
        }
    }
    int max = num[n-1] , min = num[0] , med ;
    if ( n % 2 != 0 ){
        med = num[(n-1) / 2] ;
    }
    else {
        med = (num[n/2 -1] + num[n/2] ) / 2 ; 
    }
    printf("%d %d %d" , max , med , min) ;

    return 0 ;
}
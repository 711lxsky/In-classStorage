#include <stdio.h>

int main ( void )
{
    int num[102] = {0} ;
    int n  ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d" , &num[i]) ;
    }
      for ( int j = n - 1 ; j > 0  ; j --){
        for ( int k = 0 ; k < j ; k ++){
            if ( num[k] > num[k+1]) {
                int rep = num[k] ;
                num[k] = num[k+1] ;
                num[k+1] = rep ;
            }
        }
    }
    int des ;
    if ( n % 2 != 0){
        des = num[(n-1)/2] ;
    }
    else {
       des = (num[n/2-1] + num[n/2]) / 2 ;
    }
    printf("%d" , des) ;

    return 0 ;
}
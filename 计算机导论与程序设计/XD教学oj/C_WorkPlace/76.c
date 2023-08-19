#include <stdio.h>

int main ( void )

{
    int num[50] = { 10000002 } ,tem[50] = {-1} , des[100003] = { 0 } ;
    int n , res ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d" , &num[i]) ;
    }
    for ( int i = n - 1 ; i >= 0 ; i -- ){
        for ( int j = 0 ; j < i ; j ++ ){
            if ( num[j] > num[j+1] ) {
                int rep = num[j] ;
                num[j] = num[j+1] ;
                num[j+1] = rep ;
            }
        }
    }
    int sum = 0 ;
    for ( int j = 0 , k = 0; j < n ; j ++){
        int rep = num[j] ;
        des[rep] ++ ;
        if ( tem[k] != rep) {
            k ++ ;
            tem[k] = rep ;
            sum ++ ;
        }
    }
    for ( int i = 1 ; i <= sum ; i ++){
        int rep = tem[i] ;
        printf("%d:%d\n" , rep , des[rep]) ;
    }
    return 0 ;
}
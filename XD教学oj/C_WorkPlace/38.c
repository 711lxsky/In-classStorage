#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int mys[20] = { -1 } ;
    int num , n = 0, sum = 0 ;
    scanf("%d" , &num) ;
    int rep = num ;
    while ( rep != 0){
        sum += rep % 10 ;
           n ++ ;
           rep /= 10 ;
    }
    rep = num ;
    for ( int i = 0 ; i < n ; i ++){
        mys[i] = rep % 10 ;
        rep /= 10 ;
    }
    int jud = 0 ;
    for ( int j = 0 ; j < n ; j ++){
        if ( mys[j] != mys[n-j-1]){
            jud ++ ;
            break ; 
        }
    }
    jud = abs(jud) ;
     if ( jud == 0 ) printf("%d" , sum) ;
     else printf("no") ;
     return 0 ;

    
}
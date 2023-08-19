#include <stdio.h>

int main  (void)
{
    int num[1001] = {0} ;
    int n , x, num_max = -1 , con = 0 ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d" , &x) ;
        num[x] ++ ;
        if ( num_max < x) num_max = x ;
    }
    for ( int i = 0 ; i < 1001 ; i ++) {
        if (num[i] != 0) con ++ ;
    }
    for ( int i = 0 ; i < con ; i ++){
        int lab = 0 ;
        int time_max = 0 ;
        for ( int j = 0 ; j <= num_max ; j ++){
            if ( time_max < num[j]) {
                time_max = num[j] ;
                lab = j ;
            }
            
        }
        printf("%d %d\n" , lab , num[lab]) ;
        num[lab] = -1 ;
    }
}
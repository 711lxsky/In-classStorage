#include <stdio.h>

int main ( void )
{
    int num[102] = {0} ;
    int n , ins ;
    scanf("%d" , &n) ;
    for (int i = 0 ; i < n ; i ++){
        scanf("%d" , &num[i] ) ;
    }
    scanf("%d" , &ins) ;
       for ( int j = n - 1 ; j > 0  ; j --){
        for ( int k = 0 ; k < j ; k ++){
            if ( num[k] > num[k+1]) {
                int rep = num[k] ;
                num[k] = num[k+1] ;
                num[k+1] = rep ;
            }
        }
    }
    if ( ins <= num[0]){
        for ( int i = n ; i > 0 ; i --){
            int rep = num[i] ;
            num[i] =  num[i-1] ;
            num[i-1] = rep ;
        }
        num[0] = ins ;
    }
    else if ( ins >= num[n-1]) {
        num[n] = ins ;
    }
    else {
        int lab = 1 ;
        for ( int j = 0 ; j < n - 1 ; j ++ ){
            if ( ins >= num[j] && ins <= num[j+1]){
               lab = j + 1 ;
            }
        }

        for ( int i = n ; i > lab ; i --){
              int rep = num[i] ;
            num[i] =  num[i-1] ;
            num[i-1] = rep ;
        }
        num[lab] = ins ;
    }
    for ( int i = 0 ; i <= n ; i ++){
        printf("%d " , num[i]) ;
    }
return 0 ;
}
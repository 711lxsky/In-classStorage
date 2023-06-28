#include <stdio.h>

int main ( void )
{
    int num_op[10] = {0} , num_re[10] = {0} ;
    int num , i = 0 , wei = 0 ;
    scanf("%d" , &num) ;
    int rep = num ;
    while ( rep != 0 ){
        num_re[i] =  num_op[i] = rep % 10 ;
        rep /= 10 ;
        i ++ ;
        wei ++ ;
    }
    for ( int j = wei - 1 ; j > 0  ; j --){
        for ( int k = 0 ; k < j ; k ++){
            if ( num_re[k] < num_re[k+1]) {
                int rep = num_re[k] ;
                num_re[k] = num_re[k+1] ;
                num_re[k+1] = rep ;
            }
        }
    }
    int res_op = 0 , res_re = 0 ;
    for ( int j = 0 ; j < wei ; j ++){
        res_op = res_op * 10 + num_op[j] ;
        res_re = res_re * 10 + num_re[j] ;        
    }
    printf("%d" , res_op + res_re) ;

    return 0 ;
}
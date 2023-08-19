#include <stdio.h>

int main( void )
{
    int num1[102] = { -1000000 } , num2[102] = { -2000000 } ;
    int max_num = -1766554 , n , num ;
    scanf("%d" , &n) ;
    for (int i = 0 ; i < n ; i ++){
        scanf("%d" , &num1[i]) ;
    }
    int lab ;
    for ( int j = 0 ; j < n ; j ++){
        for ( int k = 0 ; k < n ; k ++){
            if ( max_num < num1[k]) {
                max_num = num1[k] ;
                lab = k ;
            }
        }
      num2[j] =   max_num ;
      num1[lab] = -1000000 ;
      max_num = - 1000000 ;
    }
    int jud = 0 ;
    for ( int i = 0 ; i < n - 2 ; i ++){
        if ( num2[i] - num2[i+1] != num2[i+1] - num2[i+2]){
            jud ++ ;
            break ;
        }
    }
       if ( jud == 0) printf("%d" , num2[0] - num2[1]) ;
       else printf("no") ;
       return 0 ;
}
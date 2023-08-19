#include <stdio.h>

int main ( void )
{
    int sta[102]  , res[102] , odd[102]  , eve[102];
    for ( int i = 0 ; i < 102 ; i ++){
        sta[i] = res[i] = eve[i] = odd[i]  = -100000 ;
    }
    int n , num ,lab_e = 0 , lab_o = 0 ;
    scanf("%d" , &n) ;
    for ( int i = 0  ; i < n ; i ++){
        scanf("%d" , &num) ;
        sta[i] = num ;
        if ( num % 2 == 0){
           eve[lab_e] = num ;
           lab_e ++ ;
        }
        else {
            odd[lab_o] = num ;
            lab_o ++ ;
        }
    }

    for ( int i = lab_e - 1 ; i >= 0 ; i --){
       for ( int j = 0 ; j < i ;j ++){
        if ( eve[j] < eve[j+1]){
            int rep = eve[j+1] ;
            eve[j+1] = eve[j] ;
            eve[j] = rep ;
        }
       }
    }

     for ( int i = lab_o - 1; i >= 0 ; i --){
       for ( int j = 0 ; j < i ;j ++){
        if ( odd[j] < odd[j+1]){
            int rep = odd[j+1] ;
            odd[j+1] = odd[j] ;
            odd[j] = rep ;
        }
       }
    }
    for ( int i = 0 ;i < lab_e ;i ++) printf("%d " ,eve[i]) ;
    for ( int i = 0 ;i < lab_o ;i ++) printf("%d " ,odd[i]) ;

return 0 ;
}
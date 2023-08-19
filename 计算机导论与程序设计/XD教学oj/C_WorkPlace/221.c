#include <stdio.h>

int main ( void )
{
    char mys[1000] = {' '} ;
    int sum_alp = 0  , sum_num = 0  , sum = 0;
    gets(mys) ;
    /*for ( int j = 0 ; mys[j] != '\n' ; j ++){
        sum ++ ;
    }
    printf("%d" ,sum) ;*/
    for ( int i = 0 ; i < 1000 ; i ++){
        char rep = mys[i] ;
        if (( rep >= 'A' && rep <='Z') || (rep >= 'a' && rep <= 'z')) sum_alp ++ ;
        else if ( rep >= '0' && rep <= '9') sum_num ++ ;
    }

    printf("%d,%d" , sum_alp , sum_num) ;
    return 0 ;
}
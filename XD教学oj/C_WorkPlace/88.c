#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    char sta[15] = {'\0'} , dig[11] = {'\0'} ;
    gets(sta) ;
    int sum_num = 0 ;
    for ( int i = 0 , j = 0 ; i < 12 ; i ++){
        char rep = sta[i] ;
        if ( isdigit(rep)) {
            j ++ ;
            sum_num +=( rep - '0') * j ; 
        }
    }
    char jud ;
    int mod = sum_num % 11 ;
    if ( mod == 10 ){
        jud = 'X' ;
    }
    else {
        jud = mod + '0' ;
    }
    if ( jud == sta[12]) printf("Right") ;
    else {
        sta[12] = jud ;
        puts(sta) ;
    }

    return 0 ; 
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    char ch[101] = {'\0'} ;
    gets(ch) ;
    int len = strlen(ch) ;
    int dig[101] = {0} ;
    int num = 0 ;
    for ( int i = 0 ; i < len ; i ++){
        char rep = ch[i] ;
        if (isdigit(rep) ) {
            dig[num] = dig[num] * 10 + rep - '0' ;
            if ( i != len -1 && ! isdigit(ch[i+1])) num ++ ;
        }
    }
    if ( isdigit( ch[len-1] )) num ++ ;
    for ( int i = num - 1 ; i >= 0 ; i --){
        for ( int j = 0 ; j < i ; j ++){
            if ( dig[j] < dig[j+1]) {
                int rep = dig[j] ;
                dig[j] = dig[j+1] ;
                dig[j+1] = rep ;
            }
        }
    }
    for ( int i = 0 ; i < num ; i ++){
        printf("%d " , dig[i]) ;
    }
}
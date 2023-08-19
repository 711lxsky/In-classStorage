#include <stdio.h>
#include <string.h>

int main (void)
{
    char ch[11] = {'\0'} ;
    gets(ch) ;
    int len = strlen(ch) ;
    int dig[11] = {0} ;
    for ( int i = 0 ; i < len ; i ++){
        dig[i] = ch[i] - '0' ;
    }
    for ( int i = len -1 ; i >= 0 ; i --){
        for ( int j = 0 ; j < i ; j ++){
            if ( dig[j] < dig[j+1]) {
                int rep = dig[j] ;
                dig[j] = dig[j+1] ;
                dig[j+1] = rep ;
            }
        }
    }
    for ( int i = 0 ; i < len ; i ++){
        printf("%d " , dig[i]) ;
    }
}
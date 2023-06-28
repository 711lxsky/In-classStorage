#include <stdio.h>
#include <string.h>

int main ( void )
{
    char ch[102] = {'\0'} ;
    gets(ch) ;
    int len_ch = strlen(ch) ;
    for ( int i = len_ch - 1 ; i >= 0   ; i --){
        for (int j = 0 ; j < i ; j ++){
            if ( ch[j] > ch[j+1]) {
                char rep = ch[j] ;
                ch[j] = ch[j+1] ;
                ch[j+1] = rep ;
            }
        }
    }
    puts(ch) ;

    return 0 ;
}
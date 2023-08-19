#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    char sen[1001] = {'\0'} ;
    gets(sen) ;
    int len = strlen(sen) ;
    int sta_len = 0 ;
    int jud_len = -1 ;
    for ( int i = 0 ; i < len ; i ++){
        char rep = sen[i] ;
        if ( isalpha(rep)) sta_len ++ ;
        else if (' ' == rep || '.' == rep) sta_len = 0 ;
        if ( sta_len > jud_len) jud_len = sta_len ;
    }
    printf("%d" , jud_len) ;
}
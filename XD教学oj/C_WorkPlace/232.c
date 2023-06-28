#include <stdio.h>
#include <string.h>

int main (void)
{
    char mys[52] = {'\0'} ;
    gets(mys) ;
    int len_mys = strlen(mys) ;
    int jud = 1 ;
    for ( int i = 0 ; i <= (len_mys + 1) / 2 - 1 ; i ++){
        if ( mys[i] == mys[len_mys-i-1]) jud = 1 ;
        else {
            jud = 0 ;
            break;
        } 
    }
    if ( jud ) printf("yes") ;
    else printf("no") ;
}
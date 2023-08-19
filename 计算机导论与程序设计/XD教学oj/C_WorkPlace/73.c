#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    char ch[102] = {'\0'} ;
    gets(ch) ;
    int len_ch = strlen(ch) ;
    for ( int i = 0 ; i  < len_ch ; i ++){
        char rep = ch[i] ;
        int x = i ;
        if (isdigit(rep) ) {
            int cop = 0 ;
            if ( isdigit (ch[x+1])) {
                cop += rep - '0' ;
                cop *= 10 ;
                cop += ch[x+1] - '1' ;
                i ++ ;
            }
            else {
                cop += rep - '1' ;
            }
            for ( int j = 0 ; j < cop ; j ++) 
            printf("%c" , ch[x-1]) ;
            //i ++ ;
        
        }
        else if ( isalpha(rep)) printf("%c" , rep) ;
    }

    return 0 ;
}
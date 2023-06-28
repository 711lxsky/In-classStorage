#include <stdio.h>
#include <ctype.h>

int main ( void )
{
    int i , j ;
    char reg[88] = {'\0'} , des[88] = {'\0'} ;
    gets(reg) ;
    for (  i = 0 , j = 0 ; reg[i] != '\0' ; i ++){
        char res = reg[i] ;
        if (isalpha(reg[i])) {
           des[j] =  toupper(res) ;
           ++ j ;
        }
    }
    for ( int x = j - 1; x >= 0 ; x --){
        for ( int y = 0 ; y < x ; y ++){
            if ( des[y] > des[y+1]) {
                char rep = des[y] ;
                des[y] = des[y+1] ;
                des[y+1] = rep ;
            }
        }
    }
    for ( int k = 0 , l = 0 ; k < i ; k ++){
        if ( isalpha(reg[k])){
            reg[k] = des[l] ;
            l ++ ;
        }
    }
    puts(reg) ;

    return 0 ;
}
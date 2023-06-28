#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ( void )
{
    int gra = 0 , jud1 = 0 , jud2 = 0  , jud3 = 0 , jud4 = 0 ;
    char code[52] = { '\0'} ;
    gets(code) ;
    if ( 0 == strlen(code)) gra = 0 ;
    else {
        gra ++ ;
        if ( strlen(code) > 8) gra ++ ;
        for ( int i = 0 ; code[i] != '\0' ; i ++){
            char rep = code[i] ;
              if ( isupper(rep)) jud1 = 1 ;
              else if ( islower(rep)) jud2 = 1 ;
              else if ( isdigit(rep))  jud3 = 1 ;
              else jud4 = 1 ;
        }
    }
    int sum = jud1 + jud2 + jud3 + jud4 ;
    if ( sum != 0 ){
        sum -- ;
        gra += sum ;
    }

    printf("%d" , gra) ;

    return 0 ;

}
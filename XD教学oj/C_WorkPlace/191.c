
#include <stdio.h>
#include <ctype.h>

int main ( void )
{
    char sta[1001] = { '\0' } , res[1001] = { 0 } ;
    gets(sta) ;
    for ( int i = 0 ; sta[i] != '\0' ; i ++){
        char rep ;
       if ( isupper(sta[i]) ) rep = 25 - (sta[i] - 'A') + 'A' ;
       else if ( islower(sta[i])) rep = 25 - (sta[i] - 'a') + 'a' ;
       else rep = sta[i] ;
       res[i] = rep ;    
    }
    printf("%s" ,  res) ;

    return 0 ;
}
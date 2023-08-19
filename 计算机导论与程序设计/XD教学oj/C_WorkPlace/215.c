#include <stdio.h>

int main ( void )
{
    char mys[1000] = {'.'} ;
    int i , j ;
      gets(mys) ;
     for ( i = 999 ; i >= 0 ; i --){
        if ( mys[i] != '.')
        putchar(mys[i]) ;
     }

     return 0 ;
}
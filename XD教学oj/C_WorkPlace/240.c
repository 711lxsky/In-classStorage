#include <stdio.h>

int main ( void )
{
    char mys[10000] = { 0 } ;
    gets(mys) ;
    printf("%s" , mys) ;

    return 0 ;
}
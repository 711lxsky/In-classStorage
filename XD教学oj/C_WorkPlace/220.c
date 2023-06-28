#include <stdio.h>
#include <string.h>

int main (void)
{
    char mys[1001] ;
    gets(mys) ;
    printf("%d" , strlen(mys)) ;
}
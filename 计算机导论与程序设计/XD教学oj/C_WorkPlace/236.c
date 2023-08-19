#include <stdio.h>
#include <string.h>

int main (void)
{
    char mys[1001] = {'\0'} ;
    gets(mys) ;
    int len = strlen(mys) ;
    printf("%d" , len) ;
}
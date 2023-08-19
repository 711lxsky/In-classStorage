#include <stdio.h>

int main (void)
{
    char * str[13] = {"January","February","March","April","May","June","July","Augest","September","October","November","December","wrong"} ;
    int n ;
    scanf("%d" , &n) ;
    if ( n >= 1 && n <= 12) printf("%s" ,*(str+n-1)) ;
    else printf("%s" , *(str + 12)) ;
}
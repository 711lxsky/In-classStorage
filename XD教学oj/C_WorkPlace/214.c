#include <stdio.h>
#include <string.h>
#include <ctype.h>

void count ( char * , int * , int) ;
int main (void)
{
    char string[101] ;
    int num[5] = {0};
    gets(string) ;
    int len = strlen (string) ;
    count( string , num , len) ;
    for ( int i = 0 ; i < 5 ; i ++) printf("%d " , num[i]) ;
}

void count ( char * ch , int * jud , int n)
{
    for ( int i = 0 ; i < n ; i ++){
        char rep = * ( ch + i) ;
        if ( isupper(rep)) ( *(jud + 0)) ++ ;
        else if ( islower(rep)) (*(jud + 1)) ++ ;
        else if ( ' ' == rep) (*(jud + 2)) ++ ;
        else if ( isdigit(rep)) (*(jud + 3)) ++ ;
        else (* (jud + 4)) ++ ;
    }
}
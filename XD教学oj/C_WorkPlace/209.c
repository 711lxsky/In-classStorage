#include <stdio.h>
#include <string.h>

void char_cp( char *p , char * des) ;
int main ( void )
{
    int n ;

    char mys[52] = {'\0'}  , ch[52] = {'\0'};
    gets(mys) ;
    scanf("%d" ,&n) ;
    char_cp( &mys[n+1] , ch) ;
    printf("%s" , ch) ;

    return 0 ;
}

void char_cp ( char *p , char *des)
{
    while ( *p != '\0'){
        *des = *p ;
        des ++ ;
        p ++ ;
    }
}
#include <stdio.h>
#include <string.h>

void copystr ( char * , char * , int ) ;
int main (void)
{
    char ch[52] = {'\0'} , des[52] = {'\0'};
    int m ;
    gets(ch) ;
    scanf("%d" , &m) ;
    int len_ch = strlen(ch) ;
    if ( len_ch < m ) printf("error") ;
    else {
        copystr(des , ch , m) ;
        printf("%s" , des) ;
    } 
    
    
}

void copystr ( char *des ,char  *sta , int m)
{
    
    for ( int i = 0 , j = m - 1 ; j < strlen(sta) ; i++ , j ++ ){
        * (des + i) = * ( sta + j) ;
    }
}
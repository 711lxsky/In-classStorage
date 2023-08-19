#include <stdio.h>
#include <string.h>
#include <ctype.h>

void wd_sort( char (*p)[] , int x ) ;
int main ( void )
{
    char str[10][20] = {'\0'} ;
    int n ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%s" , &str[i]) ;
    }
    wd_sort(str , n) ;
    for ( int i = 0 ; i < n ; i ++){
        printf("%s\n\n" , str[i]) ;
    }
    return 0 ;
}

void wd_sort( char (*p)[20] , int n)
{
       int len[10] = {0} ;
       char rep[20] ;
       for ( int i = 0 ; i < n - 1 ; i ++){
        for ( int j = 0 ; j < n -i - 1 ; j ++){
            if ( strcmp(*(p+j) , *(p+j+1) ) >  0){
           strcpy( rep , *(p+j)) ;
           strcpy( *(p+j) , *(p+j+1)) ;
           strcpy( *(p+j+1) , rep) ;
            }
        }
       }
}


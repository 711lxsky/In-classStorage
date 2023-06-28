#include <stdio.h>

int func( char mys) ;
int main ( void )
{
    char ch[10000] = { 0 } ;
    int sum = 0 ;
     gets(ch) ;
     for ( int i = 0 ; ch[i] != 0 ; i ++){
           if ( func(ch[i])) sum ++ ;  
     }

     printf("%d" ,sum) ;

     return 0 ;

}

int func( char mys)
{
    int res = 0 ;
    if (( mys >= 'A' && mys <= 'Z') || ( mys >= 'a' && mys <= 'z' )){ res = 1 ;}
    return res ;
}
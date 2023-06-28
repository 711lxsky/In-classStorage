#include <stdio.h>

int main ( void )
{
     char s[10000] = {0} , t[10000]= { 0 } ;
     gets(s) ;
     int j = 0 ;
     for ( int i =0; i < 10000 ; i +=2  ){
        t[j] = s [i] ;
        j ++ ;
     }

     printf("%s" , t) ;

     return 0 ;

}
#include <stdio.h>
#include <string.h>

int main ( void )
{
    char mys[52] = {'\0'} , des[52] = {'\0'} ;
    char ch ;
    gets(mys) ;
   ch =  getchar() ;
   int len_mys = strlen(mys) ;
   for ( int i = 0 ; i < len_mys ; i ++){
    if ( mys[i] == ch){
        mys[i] = '\0' ;
    }
   }
   for ( int j = 0 , k = 0; j < len_mys ; j++){
    if ( mys[j] != '\0') {
        des[k] = mys[j] ;
        k ++ ;
    }
   }
   printf("%s" , des) ;

   return 0 ;
}
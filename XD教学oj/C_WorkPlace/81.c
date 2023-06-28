#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    char des[102] = {'\0'} , str[102] = {'\0'} ;
    int n  , swi ;
    gets(des) ;
    int len_des = strlen(des) ;
    scanf("%d\n%d\n" , &swi , &n) ;
    for ( int i = 0 ; i < n ; i ++){
       gets(str) ;
       int len_str = strlen(str) ;
       
       if(swi == 0){
        for ( int i = 0 ; i < len_des ; i ++){
            des[i] = toupper(des[i]) ;
        }
        for ( int j = 0 ; j < len_str ; j ++){
            str[j] = toupper(str[j]) ;
        }
       }

       char *jud = strstr(str , des) ;
       if ( NULL != jud) puts(str) ; 
    }
    return 0 ;
}
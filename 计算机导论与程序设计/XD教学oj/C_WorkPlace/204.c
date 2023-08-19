#include <stdio.h>
#include <string.h>

int main (void)
{
    char str[102] = {'\0'} , wor[10] = {'\0'} ;
    gets(str) ;
    gets(wor) ;
    int jud = 0 ,sum = 0 ,len_s = strlen(str) ,len_w = strlen(wor) ;

    for ( int i = 0 , j = 0 ; i < len_s ; i ++){

        jud = 0 ;

        if ( i == 0 && str[i] == wor[0]) {

            for ( int k = 0 ; k < len_w ; k ++){
                 if ( str[i+k] == wor[k]) jud = 1 ;
                 else jud = 0 ;
            }
          }
        else if ( str[i+len_w] == '\0'&&str[i-1] == ' ') {

             if ( str[i] == wor[0]) {
                 for ( int k = 0 ; k < len_w ; k ++){
                 if ( str[i+k] == wor[k]) jud = 1 ;
                 else jud = 0 ;
             }
        }
        }
          else{ 
            if( str[i] == wor[0]&& str[i+len_w] == ' '&&str[i-1] ==' ' ){
            for ( int k = 0 ; k < len_w ; k ++){
                 if ( str[i+k] == wor[k]) jud = 1 ;
                 else jud = 0 ;
          }
          }
    }
    if ( jud ==1 ) sum ++ ;

    }
    printf("%s %d" , wor , sum) ;

    return 0 ;

}
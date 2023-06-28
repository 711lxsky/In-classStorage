#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main (void)
{
    char ch[101] = {'\0'} ;
    int dig[101] = {0} ;
    gets(ch) ;
    int len = strlen(ch) ;
    int num = 0 , jud1 = 0 ;
    for ( int i = 0 ; i < len ; i ++ ){
        if ( isdigit(ch[i] )) {
            if ( ch[i] != '0') jud1 ++ ;
            if ( jud1 ){
                dig[num] = ch[i] - '0' ;
                num ++ ;
            } 
        }
    }
    int des = 0 ;
    for ( int i = 0 ; i < num ; i ++){
         des = des * 10 + dig[i] ;
    }
    int rep = 0 , jud = 0 ;
    for (rep = 2 ; rep <= des / 2 + 1  ; rep ++){
        if (0 == des % rep ){
            jud = rep ;
        }
    }
    printf("%d" , jud) ; 

}
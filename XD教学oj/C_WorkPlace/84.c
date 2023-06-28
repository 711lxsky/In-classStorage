#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    char root_cata[202] = {'/'} , sta_cata[202] = {'\0'} ;
    char ope[202] = { '\0' } ;
    gets(sta_cata) ;
    while(gets(ope) != NULL){
        if( ope[0] == 'p') break;
        int len_sta_cata = strlen(sta_cata) ;
        int len_ope = strlen(ope) ;
        int jud_root =  strcmp(root_cata , sta_cata) ;
        
        if (  ope[3] == '/' && ope[4] == '\0'){
            if (jud_root != 0) {
               strcpy(sta_cata , root_cata) ;
            }
        }
        else if ( ope[3] == '.'){
            if ( jud_root != 0) {
                int i ;
                for (  i = len_sta_cata - 1 ;  sta_cata[i] != '/' ;i -- ){
                    sta_cata[i] = '\0' ;
                }
                if ( i != 0 ) sta_cata[i] = '\0' ; 
            }
        }
        else if ( islower(ope[3]) || isdigit(ope[3])) {
            for ( int i = 0 ; i < len_ope ; i ++){
                ope[i] = ope[i+3] ;
            }
            if (jud_root != 0) sta_cata[len_sta_cata] = '/' ;
            strcat(sta_cata , ope) ;
        } 
        else {
               for ( int i = 0 ; i < len_ope ; i ++){
                ope[i] = ope[i+3] ;
            }
            strcpy(sta_cata , ope) ;
        }
    }
    puts(sta_cata) ;

    return 0 ;
}
#include <stdio.h>
#include <string.h>

int main (void)
{
    char fro[52] = {'\0'} , beh[52] = {'\0'} ;
    char sta[52] = {'\0'} , temp[52] = {'\0'} ;
    int sum_fro = 0 , sum_beh = 0 , sum_ch = 0  , jud = 0 ;
    gets(sta) ;
    int len_sta = strlen(sta) ;
    for ( int i = 0 ; i < len_sta ; i ++){
        char rep = sta[i] ;
        if (rep == '(' || rep == '[' || rep == '{'){
            sum_fro ++ ;
            temp[sum_ch] = rep ;
            sum_ch ++ ;
        }
        else if (rep == ')' || rep == ']' || rep == '}')
        {
            sum_beh ++ ;
            temp[sum_ch] = rep ;
            sum_ch ++ ;
        }
    }
    if ( sum_beh != sum_fro) printf("no") ;
    else {
    for ( int i = 0 , temp_fro = 0 ; i < sum_ch ; i ++ ){
        char rep = temp[i] ;
        if ( rep == '(' || rep == '[' || rep == '{'){
            fro[temp_fro] = rep ;
            temp_fro ++ ;
        }
        else {
            char rep_fro = fro[temp_fro-1] ; 
            if(rep == ')'&& rep_fro == '(') {
                temp_fro -- ;
                jud = 1 ;
            }
            else if ( rep == ']' && rep_fro == '[') {
                temp_fro -- ;
                jud = 1 ;
            }
            else if ( rep == '}' && rep_fro == '{') {
                temp_fro -- ;
                jud = 1 ;
            }
            else {
                jud = 0 ; 
                break;
            } 
        }

    } 
    if ( jud == 1) printf("yes") ;
    else printf("no") ;
    }   
    return 0 ;
}
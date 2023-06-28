#include <stdio.h>
#include <string.h>

int main ( void )
{
    char sta[301] = {'\0'} , des[30] = {'\0'} ;
    int num[30] = {0} ;
    int n , num_sta , num_des = 0;
    gets(sta) ;
    num_sta = strlen(sta) ;
    for ( int i = 0 , k = 0 ; i < num_sta ; i ++){
        if (sta[i] == '-'){
            num_des ++ ;
            char rep = sta[i+1] ;
            int x = rep - 'a' ; 
           // printf("%d\n" , x) ;
            num[x] ++ ;
            des[x] = rep ;
        }
    } 
    for ( int i = 0 ; i < 30 ; i ++){
        if ( num[i] != 0){
            printf("-%c " , des[i]) ;
        }
    }
    if ( num_des == 0) printf("no") ;
    return 0 ;
}
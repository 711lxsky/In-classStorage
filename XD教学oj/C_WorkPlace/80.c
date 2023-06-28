#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    char mys[102] = {'\0'} ;
    char des ;
    int swi , sum_des = 0 ;
    scanf("%c %d\n" , &des , &swi) ;
    gets(mys) ;
    int len_mys = strlen(mys) ;
    if ( swi == 1){
        for ( int i = 0 ; i < len_mys ; i ++){
            if ( des == mys[i]) sum_des ++ ;
        }
    }
    else if ( swi == 0){
        if ( isupper(des)) {
            for ( int j = 0 ; j < len_mys ; j ++){ 
            mys[j] =  toupper(mys[j]) ;
            }
        }
        else if ( islower(des)){
        for ( int k = 0 ; k < len_mys ; k ++) {
        mys[k] = tolower(mys[k]) ;
        }
        }
        for ( int x = 0 ; x < len_mys ; x ++){
            if ( des == mys[x]) sum_des ++ ;
        }
    }
    printf("%d" , sum_des) ;

    return 0 ; 
}
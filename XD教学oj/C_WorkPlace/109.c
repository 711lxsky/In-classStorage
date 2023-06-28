#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char mys[102] = {'\0'} ;
    gets(mys) ;
    int len_mys = strlen(mys) ;
    char left[102] = {'\0'} , right[102] = {'\0'} ;
    char bas = mys[0] ;
    for ( int i = 1 , le = 0 , ri = 0; i < len_mys ; i ++){
        char rep = mys[i] ;
        if ( rep > bas) {
            left[le] = rep ;
            le ++ ;
        }
        else {
            right[ri] = rep ;
            ri ++ ;
        }
    }
    int len_ri = strlen(right) ;
    for ( int i = len_ri - 1 ; i >= 0 ; i --){
        for ( int j = 0 ; j < i ; j ++){
            if ( right[j] > right[j+1]) {
                char temp = right[j] ;
                right[j] = right[j+1] ;
                right[j+1] = temp ;
            }
        }
    }
    printf("%s%c%s" , left , bas , right) ;
    return 0 ;
}
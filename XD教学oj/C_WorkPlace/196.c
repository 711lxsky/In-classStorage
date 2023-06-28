#include <stdio.h>

int main ( void )
{
    char mys , ch , res , rep ;
    int num , row , line , i , j , gap ;
    scanf("%c" , &mys) ;
    row = mys - 'A' + 1 ;
    num = row ;
    line = row * 2  ;
    for( i = 1 ; i <= row ; i ++){
        for( j = 1 ; j <= line ; j ++){
            if ( j == line) res = '\n' ;
            else if ( j <= num){
                gap = i + j - num - 1;
                if ( gap < 0) res = ' ' ;
                else res = gap + 'A' ;
            }
            else {
                gap = i - j + num - 1 ;
                 if ( gap < 0) res = ' ' ;
                else res = gap + 'A' ;
            }
            putchar ( res) ;
        }
    }
    return 0 ;
}
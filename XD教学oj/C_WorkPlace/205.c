#include <stdio.h>
#include <math.h>

int main ( void )
{
    char ch ;
    int row , line , i , n , j , x ;
    scanf("%c" , &ch) ;
    scanf("%d" , &n) ;
    x = 2 * n + 1 ;
    for ( row = 1 ; row <= n ; row ++ ){
        for ( line = 1 ; line <= x ; line ++){
            if ( (row + line - n ) % 2 == 1 && abs(n - line) <= row - 1 ){
                putchar(ch) ;
            }
            else if ( line == x){
                putchar('\n') ;
            }
            else {
                putchar(' ') ;
            }
        }
    }

    return 0 ;
}
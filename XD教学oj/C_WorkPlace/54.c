#include <stdio.h>

int main (void)
{
    int num , a , b ,c , i , j , k ;
    scanf("%d" , &num) ;
    for ( a = 0 ; a <= 9 ; a ++){
        for ( b = 0; b <= 9 ; b ++){
            for ( c = 0 ; c <= 9 ; c ++){
                if (a * 100 + b * 10 + c + c * 100 + b * 10 + a == num){
                    printf("%d %d %d\n" , a ,b , c) ;
                }
            }
        }
    }
    return 0 ;
}
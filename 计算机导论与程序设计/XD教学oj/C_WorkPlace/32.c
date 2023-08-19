#include <stdio.h>

int main (void)
{
    int n , num , sum = 0 , i ;
    scanf("%d" , &num) ;
    while (num != 1){
        if (num % 2 == 0){
            num /= 2 ;
            sum ++ ;
        }
        else {
            num = num * 3 + 1 ;
            sum ++ ;
        }
    }
    printf("%d" , sum) ;

    return 0; 
}
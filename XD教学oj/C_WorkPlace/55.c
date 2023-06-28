#include <stdio.h>

int An ( int n) ;
int Bn ( int n) ;

int main ( void )
{
    int n , i ;
    float res , sum = 0;
    scanf("%d" , &n) ;
    for ( i = 1 ; i <= n ; i ++){
        res = (float) An(i) / (float) Bn(i)  ;
        //printf("%f\n" , res) ;
        sum += res ;
    }
    printf("%.2f" , sum) ;
    return 0 ;
}

int An ( int n)
{
    int  i , j , num3 ,num1 = 1 , num2 = 1 ;
    for ( i = 1 ; i <= n ; i ++){
        num3 = num1  + num2;
        num1= num2 ;
        num2 = num3 ;
    }
    return num3 ;
}

int Bn ( int n)
{
    int  i , j , num3 ,num1 = 1 , num2 = 0 ;
    for ( i = 1 ; i <= n ; i ++){
        num3 = num1  + num2;
        num2= num1 ;
        num1 = num3 ;
    }
    return num3 ;
}
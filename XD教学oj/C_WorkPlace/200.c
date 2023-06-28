#include <stdio.h>

int main ( void )
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10} ,rep[10] = {1,2,3,4,5,6,7,8,9,10} ;
    int n ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < 10-n-1 ; i ++){
    //rep[i] =  arr[i] ;
        arr[i] = arr[i+n+1] ;
    }
    for ( int j = 0 ; j < n + 1 ; j ++){
        arr[10-n-1+j] = rep[j] ;
    }
    for ( int k = 0 ; k < 10 ; k ++){
        printf("%d " , arr[k]) ;
    }
    return 0 ;
}
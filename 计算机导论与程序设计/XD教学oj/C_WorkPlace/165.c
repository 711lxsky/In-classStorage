#include <stdio.h>

int main ( void )
{
    int A[88] = { 0 } ;
    int n ; 
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d" , &A[i]) ;
    }
    int max = A[0] , lab = 0 ;
    for ( int j = 0 ; j < n ; j ++){
        if ( max < A[j]) {
            max = A[j] ;
            lab = j ;
        }
    }
    printf("%d %d %d" , n , max , lab) ;
    return 0 ;
}
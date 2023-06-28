#include <stdio.h>

void change( int *p , int x) ;
int main ( void )
{
    int num[22] = {0} ;
    int n ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d" , &num[i]) ;
    }
    change ( num , n) ;
    for ( int j = 0 ; j < n ; j ++){
        printf("%d " , num[j]) ;
    }

    return 0 ;
}

void change ( int *p , int n)
{
    int * min = p , *max = p ;
    for ( int i = 0 ; i < n ; i ++){
        if ( *min > * ( p + i)) min =&*( p + i );
        if ( *max < * ( p + i)) max =&*( p + i );
    }
    int rep = *max ;
    *max = *min ;
    *min = rep ;

}
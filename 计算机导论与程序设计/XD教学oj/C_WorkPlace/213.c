#include <stdio.h>

void palce (  int (*des)[7] ,  int *num  , int m , int n) ;
int main (void)
{
    int m , n ;
    int num[50] = {0} ;
    scanf("%d %d" , &m , &n) ;
    for ( int i = 0 ; i < m * n ; i ++){
        scanf("%d" , &num[i]) ;
    }
    for ( int i = m * n - 1 ; i >= 0 ; i --){
        for ( int j = 0 ; j < i ; j ++){
            if ( num[j] > num[j+1]) {
                int rep = num[j] ;
                num[j] = num[j+1] ;
                num[j+1] = rep ;
            }
        }
    }
    int des[7][7] = {0} ;
    palce( des , num , m , n) ;
    for ( int i = 0 ; i < m ; i ++){
        for ( int j = 0 ; j < n ; j ++){
            printf("%3d" , des[i][j]) ;
        }
        printf("\n") ;
    }

}

void palce (  int (*des)[7] ,  int *num  , int m , int n) 
{
    int x = 0 ;
    for ( int i = 0 ; i < m ; i ++){
        if ( i % 2 == 0 ) {
            for ( int j = n - 1 ; j >= 0 ; j --){
                *( * ( des + i) + j) = * ( num + x) ;
                x ++ ;
            }
        }
        else {
            for ( int j = 0 ; j < n ; j ++){
                *( * ( des + i) + j) = * ( num + x) ;
                x ++ ;
            }
        }
    }
}
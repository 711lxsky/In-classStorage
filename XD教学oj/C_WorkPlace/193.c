#include <stdio.h>

int main (void)
{
    double gra[11] = {0} ;
    int n ;
    double max , min ,sum = 0 ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%lf" , &gra[i]) ;
    }
    max = min = gra[0] ;
    for ( int j = 0 ; j < n ; j ++){
        sum += gra[j] ;
        if ( max - gra[j] < 0) max = gra[j] ;
        if ( min - gra[j] > 0 ) min = gra[j] ;
    }
    sum -= max + min ;
    double des = sum / (n-2) ;
    printf("%.2lf" , des) ;
    return 0 ;
}
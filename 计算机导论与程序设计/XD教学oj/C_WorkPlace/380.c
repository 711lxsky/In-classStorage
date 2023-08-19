#include <stdio.h>
#include <math.h>

void ini_val ( int , int * ) ;
int isprime ( int ) ;

int main (void)
{
    int val[5] ;
    int n ;
    scanf("%d" , &n) ;
    ini_val( n , val) ;
    //for ( int i = 0 ; i < 5 ; i ++) printf("%d " , val[i]) ;
   int min_gap = 1000000 ;
   for ( int i = 0 ; i < 5 ; i ++){
        int sum_a = 0 , sum_b = 0 ;
        for ( int j = 0 ; j < 5 ; j ++){
            if ( i != j) sum_a += val[j] ;
        }
        sum_b += val[i] ;
        int now_gap = abs ( sum_a - sum_b) ;
        if ( min_gap > now_gap) min_gap = now_gap ;
   }
   for ( int i = 0 ; i < 5 ; i ++){
    for ( int j = i + 1 ; j < 5 ; j ++ ){
        int sum_a = 0 , sum_b = 0 ;
        for ( int k = 0 ; k < 5 ; k ++){
            if ( k != i && k != j) sum_b += val[k] ;
        }
        sum_a += val[i] + val[j] ;
        int now_gap = abs ( sum_a - sum_b) ;
        if ( min_gap > now_gap) min_gap = now_gap ;
    }
   }
    printf("%d" , min_gap) ;
}

void ini_val ( int n , int * val)
{
    int num = 0 ;
    for ( int i = 2 ; num < n + 4 ; i ++){
        if ( isprime(i)) {
            if ( num >= n -1 ) val[num+1-n] = i ;  
            num ++ ;
        }

    }
}

int isprime ( int num )
{
    int jud = 1 ;
    for ( int i = 2 ; i <= sqrt(num) ; i ++){
        if ( 0 == num % i) {
            jud = 0 ;
            break;
        }
    }
    return jud ;
}
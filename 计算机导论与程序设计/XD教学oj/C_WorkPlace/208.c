#include <stdio.h>

void sort ( int *p , int n) ;
int compare ( int x , int y);
int main ( void )
{
    int num[22] = { 0 } ;
    int n ; 
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d" , &num[i]) ;
    }
    sort(num , n) ;
    for ( int i = 0 ; i < n ; i ++){
        printf("%d " , num[i]) ;
        if ( num[i] % 2 != 0 && num[i+1] % 2 == 0) 
        printf("  ")  ;
    }
    return 0 ;
}

void sort ( int *p , int n)
{
    int j , i , k ;
      for (  i = 0 ; i < n  ; i ++){
        for (  j = i + 1 , k = i ; j < n ; j ++){
            int num1 = *(p + k ) ;
            int num2 = *(p + j ) ;
            if ( compare( num1 , num2) > 0) k=j ;
        }
        if ( k != i ){
            int rep = * ( p + i) ;
            *( p + i) = * ( p + k) ;
            *( p + k ) = rep ; 
        }
      }
}

int compare ( int x , int y)
{
    int jud = 0 ;
    if ( x % 2 == 0 && y % 2 != 0) 
    jud = 2 ;
    else if ( x % 2 != 0 && y % 2== 0 ) 
    jud = -2 ;
    else {
    if ( x > y)  jud = 1 ;
    else if ( x < y ) jud = -1 ;
    else jud = 0 ; }
    
    return jud ;
}
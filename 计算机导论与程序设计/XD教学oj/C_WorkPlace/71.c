#include <stdio.h>

int main (void)
{
    int num[22][22] = { 0 } , jud[52] = { 0 } ;
    int n , m , t , k ,lab_k_row = -1 , lab_k_line = -1 ;
    scanf("%d %d %d %d" , &n , &m , &t , &k) ;
    for(int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < m ; j ++){
            scanf("%d" , &num[i][j]) ;
            if( num[i][j] == k && lab_k_line == -1){
                lab_k_row = i ;
                lab_k_line = j ;
            }
        }
    }
    if ( n == 1 ){
          int a , b ;
    for( a = lab_k_row , b = lab_k_line ; num[a][b] == k ; b ++){   
                    int rep3 = num[a][b-1] ;
                    int rep4 = num[a][b+1] ;
                    jud[rep3] = jud[rep4] =1 ;  
    }
    }
    else {
    int a , b ;
    for( a = lab_k_row , b = lab_k_line ; num[a][b] == k ; a ++){
        for ( b = lab_k_line ; num[a][b] == k ; b ++){
               if ( a == 0 ){
                if ( b == 0){
                    int rep4 = num[a][b+1] ;
                    int rep2 = num[a+1][b] ;
                    jud[rep4] = 1 ;
                    jud[rep2] = 1 ;
                }
                else if ( b == m - 1){
                    int rep3 = num[a][b-1] ;
                    int rep2 = num[a+1][b] ;
                    jud[rep3] = 1 ;
                    jud[rep2] = 1 ;
                }
                else {
                    int rep2 = num[a+1][b] ;
                    int rep3 = num[a][b-1] ;
                    int rep4 = num[a][b+1] ;
                jud[rep2] = jud[rep3] = jud[rep4] =1 ;
                }
               }
               else if ( a == n - 1){
                if ( b == 0){
                     int rep1 = num[a-1][b] ;
                    int rep4 = num[a][b+1] ;
                    jud[rep1]  = jud[rep4] =1 ;
                }
                else if ( b == m - 1){
                     int rep1 = num[a-1][b] ;
                    int rep3 = num[a][b-1] ;
                    jud[rep1] =jud[rep3] =1 ;
                }
                else {
                     int rep1 = num[a-1][b] ;
                    int rep3 = num[a][b-1] ;
                    int rep4 = num[a][b+1] ;
                    jud[rep1]=  jud[rep3] = jud[rep4] =1 ;
                }
               }
               else {
                if ( b == 0){
                     int rep1 = num[a-1][b] ;
                    int rep2 = num[a+1][b] ;
                    int rep4 = num[a][b+1] ;
                    jud[rep1] =jud[rep2] = jud[rep4] =1 ;
                }
                else if ( b == m - 1 ){
                     int rep1 = num[a-1][b] ;
                    int rep2 = num[a+1][b] ;
                    int rep3 = num[a][b-1] ;
                    jud[rep1] =jud[rep2] = jud[rep3] =1 ;
                }
                else {
                     int rep1 = num[a-1][b] ;
                    int rep2 = num[a+1][b] ;
                    int rep3 = num[a][b-1] ;
                    int rep4 = num[a][b+1] ;
                    jud[rep1] =jud[rep2] = jud[rep3] = jud[rep4] =1 ;
                }
               }
           }
           b = lab_k_line ;
        }
    }

        int sum = 0 ;
        for ( int i = 0 ; i < 52 ; i++){
            sum += jud[i] ;
        }
        if ( jud[k] == 1) sum -- ;
        printf("%d" , sum) ;

        return 0 ;
    }

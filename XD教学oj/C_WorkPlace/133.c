#include <stdio.h>

int main (void)
{
	int num1[1002] = {0} , num2[1002] = {0} ;
	int ind1[1002] = {0} , ind2[1002] = {0} ;
	int n , m , op ;
	scanf("%d %d %d" , &n , &m , &op) ;

	 for ( int i = 0  , j =0 , k = 0 ; i <  2 * n ; i ++){
        if ( i % 2 == 0) {
            scanf("%d" , &num1[j]) ;
            j ++ ;}
        else {
            scanf("%d" , &ind1[k]) ;
            k ++ ;
        }
    }

    for ( int i = 0  , j =0 , k = 0 ; i <  2 * m ; i ++){
        if ( i % 2 == 0) {
            scanf("%d" , &num2[j]) ;
            j ++ ;}
        else {
            scanf("%d" , &ind2[k]) ;
            k ++ ;
        }
    }

	int max_ind = ind1[n-1] > ind2[m-1] ? ind1[n-1] : ind2[m-1] ;
	int min_ind = ind1[0] < ind2[0] ? ind1[0] : ind2[0] ;
	int max_wei = n > m ? n : m ;
	int jud = 0 ;

	for ( int i = min_ind ; i <= max_ind ; i ++){
		int des_num = 0 ;
		for ( int j = 0 ; j <= max_wei ; j ++ ){
			if ( ind1[j] == i) des_num += num1[j] ;
			if ( ind2[j] == i) if ( op == 0) des_num += num2[j] ;
								else des_num -= num2[j] ;
		}
		
		if ( des_num != 0 ) {
			jud ++ ;
			if ( jud == 1 ) {
				if ( i == 0 ) printf("%d" , des_num) ;

				else if ( i == 1 ) {
					if ( des_num == 1 ) printf("x") ;
					else if ( des_num == -1) printf("-x") ;
					else printf("%dx" , des_num) ;

				}
				else {
					if ( des_num == 1 ) printf("x^%d" , i) ;
					else if ( des_num == -1 ) printf("-x^%d" , i) ;
					else printf("%dx^%d" , des_num , i) ;
				}
			}
			else {
				if ( i == 1 ) {
					if ( des_num > 0 ) {
					if ( des_num == 1 ) printf("+x") ;
					else printf("+%dx" , des_num ) ;
				}
					else { 
					if ( des_num == -1)  printf("-x") ;
					else  printf("%dx" , des_num) ;
				}
				}
				else {
					if ( des_num > 0 ){
					if ( des_num == 1 ) printf("+x^%d" , i) ;
					else printf("+%dx^%d" , des_num , i ) ;
				}
					else {
					   if ( des_num == -1 ) printf("-x^%d" , i) ;
					   else  printf("%dx^%d" , des_num , i) ;
				}
			}
		}
		
	}
}
}
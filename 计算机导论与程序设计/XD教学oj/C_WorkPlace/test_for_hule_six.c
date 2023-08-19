#include<stdio.h>
 
int compactlntegers(int x , int y[]) ; 
int main()
{
	int n , num[1000] = {0} , j;
	scanf("%d" , &n) ;
	for(int i = 0 ; i < n ; i++)
	scanf("%d", &num[i] ) ;
	j = compactlntegers(n , num) ;
	for(int i = 0 ; i < n ; i++)
	{
		if(num[i] != 0 )
		  printf("%d " , num[i]) ;
	}
	printf("\n\n") ;
	printf("%d" , j) ;
	return 0 ;
}
int compactlntegers(int x , int y[])
{
	int sum = 0 ;
	for ( int i = x - 1 ; i >= 0 ; i --){
		for ( int j = 0 ; j < i ; j ++){
			if ( y[j] == 0 ){
				y[j] = y[j+1] ;
				y[j+1] = 0 ;
			}
		}
	}
	for ( int k = 0 ; k < x ; k ++){
		if ( y[k]  != 0 ) sum ++ ;
	}
	return(sum) ;
}
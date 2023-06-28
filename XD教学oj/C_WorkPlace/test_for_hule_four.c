#include<stdio.h>
int main()
{
	int num[3][4] = {0} ;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			scanf("%d" , &num[i][j]) ;
		}
	}
	int max = num[0][0] , t = 0 ;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			if(num[i][j] < 0){
				 t = (-1)*(num[i][j]) ;
				 num[i][j] = t ;
			}
			if(max < num[i][j]){
				max = num[i][j] ;
				}	
		}
	}
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			if(num[i][j] == max){
				printf("%d %d %d" , max , i+1 , j+1);
				break ;
			}
		}break ;
	}
	return 0 ;
 }

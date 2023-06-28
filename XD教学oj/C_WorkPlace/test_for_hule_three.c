#include<stdio.h>

int main (void)
{
	int num[102][102] = { 0 } ;
	int n ;
	scanf("%d" , &n) ;
	for ( int i = 0 ; i < n ; i ++){
		for ( int j = 0 ; j < n ; j ++){
			scanf("%d" , &num[i][j]) ;
		}
	}
	int max_row = 0 , min_row = 0 , max = num[0][0] , min = num[0][0] ;  
	// 初始化最大值最小值，和行数标签值
	for ( int row = 0 ; row < n ; row ++){
		for ( int line = 0 ; line < n ; line ++){
			int temp = num[row][line] ;
			if ( max < temp ){
				max = temp ;
				max_row = row ;
			}
			if ( min > temp ){
				min = temp ;
				min_row = row ;
			}                
			// 两个if来标记最大数和最小数所在的行数
		}
	}
	if ( max_row != min_row){
	for ( int k = 0 ; k < n ; k ++){
		int *p1 = &num[max_row][k] ;
		int *p2 = &num[min_row][k] ;
		int rep = *p1 ;
		*p1 = *p2 ;
		*p2 = rep ;
	}  /*   使用指针来进行值的互换，可以看到这里需要6行代码，但一般的双值转换只需要3行
	      且使用指针级易引发危险
	      所以我觉得在工作量不大、问题简单的情况下不使用指针为妙*/
	}
	for ( int i = 0 ; i < n ; i ++){
		for ( int j = 0 ; j < n ; j ++){
			printf("%d " , num[i][j]) ;
			if ( j == n - 1) printf("\n") ;
		}
	}

	return 0 ;
}
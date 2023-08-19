// 函数测试
	 
	 #include <stdio.h>
	 
	 int Odd (int) ;
	 
	 int main ( void)
	 {
	 	int  i , n ,num  , sum_odd = 0 , sum_num = 0;
	 	scanf("%d" ,&n) ;
	 	//scanf("%d" , &num) ;
	 	for ( i=1 ; i <= n ; i ++) {
	 		scanf("%d" , &num) ;
	   sum_odd += Odd(num) ;
       sum_num += num ;
 }
	 	printf("%d  | %d" , sum_odd , sum_num) ;
	 }
	 
	 int Odd ( int x) 
	 {
	 	int jud ;
	 	if ( x % 2 == 0)
	 	{
	 		jud = 0 ;
		 }
		 else {
		 	jud = 1 ;
		 }
		 
		 return jud ;
	 }
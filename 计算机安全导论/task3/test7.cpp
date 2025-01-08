#include <stdio.h>

main( )

{
	
	int num=2023;
	
	printf("Before: num = %d\n", num);
	
	printf("%.10d %n\n", num, &num);
	
	printf("After: num = %d\n", num);
	
}

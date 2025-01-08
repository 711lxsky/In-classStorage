# include <stdio.h>

int main(){
	
	int num = 0;
	
	printf("num = %d\n", num);
	
	printf("There is a string: abcdefghijklmn%n\n", &num);
	
	printf("num = %d\n", num);
	
	return 0;
	
}


#include<stdio.h>

int main()
{
	char a[100] ={'\0'};
	int c=0;
	char x;
	gets(a);
	for(int i=0;i<100;i++)
	{
		int b[100]={0};
		b[i]=a[i]+0;
		c=c+b[i];
	}
	x=c;
	c=c%256;
	printf("%d %d",c,x);
	return 0;
}

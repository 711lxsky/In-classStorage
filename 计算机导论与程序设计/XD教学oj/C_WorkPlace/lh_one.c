#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char *compress(char *src)
{
	char *b=(char *)malloc(sizeof(char)*100);
	int i=0,j=0,num=1;
	int len=strlen(src) ;
    //src[len] = '\0' ;
	for(i=0;i<len;i++)
	{
		num=1;
		b[j++]=src[i];
		
		while(src[i]==src[i+1])
		{
			i++;
			num++;
		}
		if(src[i]!=src[i+1])
		{
			if(num)
	    	{
	    		continue;
	    	}
	    	else 
	    	{
	    		if(num<10)
	    		{
	    			b[j++]=num+'0';
				}
				else
				{
					b[j++]=num/10+'0';
		
		        	b[j++]=num%10+'0';
				}
			}
	    
		}
		
		
	}
	b[j]='\0';
	return b;
}
int main(int argc, char *argv[]) {
	char src[100];
	gets(src);	
	char *ps=compress(src);
	puts(ps);
	free(ps) ;
	return 0;
}

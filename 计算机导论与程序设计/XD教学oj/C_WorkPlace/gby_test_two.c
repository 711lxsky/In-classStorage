#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000]={0},b[1000]={0};
	gets(a);
	gets(b);
	int s1=strlen(a),s2=strlen(b);
	double f=0;
	int cnt=0;
	strlwr(a);
	strlwr(b);
	if(s1>=s2)
	{
		int i,j=0;
		for(i=0;i<s1;i++)
		{
			j=0;
			if(a[i]==b[j])
			{
			
			for(j=0;j<s2;j++)
			{
				if(a[i+j]!=b[j])
				{
				
					if(cnt<j)
					{
					cnt=j;}
					i+=j;
					break;
						if(i+j>=s1)
					break;
				}
					if(j==s2-1&&a[i+j]==b[j])
					{
					cnt=j+1;
					i+=j;}
				
			}
			}
		}
		f=cnt*2.0/(s1+s2);
	}
	else
	{
		int i,j=0;
		for(i=0;i<s2;i++)
		{
			j=0;
			if(b[i]==a[j])
			{
			
			for(j=0;j<s2;j++)
			{
				if(b[i+j]!=a[j])
				{
					if(cnt<j)
					cnt=j;
					i+=j;
					break;
					
					if(i+j>=s2)
					break;
				}
				if(j==s1-1&&b[i+j]==a[j])
					{
					cnt=j+1;
					i+=j;}
				
			}
			}
		}
		f=cnt*2.0/((s1+s2)*1.0);
	}
	printf("%.3f",f);
}
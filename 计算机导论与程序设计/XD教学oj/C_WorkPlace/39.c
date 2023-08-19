#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&m,&n);
	int i,t,p,q,a[256][256];
	int b[70000],temp;
	for(i=0;i<n;i++)
	{
		for(t=0;t<m;t++)
		{
			scanf("%d",&a[i][t]);
		}
	}
	p=0;
	for(i=0;i<n;i++)
	{
		for(t=0;t<m;t++)
		{
			b[p]=a[i][t];
			p++;
		}
	}
	for(i=0;i<p-1;i++)
	{
		for(t=0;t<p-1-i;t++)
		{
			if(b[t]>b[t+1])
			{
				temp=b[t];
				b[t]=b[t+1];
				b[t+1]=temp;
				
			}
		}
	}
	
	int count=1;
	for(i=0;i<p;i++)
	{
		while(b[i]==b[i+1]){
			count++;
			 i++;
		}
		printf("%d %d\n",b[i],count);
		count=1;
		
	}
	
}

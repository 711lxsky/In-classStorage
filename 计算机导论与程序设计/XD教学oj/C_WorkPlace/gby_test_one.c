#include<stdio.h>
#include<string.h>
int main()
{
	char ch[100][100]={0},ch1[100][100]={0};
	int i,j,l,m,n,k;
	char st[100]={0},st1[100]={0};
	scanf("%s",st);
	scanf("%d",&k);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",ch[i]);
		for(int u=0;u<strlen(ch[i]);u++)
		{
			ch1[i][u]=ch[i][u];
		}
	}
	if(k==1)
	{
		temp:
	for(i=0;i<n;i++)
	{
		for(j=0;j<strlen(ch[i]);j++)
		{
			m=0;
			int cnt=0;
			if(ch[i][j]==st[m])
			{
				cnt=1;
				for(l=j;l<strlen(st);l++)
				{
					if(ch[i][l]!=st[m++])
					{cnt=0;
					break;
					}
				}
				 if(cnt==1)
				 {
				 	puts(ch1[i]);
				 	break;
				 }
			}
		}
	}
	return 0;
}
	else if(k==0)
	{
		strlwr(st);
		for(i=0;i<n;i++)
		{
			strlwr(ch[i]);
		}
		goto  temp;
	}
	
 } 
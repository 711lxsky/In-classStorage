#include <stdio.h>
int dp[205][20005]={0};
int main(){
	int v_w[205]={0};
	int n,i,j,sum=0;
	//输入物品价值、容量、顺便计算一下总价值
	scanf("%d",&n);
	for(i=1;i<=n;i++){    
		scanf("%d",&v_w[i]);
		sum+=v_w[i];
	}
	
	for(i=1;i<=n;i++){//背包的算法
		for(j=1;j<=(sum/2);j++){
			if(v_w[i]>j)dp[i][j]=dp[i-1][j];
			else dp[i][j]=(dp[i-1][j]>dp[i-1][j-v_w[i]]+v_w[i])?dp[i-1][j]:dp[i-1][j-v_w[i]]+v_w[i];
			//printf("dp[%d][%d]:%d ",i,j,dp[i][j]);
		}
	//	printf("\\n");
	}//这两个printf语句我还保留在这里，是因为它可以打印出非常整齐的表格（滑稽
	if((sum-2*dp[n][sum/2])>0)printf("%d",(sum-2*dp[n][sum/2]));
	else printf("%d",-(sum-2*dp[n][sum/2]));//绝对值问题
	return 0;
}
 
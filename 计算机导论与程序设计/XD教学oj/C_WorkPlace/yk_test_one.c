#include<stdio.h>
int main(){
	int w[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int n,i,j,k[100],sum[100]={0},d[100][20],flag=0;
	char c[100];
	char m[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	scanf("%d",&n);
	for(i=0;i<n;i++) {
	for(j=0;j<17;j++){
		scanf("%d",&d[i][j]);
		sum[i]+=d[i][j]*w[j];
	    
}scanf("%c",&c[i]);
}
	for(i=0;i<n;i++) k[i]=sum[i]%11;
	for(i=0;i<n;i++) {
		if(m[k[i]]==c[i]) flag++;
	}
	if(flag==n) printf("All passed");
	else{
	for(i=0;i<n;i++){
		if(m[k[i]]!=c[i]){
			for(j=0;j<17;j++){
				printf("%d",d[i][j]);
				printf("%c\n",c[i]);
			}   
		}
	}
	}
	return 0;
} 
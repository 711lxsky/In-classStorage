#include <stdio.h>
#include <math.h>
int n,num=0,sum=0;
int book[1000]; //#用于记录符号
int main(){
	void dfs( int step);
	scanf("%d",&n);
	dfs(1);
	printf("%d",num);
} //#dfs全排列枚举book
void dfs( int step){
	int tail,j,i;
	if(step==n){
		int k;
		int a[1000]={0};
		a[1]=1;
        tail=2;
		for(k=1;k<n;k++){
			 switch(book[k]){
			 	case 1: a[tail++]=k+1;break;//#加号
			 	case 2: a[tail++]=-(k+1);break;//#减号
			 	case 3: a[tail-1]=(abs(a[tail-1])*10+k+1)*(a[tail-1]/abs(a[tail-1]));break;//#空格情况
			 }
		}
		sum=0;
		for(j=1;j<tail;j++){
			sum+=a[j];
		}
		if(sum==0) num++;
		return;
	}
	else{
		for(i=1;i<=3;i++){
		book[step]=i;
		dfs(step+1);
	}}
    return;
}

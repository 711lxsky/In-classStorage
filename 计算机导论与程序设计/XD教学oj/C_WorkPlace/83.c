/*#include <stdio.h>

int main ( void )
{
    int squ[102][102] = { 0 } ;
    int n , m ;
    scanf("%d %d" , &n , &m) ;
    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < m ; j ++){
            scanf("%d" , &squ[i][j]) ;
        }
    }
        for ( int line = 0 ; line < m ; line ++ ){
            for ( int row = n - 1 ; row >= 0 ; row --){
                printf("%d " , squ[row][line]) ;
                if ( row == 0 ) printf("\n") ;
        }
        }
    return 0 ;
}*/

#include<stdio.h>
int main(){
	int m,n,i,j;
	int arr[52][52]={0};
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(j=0;j<n;j++){
		for(i=m-1;i>=0;i--){
			printf("%d ",arr[i][j]);
			if(i==0){
				printf("\n");
			}
		}
	}
	return 0;
} 
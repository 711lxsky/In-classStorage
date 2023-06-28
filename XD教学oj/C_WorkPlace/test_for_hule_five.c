#include<stdio.h>

int main()
{
	int n , b , t = 0 ;
	int num[102] ; 
	scanf("%d %d" , &n , &b) ;
	for(int i = 0 ; i < n ; i++)
		scanf("%d" , &num[i]) ;
	for(int i = 0 ; i < n - 1 ; i++){
		for(int j = 0 ; j < n - 1 - i ; j++)
		if(num[j] > num[j + 1]){
			t = num[j] ;
			num[j] = num[j + 1] ;
			num[j + 1] = t ;
		}
	}
	for(int i = 0 ; i < n ; i++){
        if ( num[i] % b == 0) ;
		else {
            int rep = num[i] ;
            if ( rep < 65 && rep > 90 ) printf("%d " , rep) ;
            else printf("%c " , rep) ;
        }
    }

	return 0 ;
}
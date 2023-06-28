#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
   int rate[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2} ;
   char M[11] ={'1','0','X','9','8','7','6','5','4','3','2'} ;
   char card[101][19] ={'\0'} ;
   int n ;
   scanf("%d" , &n) ;
   for(int i = 0 ; i < n ; i ++){
    scanf("%s" , card[i]) ;
   }
   int jud = 1 ;
   int num[101] = {0} ;
   for(int i = 0 ;i < n ; i ++){
    int thispass = 1 ;
    for(int j = 0 ; j < 17 ; j ++){
        if( ! isdigit(card[i][j])){
            printf("%s\n" ,card[i] ) ;
            jud = 0 ;
            thispass = 0 ;
            break;
        }
        else {
            num[i] += (card[i][j] - '0') * rate[j] ;
        }
        }
        if (thispass == 0) 
        {
            continue; 
        }
        
         int mod = num[i] % 11 ;
        if(M[mod] != card[i][17]) {
            printf("%s\n" , card[i]) ;
            jud = 0 ;
    }
   }
   if(jud) printf("All passed") ;
   return 0 ;
}
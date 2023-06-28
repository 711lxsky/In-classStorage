#include <stdio.h>
#include <string.h>
//#include <locale.h> 
//#include <wchar.h> 
int main (void)
{
    char cou[102][202] ;
    //setlocale(LC_ALL,"Chs") ;
    int num[102] = {0} ;
    int n ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
         scanf("%s" , cou[i]) ;
         scanf("%d" , &num[i]) ;
    }
    for ( int i = 0 , j = 0; i < n ; i ++){
        int max = num[0] ;
        int lab = 0 ;
        for ( j = 0 ; j < n ; j ++){
             if ( max < num[j]) {
                max = num[j] ;
                lab = j ;
             }
        }
        printf("%s" , cou[lab]) ;
        printf("  %d\n" , num[lab]) ;
        num[lab] = -1 ;
    }
    return 0 ; 

}
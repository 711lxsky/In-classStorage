#include <stdio.h>
#include <string.h>

int main ( void )
{
    char ch[1002][1002] = {'\0'} , end[] = "***end***" ;
    int num[1002] = {0} ;
    int i = 0 , sum_ch = 0 ;
    while (gets(ch[i] ) ){
        if(! strcmp(end , ch[i])) break ;
        num[i] = strlen(ch[i]) ;
        i ++ ;
        sum_ch ++ ;
    }
    int max = -1 , lab = 0 ;
    for ( int j = 0 ; j < sum_ch ; j ++ ){
          if ( max < num[j]) {
            max = num[j] ;
            lab = j ;
          }
    }
    printf("%d\n%s" , max , ch[lab]) ;
    return 0 ;
}
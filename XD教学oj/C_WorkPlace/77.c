#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
      int num[5] = {0} ;
      int res = 0 ;
      char ch , ope ;
      char mys[4][15] = {'\0'} ;
      for ( int i = 0 ; i < 3 ; i ++){
        scanf("%s" , mys[i]) ;
      }
      for ( int i = 0 , k = 0 ; i < 3 ; i ++){
        char rep = mys[i][0] ;
        if ( isdigit( rep )) {
            int len = strlen(mys[i]) ;
            int sum = 0 ;
            for ( int j = 0 ; j < len ; j ++){
                sum *= 10 ;
             sum += mys[i][j] - '0' ;
            }
            num[k] = sum ;
            k ++ ;
        }
        else ope = rep ;
      }
      int x = num[0] , y = num[1] ;
      switch (ope)
      {
    case '+' :
        res = x + y ;
        break;
    case '-' :
        res = x - y ;
        break;
    case '*' :
        res = x * y ;      
        break;
    case '/' :
        res = x / y ;
        break;
    case '%' :
        res= x % y ;
        break;
   default:
        break;
      }
      printf("%d" , res) ;
      return 0 ;
}
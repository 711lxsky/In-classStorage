#include <stdio.h>

int function ( int a ,int b )
{
    int sum = 0  ,  i , j , k , num ,rep , tem;
    if ( a > b ){
        rep = a ;
        a = b ;
        b = rep ;
    }
    if ( b < 100) ;
    else {
        if ( a < 100)  a = 100 ;
        for ( i = a ; i <= b ; i ++){
            rep = i ;
            num = 0 ;
            while(rep != 0){
                rep /= 10 ;
                num ++ ;   
                 }
            rep = i ;
 int mys = 0 ;
            while ( rep !=0 ){
          int  tem1 = 1;
          int tem2 = 1 ;
                tem1 = rep % 10 ;
                rep /= 10 ;

                for ( k = 1 ; k <= num ; k ++ ){
                    tem2 *= tem1 ;
                }

                mys += tem2 ;
            }
            if ( mys == i) sum ++ ;
        }
    }
    return sum ;
}
int main ( void )
{
    int a , b , res;
    scanf("%d %d" , &a , &b) ;
     res = function(a , b);
     printf("%d" , res) ;

     return 0 ;
}
#include <stdio.h>
#include <math.h>

int main ( void )
{
    char mys[50] = {'\0'} ;
    int num = 0  , res = 0 ;
    gets(mys) ;
    for ( int i = 49 ;   i >= 0 ; i --){
        char rep = mys[i] ;
        if (( rep >= 'A' && rep <= 'F') || (rep >= 'a' &&rep<= 'f' ) || (rep >= '0' && rep <= '9')){
            int x = 0 ;
            /*if ( rep == 'A' || rep == 'a')  x= 10 ;
            else if ( rep =='B' || rep == 'b') x = 11 ;
            else if ( rep == 'C' || rep == 'c') x = 12 ;
            else if ( rep == 'D' || rep == 'd' ) x = 13 ;
            else if ( rep == 'E' || rep == 'e') x = 14 ;
            else if ( rep == 'f' || rep == 'F') x = 15 ; */
            switch (rep){
                case 'A' :
                case 'a' : x = 10 ; break ;
                case 'B' :
                case 'b' : x = 11 ;break ;
                case 'C' :
                case 'c' :x = 12 ; break ;
                case 'D' :
                case 'd' : x = 13 ; break ;
                case 'E' :
                case 'e' : x = 14 ; break ;
                case 'F' : 
                case 'f' : x = 15 ; break ;
                case '9' : x = 9 ; break;
                case '8' : x = 8 ;break;
                case '7' : x = 7 ; break;
                case '6' : x = 6 ;break;
                case '5' : x = 5 ;break;
                case '4' : x = 4 ;break;
                case '3' : x = 3 ;break;
                case '2' : x = 2 ; break;
                case '1' : x = 1 ;break;
                case '0' : x = 0 ;break;

            }
            res += x * pow(16,num) ;
            num ++ ;
        }
    }
    printf("%d" , res) ; 
}
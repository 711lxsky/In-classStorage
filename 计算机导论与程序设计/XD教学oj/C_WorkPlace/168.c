#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main (void)
{
    char ch1[102] = {'\0'} , ch2[102] = {'\0'} ;
    gets(ch1) ;
    gets(ch2) ;
    int rate_same[102][102] = {0} ;
    int len_ch1 = strlen(ch1) , len_ch2 = strlen(ch2) ;
    for ( int i = 0 ; i < len_ch1 ; i ++){
        for ( int j = 0 ; j < len_ch2 ; j ++){
            char rep1 = ch1[i] ;
            char rep2 = ch2[j] ;
            if ( rep1 == rep2 || abs(rep1 - rep2) == 32){
                if ( i != 0 && j != 0) 
                rate_same[i][j] = rate_same[i-1][j-1] + 1 ;
                else {
                    rate_same[i][j] = 1 ;
                }
            }
        }
    }
    int max_same = 0 ; 
    for ( int i = 0 ; i < len_ch1 ; i ++){
        for ( int j = 0 ; j < len_ch2 ; j ++){
           if ( max_same < rate_same[i][j]) 
            max_same = rate_same[i][j] ;
        }
    }
    double same = 2.0 * max_same / (len_ch1+len_ch2) ;

    printf("%.3lf" ,same) ;

    return 0 ; 
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    char sen[101] = {'\0'} , sta_word[11] = {'\0'} , word[11] = {'\0'} ;
    char change_sen[101][11] = {'\0'} ;
    gets(sen) ;
    gets(word) ;
    int len_sen = strlen(sen) ;
    int len_word = strlen(word) ;
    for ( int i = 0 ; i < len_sen ; i ++){
        sen[i] = tolower(sen[i]) ;
    }
    for ( int j = 0 ; j < len_word ; j ++){
        sta_word[j] = word[j] ;
        sen[j] = tolower(word[j]) ;
    }
    int row = 0 , line = 0 ;
    for ( int i = 0  ; i < len_sen ; i ++){
        if ( sen[i] != ' '){
            change_sen[row][line] = sen[i] ;
            line ++ ;
        }
        else {
            row ++ ;
            line = 0 ;
        }
    }
    int sum = 0 ;
    for ( int i = 0 ; i <= row ; i ++) {
        if (! strcmp(change_sen[i] , word)) sum ++ ;
    }
    printf("%s %d" , sta_word , sum) ;

}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *compress(char *src) ;
int main(void){
    char src[100] ;
    scanf("%s" , src) ;
    char *ps = compress(src) ;
    puts(ps) ;
    return 0 ;
}

char *compress(char *src){
    int len = strlen(src) ;
    char *res = (char *)malloc(sizeof(char) *100) ;
    int sum = 1 ;
    src[len] = '!' ;
    int j = 0 ;
    for(int i = 0 ; i < len  ; i ++){
        //int sum = 0 ;
        if(src[i] == src[i+1]){
            sum ++ ;
        }
        else {
            if (sum >= 3) {
            res[j++] = src[i];
            //j ++ ;
            if (sum >= 10) {
                res[j++] = (sum / 10) - 0 + '0';
            }
            res[j++] = sum % 10 - 0 + '0';
            sum = 1;
        }
            else {
                for(int k = 0 ; k < sum ; k++){
                    res[j++] = src[i] ;
                }
                sum = 1 ;
            }
        }
    }
    //printf("%d" , j) ;
    res[j] = '\0' ;
    //printf("%d\n" , strlen(res)) ;
    //puts(res) ;
    return res ;
}
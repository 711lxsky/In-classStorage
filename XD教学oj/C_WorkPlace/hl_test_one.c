#include "string.h"
#include <stdio.h>

int main(void){
    char *p[10] = {
        "char","aabdfg","dcdbe","abbd","cd"
    };
    printf("%d\n",sizeof(char));
    for(int i = 0 ; i < 10 ; i ++){
        printf("%d: %s  ok\n",i,p[i]);
        
    }
    printf("%s -- %d\n",p[4], sizeof(p[4]));
    int len = strlen(p[4]);
    printf("len :%d  ", len);
    for(int i = 0 ; i < len ; i ++){
        printf("%c ", p[4][i]);
    }
    printf("+++ size: %d" , sizeof(char*));
}
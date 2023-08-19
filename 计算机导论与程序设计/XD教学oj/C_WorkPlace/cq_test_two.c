#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
    char *name , gender ;
    int score ;
};

int main()
{
    struct stu a={NULL,'m',290} , b ;
    a.name = (char *)malloc(10);
    strcpy(a.name, "Zhao") ;
    b = a ; 
    b.gender = 'f' ; b.score = 350 ;
    strcpy(b.name, "Qian");
    printf("%s,%c,%d,",a.name , a.gender , a.score) ;
    printf("%s,%c,%d\n",b.name, b.gender, b.score) ;
    free(a.name) ;
    return 0 ;
}

#include <stdio.h>

void func ( char s[] , char t[]) ;
int main ( void )
{
    char s[10000] = { 0 } , t[10000] = {0} ;
    gets(s) ;
    gets(t) ;
    char *p1 = s , *p2 = t ;
     while ( *p1 != 0){
        ++p1 ;
     }
     while ( *p2 != 0){
     *p1++ = *p2++ ;
     }
    printf("%s" , s) ;

    return 0 ;
    
}

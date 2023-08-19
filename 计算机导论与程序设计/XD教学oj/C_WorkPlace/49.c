#include <stdio.h>
#include <math.h>

int main ( void )
{
     double a ,b ,num ;
    int rep ;
    scanf("%lf" ,  &a) ;

    b = sqrt(a) ;
    rep = b ;
    if ( b - rep == 0){
        printf("%d" , rep) ;
    }
    else {
        printf("no");
    }

    return 0;
}
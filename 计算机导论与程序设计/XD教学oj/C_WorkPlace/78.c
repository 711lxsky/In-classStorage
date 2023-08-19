#include <stdio.h>

int main (void)
{
    int n , m , k ;
    scanf("%d %d %d\n", &n , &m , &k) ;
    char gra[22][22] = {'\0'} ;
    int jud[22][22] = {0} ;
    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < m ; j ++){
            scanf("%c" , &gra[i][j]) ;
        }
        getchar() ;
    }
    //char *des ="none" ;
    int num = 0 , row = 0 , line = k - 1;
    while(22){
        char loc = gra[row][line] ;
        jud[row][line] = 1 ;
        if ('N' == loc) row -- ;
        else if ('S' == loc) row ++ ;
        else if ( 'E' == loc) line ++ ;
        else if ('W' == loc) line -- ;
        num ++ ;
        if (row < 0 || row == n || line < 0 || line == m) {
            printf("out ") ;
            break;
        }
        else if ( 1 == jud[row][line] ){
             printf("loop ") ;
            break ;
        }
    }
    printf("%d" ,  num) ;
}
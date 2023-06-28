#include <stdio.h>

double aver ( double (*prt)[4]) ;
int fals ( double (*ptr)[4] ) ;
int well ( double (*ptr)[4]) ;

int main (void)
{
    double gra[5][4] ;
    for ( int i = 0 ; i < 5 ; i ++){
        for ( int j = 0 ; j < 4 ; j ++){
            scanf("%lf" , &gra[i][j]) ;
        }
    }
    printf("%.1lf %d %d" , aver(gra) , fals(gra) , well(gra)) ;
}

double aver ( double (*ptr)[4])
{
    double sum = 0.0 ;
    for ( int i = 0 ; i < 5 ; i ++){
        sum +=  *(* ( ptr + i ) + 0 ) ;
    }
    sum /= 5 ;
    return sum ;
}

int fals ( double (*ptr)[4])
{
    int num = 0 ;
    for ( int i = 0 ; i < 5 ; i ++){
        int fail = 0 ;
        for ( int j = 0 ; j < 4 ; j ++){
            if ( *( * (ptr + i) + j) < 60) fail ++ ;
        }
        if ( fail >= 2 ) num ++ ;
    }
    return num ;
}

int well ( double (*ptr)[4] )
{
    int num = 0 ;
    for ( int i = 0 ; i < 5 ; i ++){
        double sum = 0.0 ;
        int jud = 0 ;
        for ( int j = 0 ; j < 4 ; j ++){
            double rep = * ( * ( ptr + i) + j) ;
            sum += rep ;
            if ( rep >= 85) jud ++ ;
        }
        sum /= 4 ;
        if ( (sum - 90.0) >= 0 || 4 == jud ) num ++ ;
    }

    return num ;
}
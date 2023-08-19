#include <stdio.h>
#include <string.h>

struct Stu
{
    char num[9] ;
    char name[11] ;
    double gra ;
};

int main ( void)
{
    struct Stu stu[101] ;
    int n ;
    double gra1 , gra2 ,gra3 ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%s %s %lf %lf %lf" , stu[i].num , stu[i].name , &gra1 , &gra2  , &gra3 ) ;
        stu[i].gra = (gra1 + gra2 + gra3) / 3 ;
    }
    for ( int i = 0 ; i < n ; i ++){
        double max_gra = -1 ;
        int lab = 0 ;
        for ( int j = 0 ; j < n ; j ++){
            if ( max_gra - stu[j].gra < 0) {
                lab = j ;
                max_gra = stu[j].gra ;
            }
        }
        printf("%s %s %.1lf\n" , stu[lab].num , stu[lab].name , stu[lab].gra) ;
        stu[lab].gra = -2.0 ;
    }
    return 0 ;
}
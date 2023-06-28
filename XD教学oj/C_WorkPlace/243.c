#include <stdio.h>
#include <string.h>

struct Stu
{
    char name[22] ;
    int sum_gra ;
    int add_gra ;
};

int main (void)
{
    struct Stu stu[101] ;
    int n  , gra1 , gra2 , gra3 , gra4 ,gra5  ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%s %d %d %d %d %d %d" , stu[i].name , &gra1 , &gra2 , &gra3 , &gra4 , &gra5 , &stu[i].add_gra ) ;
        stu[i].sum_gra = gra1 + gra2 + gra3 + gra4 + gra5 + stu[i].add_gra;
    }
    for ( int i = 0 ; i < n ; i ++){
        int max_gra = -1 ;
        int lab = 0 ;
        for ( int j = 0 ; j < n ; j ++){
            if ( max_gra < stu[j].sum_gra){
                max_gra = stu[j].sum_gra ;
                lab = j ;
            }
            else if ( max_gra == stu[j].sum_gra){
                if ( stu[lab].add_gra < stu[j].add_gra) {
                   // stu[lab].add_gra = stu[j].add_gra ;
                    lab = j ;
                }
            }
        }
        printf("%s %d %d\n" , stu[lab].name , stu[lab].sum_gra , stu[lab].add_gra ) ;
        stu[lab].sum_gra = -2 ;
    }
    return 0 ;
}

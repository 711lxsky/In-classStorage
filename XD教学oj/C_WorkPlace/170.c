#include <stdio.h>
#include <string.h>

struct Stu_gra
{
    char stu_name[22] ;
    int sum_gra ;
    int eng_gra ; 
};

int main (void)
{
    struct Stu_gra stu[200] ;
    int m , n ;
    scanf("%d %d" , &m , &n) ;
    for ( int i = 0 ; i < m ; i ++){
        scanf("%s %d %d" , stu[i].stu_name , &stu[i].sum_gra , &stu[i].eng_gra) ;
    }
    for ( int i = 0 ; i < n ; i ++){
        int lab = 0 ;
        struct Stu_gra test = {"msy" , -1 , -2} ;
        for ( int j = 0 ; j < m ; j ++){
            if ( test.sum_gra < stu[j].sum_gra){
                lab = j ;
                test.sum_gra = stu[j].sum_gra ;
                test.eng_gra = stu[j].eng_gra ;
            }
            else if ( test.sum_gra == stu[j].sum_gra){
                if ( test.eng_gra < stu[j].eng_gra){
                    lab = j ;
                     test.sum_gra = stu[j].sum_gra ;
                     test.eng_gra = stu[j].eng_gra ;
                }
            }
        }
        printf("%s %d %d\n" , stu[lab].stu_name , stu[lab].sum_gra , stu[lab].eng_gra) ;
        stu[lab].sum_gra = -22 ;
    }
}
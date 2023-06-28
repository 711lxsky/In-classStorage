#include <stdio.h>
#include <string.h>

struct File
{
    int year ;
    int month ;
    int day ;
    int size ;

};
int cmpfile (struct File ,struct File) ;
int main (void)
{
    struct File file[101] ;
    int n ;
    scanf("%d" , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d/%d/%d %d" , &file[i].year , &file[i].month , &file[i].day , &file[i].size) ;
    }
    for ( int i = 0 ; i < n ; i ++){
        struct File des_file ={ -1 , -1 , -1 , -1} ;
        int lab = 0 ;
        for ( int j = 0 ; j < n ; j ++){
        if ( cmpfile ( des_file , file[j]) ){
            lab = j ;
            des_file = file[j] ;
        }
        }
        printf("%d/%d/%d %d\n" , file[lab].year , file[lab].month , file[lab].day , file[lab].size) ;
        file[lab].year = -2 ;
    }
}

int cmpfile (struct File f1 ,struct File f2) 
{
    int jud = 0 ;
    if ( f1.year < f2.year) jud = 1 ;
    else if ( f1.year == f2.year) {
        if ( f1.month < f2.month) jud = 1 ;
        else if ( f1.month == f2.month) {
            if ( f1.day < f2.day) jud = 1 ;
            else if ( f1.day == f2.day) {
                if ( f1.size < f2.size) jud = 1 ;
            }
        }
    }
    return jud ;
} 
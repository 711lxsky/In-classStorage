#include <stdio.h>

struct Time
{
    int num ;
    int sta_hour ;
    int sta_min ;
    int end_hour ;
    int end_min ;
};

int main (void)
{
    int rate[101] = {0} ;
    struct Time time[101] ;
    int n ;
    scanf("%d" , &n) ;
    for ( int i = 0 ;i < n ; i ++){
        scanf("%d %d:%d %d:%d" , &time[i].num , &time[i].sta_hour , &time[i].sta_min , &time[i].end_hour , &time[i].end_min) ;
    }
    for ( int i = 0 ; i < n ; i ++){
        int loc = time[i].num ;
        int des = 0 ;
        int hour1 = time[i].sta_hour  , hour2 = time[i].end_hour , min1 = time[i].sta_min , min2 = time[i].end_min ;
        if ( min1 > min2){
            des = min2 + 60 - min1 + ( hour2 - 1 - hour1) * 60 ;
        }
        else {
            des = min2 - min1 + ( hour2 - hour1) * 60 ;
        }
        rate[loc] += des ;
    }
    n = 0 ;
    for ( int i = 0 ; i < 100 ; i ++ ) {
        if ( rate[i] != 0) n ++ ;
    }
    for ( int i = 0 ; i < n ; i ++){
        int lab = 0 ;
        int time_max = -1 ;
        for ( int j = 0 ; j < 100 ; j ++){
            if ( time_max < rate[j]) {
                lab = j ;
                time_max = rate[j] ;
            }
        }
        printf("%d %d\n" , lab , rate[lab]) ;
        rate[lab] = -1 ;
    }
    
}

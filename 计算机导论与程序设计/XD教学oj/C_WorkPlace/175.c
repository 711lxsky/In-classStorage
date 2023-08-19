#include <stdio.h>

struct Win
{
    int num ;
    int x1 ;
    int y1 ;
    int x2 ;
    int y2 ;
};

void change_loc( int , int , struct Win * ) ;
int main (void)
{
    struct Win windows[101] ;
    int lick_loc[52][3] = {0} ;
    int n , m ;
    scanf("%d %d" , &n , &m) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d %d %d %d" , &windows[i].x1 , &windows[i].y1 , &windows[i].x2 , &windows[i].y2) ;
        windows[i].num = i + 1 ;
    } 
    int lick_x = 0 , lick_y = 0 ;
    for ( int i = 0 ; i < m ; i++) 
        scanf("%d %d" , &lick_loc[i][0] , &lick_loc[i][1]) ;
    for ( int i = 0 ; i < m ; i ++){
       // scanf("%d %d" , &lick_x , &lick_y) ;
       lick_x = lick_loc[i][0] ;
       lick_y = lick_loc[i][1] ;
        int jud = 1 ;
        for ( int j = n -1 ; j >= 0 ; j --){
            if ( lick_x >= windows[j].x1 && lick_x <= windows[j].x2 && lick_y >= windows[j].y1 && lick_y <= windows[j].y2){
                printf("%d\n" , windows[j].num) ;
                jud = 0 ;
                change_loc( j , n , windows) ;
                break;
            }
        }
        if ( jud ) printf("IGNORED\n") ;
    }
}

void change_loc( int j , int n ,  struct Win * windows)
{
    struct Win rep = windows[j] ;
    for ( int i = j ; i < n - 1 ; i ++){
        windows[i] = windows[i+1] ;
    }
    windows[n-1] = rep ;
    
}
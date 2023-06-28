#include <stdio.h>

struct Pro
{
    int num_stock ;
    int pri_stock ;
    int cash ;
};

int main (void)
{
    struct Pro property = { 0 , 0 , 0} ;
    int n , deal_num , deal_price ;
    scanf("%d %d %d" , &property.num_stock , &property.pri_stock , &n) ;
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d %d" , &deal_num , &deal_price) ;
        property.num_stock += deal_num ;
        property.pri_stock = deal_price ;
        property.cash -= deal_num * deal_price ;
    }
    int sum = property.cash + property.num_stock * property.pri_stock ;
    printf("%d" , sum ) ;
}
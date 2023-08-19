#include <stdio.h>

int main (void)
{
    char *week[8] = {"Monday" , "Tuesday" , "Wendnesday" , "Thursday" , "Friday" , "Saturday" , "Sunday"} ;

    int year , month , day ;
    scanf("%d %d %d" , &year , &month , &day) ;
    if ( 1 == month || 2 == month){
        year -- ;
        month += 12 ;
    }
    int des = ( day + 2 * month + 3 * ( month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7 ;
    printf("%s" , week[des]) ; 
}
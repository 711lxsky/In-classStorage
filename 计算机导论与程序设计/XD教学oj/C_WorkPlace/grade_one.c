   // 使用for循环单次处理数据

#include <stdio.h>

int main ( void )
{
    int score , N , rate_A = 0 , rate_B = 0 , rate_C  = 0 , rate_D = 0 , rate_E = 0 ;

    scanf("%d" , &N) ;
    for ( int i = 1 ; i <= N ; i ++){  // 每进行一次for循环输入一个数据
        scanf("%d" , &score) ;
        if ( score >= 90) rate_A ++ ;  // 进行成绩等级的判断
        else if ( score >= 80 && score < 90) rate_B ++ ;
        else if ( score >= 70 && score < 80) rate_C ++ ;
        else if ( score >= 60 && score < 70) rate_D ++ ;
        else rate_E ++ ;
    }
    printf("%d %d %d %d %d" , rate_A , rate_B , rate_C , rate_D , rate_E) ;
    
    return 0 ;
}
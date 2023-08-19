 // 数组 + 函数调用

 #include <stdio.h>

 char judge_rate ( int x) ;
 int main ( void )
 {
    int num[1002] = { 0 } ;
    int N , rate_A = 0 , rate_B = 0 , rate_C  = 0 , rate_D = 0 , rate_E = 0 ;
    scanf("%d" , &N) ;

    for ( int i = 0 ; i < N ; i ++){ // 借助for循环输入数据存入数组
        scanf("%d" , &num[i]) ;
    }
    for ( int i = 0 ; i < N ; i ++){ // 遍历数组，进行数据处理
         // 原本这一步可以直接放在上面的for循环里面做，但是为了更好使用数组， 进行比较，又开了一个for循环
        char rate = judge_rate( num[i ]) ;
        if ( rate == 'A') rate_A ++ ;
        else if ( rate == 'B') rate_B ++ ;
        else if ( rate == 'C') rate_C ++ ;
        else if ( rate == 'D') rate_D ++ ;
        else rate_E ++  ;
}
        printf("%d %d %d %d %d" , rate_A , rate_B , rate_C , rate_D , rate_E) ;
    
    return 0 ;
    
 }

 char judge_rate ( int score){
       char mys ;

      if ( score >= 90) mys = 'A' ;  // 进行成绩等级的判断
        else if ( score >= 80 && score < 90) mys = 'B' ;
        else if ( score >= 70 && score < 80) mys = 'C' ;
        else if ( score >= 60 && score < 70) mys = 'D' ;
        else mys = 'E' ;

        return mys ;
 }
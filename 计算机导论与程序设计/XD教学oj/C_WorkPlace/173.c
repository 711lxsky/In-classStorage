#include <stdio.h>

void arra_sat( int , int *) ;
int main (void)
{
    int n ;
    int tic_num[101] = { 0 }  , sat_num[21][5] = {0} , line_freeSat_num[21] = {0} ;
    /* tic_num 表示 需要购买的车票数量
       sat_num 表示座位矩阵 ， 若元素为 0 ， 表示未售出（空） ；为 1 ， 则已售出（有人）
       line_freeSat_num 表示每一排座位中的空座位数 如 10101 ， 空座位数为2*/
    for ( int i = 0 ; i < 20 ; i ++) line_freeSat_num[i] = 5 ;
    // 遍历 ， 将元素赋值为5 （初始时每排空座位都是5）
    scanf("%d" , &n) ;
    // 读入购票指令数量 ， 开始for循环
    for ( int i = 0 ; i < n ; i ++){
        scanf("%d" , &tic_num[i]) ;
        // 读入购票数
    }
    for ( int i = 0 ; i < n ; i ++){
        int need_tic = tic_num[i] ;
    // need_tic 表示所需票数 ， 引入这个变量是为了方便阅读和写代码
        int jud = 0 ;
        for ( int j = 0 ; j < 20 ; j ++){
        // 逐个查看每排空座位数 ， jud判断是否有某一排满足购票要求
            if ( line_freeSat_num[j] >= need_tic){
                int loc ;
                // loc 用于标记 满足 要求 的 这一排 中 空座位 的 位置
                jud = 1 ;
                // 存在这排 ， jud 标记为 1
                line_freeSat_num[j] -= need_tic ;
                // 将此排的空闲座位数更新
                for (  loc = 0 ; sat_num[j][loc] != 0 ; loc ++) ;
                // 寻找此排中 空座位 具体位置
                for ( int k = 0 ; k < need_tic ; k ++){
                    sat_num[j][loc+k] = 1 ;
                    // 在座位矩阵中将座位状态标记为售出
                    printf("%d " , j * 5 + loc + k + 1) ;
                    // 打印车票号码 ， 注意座位号下标起始是1
                }
                printf("\n") ;
                break;
            }

        }
        if ( jud == 0){
            // 不存在满足要求的一排
            int sum = 0 , row = 0 , loc = 0;
            // sum 用于逐一收集空闲座位的数量
            // row 用来标记排号
            while ( sum <= need_tic){
                // sum 直至收集到满足购票要求的座位数量 ， 才跳出循环
                if ( sat_num[row][loc] == 0){
                    // 是空闲的就收集
                    line_freeSat_num[row] -- ;
                    // 更新每排的空闲座位量
                    sum ++ ;
                    // 收集
                    sat_num[row][loc] = 1 ;
                    // 更新座位状态
                 if( row <= 19)   printf("%d " , row * 5 + loc + 1) ;
                 //注意行下标不超过19  
                 //打印车票
                }
                if ( loc == 4){
                    row ++ ;
                    loc = 0 ;
                // 当loc跑到4时 ， 此时要查看下一排
                }
                else loc ++ ;
            }
            printf("\n") ;
            // 买完一个 ， 打印换行
        }
    }
}


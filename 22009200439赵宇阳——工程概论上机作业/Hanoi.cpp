/* 使用递归解决本问题：
因为是将n个棋子全部从A杆移动到C杆，
所以先借助C杆将n-1个棋子移动到B杆，将A上第n个棋子移动到C杆后，再动B杆上的n-1棋子
剩下的棋子又可以按上述规律，借助A杆移动到C杆，可以看成将第n个棋子忽略*/

#include <bits/stdc++.h>

using namespace std ;
int sum_change = 0 ;
void moveChess(int , char , char) ;
void HanoiChange(int , char , char , char) ;

int main(void)
{   
    cout << "现在您可以输入需要移动的棋子数，我将进行移动" << endl ;
    int n = 0 ;
    cin >> n ;
    HanoiChange(n , 'A' , 'B' , 'C') ;
    cout << "一共移动了" << sum_change << "步" ;
    return 0 ;

}

void moveChess(int num , char pillarStart , char pillarEnd){
    // 从函数打印棋子的移动轨迹并对步数记录
    cout << "将第" << num << "颗棋子从" << pillarStart << "柱移动到" << pillarEnd << "柱" << endl ;
    ++ sum_change ;    
}

void HanoiChange(int n , char pillarA , char pillarB , char pillarC){
    /* 处理移动逻辑的主递归函数
    递归结束条件是n == 0*/
    if(n == 1){
        moveChess(n , pillarA , pillarC) ;
    }
    // 重复递归 主杆上仅剩一颗棋子时，移动到目标杆
    else {
        HanoiChange(n - 1 , pillarA , pillarC , pillarB) ;
        moveChess(n , pillarA , pillarC) ;
        HanoiChange(n - 1 , pillarB , pillarA , pillarC) ;
    }
    
}
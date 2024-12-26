#include "People.h"

// 初始化静态成员变量
int People::num = 0;

int main() {
    // 创建两个People对象
    People p1(30, 170, 60);
    People p2(25, 160, 55);
    // 显示两个人的信息
    p1.Show();
    p2.Show();
    // 显示人数
    People::ShowNum();
    // p1进食，p2运动
    p1.Eating();
    p2.Sporting();
    // p1和p2睡眠
    p1.Sleeping();
    p2.Sleeping();
    // 再次显示两个人的信息
    p1.Show();
    p2.Show();
    // 再次显示人数
    People::ShowNum();

    return 0;
}

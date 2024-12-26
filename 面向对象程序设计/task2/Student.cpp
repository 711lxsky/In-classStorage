#include "Student.h"

// 静态成员变量初始化
int Student::count = 0;
int Student::mathTotalScore = 0;
int Student::englishTotalScore = 0;

int main() {
    // 创建学生对象
    Student s1("Alice", 1, 90, 88);
    Student s2("Bob", 2, 85, 92);
    Student s3("Charlie", 3, 78, 81);

    // 显示每个学生的基本信息
    s1.ShowBase();
    s2.ShowBase();
    s3.ShowBase();

    // 显示静态数据
    Student::ShowStatic();

    return 0;
}


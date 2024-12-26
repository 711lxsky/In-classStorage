#include <iostream>
#include <cstring> // 用于处理字符数组

using namespace std;

class Student {
private:
    char name[18];
    int num;
    int mathScore;
    int englishScore;
    static int count; // 学生人数
    static int mathTotalScore; // 数学总成绩
    static int englishTotalScore; // 英语总成绩

public:
    // 构造函数
    Student(const char* nm, int nu, int math, int english) {
        strncpy(name, nm, 17); // 复制姓名，确保不会超出字符数组长度
        name[17] = '\0'; // 确保字符串以空字符结尾
        num = nu;
        mathScore = math;
        englishScore = english;
        count++;
        mathTotalScore += math;
        englishTotalScore += english;
    }

    // 显示基本数据
    void ShowBase() const {
        cout << "Name: " << name << ", Number: " << num
             << ", Math Score: " << mathScore << ", English Score: " << englishScore << endl;
    }

    // 显示静态数据
    static void ShowStatic() {
        cout << "Total Students: " << count
             << ", Total Math Score: " << mathTotalScore
             << ", Total English Score: " << englishTotalScore << endl;
    }
};

#include <iostream>

class Date;  // 前向声明

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}

    // 友元函数，用于显示时间和日期
    void display(const Date& date);
};

class Date {
private:
    int year;
    int month;
    int day;

    // 声明Time类为友元类
    friend class Time;

public:
    Date(int y = 2000, int m = 1, int d = 1) : year(y), month(m), day(d) {}
};

// Time类的display函数实现
void Time::display(const Date& date) {
    std::cout << "Date: " << date.year << "-" << date.month << "-" << date.day << std::endl;
    std::cout << "Time: " << hour << ":" << minute << ":" << second << std::endl;
}

int main() {
    // 创建Date和Time对象
    Date date(2024, 11, 18);
    Time time(22, 30, 45);

    // 使用Time类的display函数输出日期和时间
    time.display(date);

    return 0;
}

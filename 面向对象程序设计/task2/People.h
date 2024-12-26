#include <iostream>

using namespace std;

class People {
protected:
    int age;
    int height;
    int weight;
    static int num; // 静态成员变量，用于记录人数

public:
    // 构造函数
    People(int a, int h, int w) : age(a), height(h), weight(w) {
        num++; // 每次创建一个新对象，人数增加
    }

    // 进食：体重加1
    void Eating() {
        weight += 1;
    }

    // 运动：身高加1
    void Sporting() {
        height += 1;
    }

    // 睡眠：年龄、身高、体重各加1
    void Sleeping() {
        age += 1;
        height += 1;
        weight += 1;
    }

    // 显示个人信息
    void Show() const {
        cout << "Age: " << age << ", Height: " << height << " cm, Weight: " << weight << " kg" << endl;
    }

    // 静态成员函数，显示人数
    static void ShowNum() {
        cout << "Number of people: " << num << endl;
    }
};



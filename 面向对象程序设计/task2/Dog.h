#include <iostream>
#include <cstring> // 用于处理字符串的函数，如strcpy和strlen

using namespace std;

class Dog {
private:
    char* name; // 狗的名字，使用字符指针表示
    int age; // 狗的年龄
    char sex; // 狗的性别，'M'表示男性，'F'表示女性
    double weight; // 狗的体重

public:
    // 构造函数
    Dog(const char* n, int a, char s, double w) : age(a), sex(s), weight(w) {
        name = new char[strlen(n) + 1]; // 为name分配内存
        strcpy(name, n); // 复制名字到name
    }

    // 复制构造函数，实现深拷贝
    Dog(const Dog& other) : age(other.age), sex(other.sex), weight(other.weight) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name); // 复制名字
    }

    // 赋值运算符，也要确保深拷贝
    Dog& operator=(const Dog& other) {
        if (this != &other) { // 防止自我赋值
            char* new_name = new char[strlen(other.name) + 1];
            strcpy(new_name, other.name); // 复制名字
            delete[] name; // 释放旧的内存
            name = new_name; // 指向新的名字内存
            age = other.age;
            sex = other.sex;
            weight = other.weight;
        }
        return *this;
    }

    // 析构函数，释放内存
    ~Dog() {
        delete[] name;
    }

    // 设置狗的名字
    void setName(const char* n) {
        delete[] name; // 释放旧的内存
        name = new char[strlen(n) + 1]; // 为新名字分配内存
        strcpy(name, n); // 复制新名字
    }

    // 设置狗的年龄
    void setAge(int a) {
        age = a;
    }

    // 设置狗的性别
    void setSex(char s) {
        sex = s;
    }

    // 设置狗的体重
    void setWeight(double w) {
        weight = w;
    }

    // 打印狗的信息
    void print() const {
        cout << "Name: " << name << ", Age: " << age << ", Sex: " << sex << ", Weight: " << weight << " kg" << endl;
    }
};

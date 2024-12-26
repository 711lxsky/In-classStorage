#include <iostream>
#include <string>
#include <utility>

// 基类 Person
class Person {
protected:
    int id;
    std::string name;

public:
    // 构造函数
    Person(int id, std::string  name) : id(id), name(std::move(name)) {}

    // 显示个人信息
    virtual void display() const {
        std::cout << "ID: " << id << ", Name: " << name << std::endl;
    }
};

// 派生类 Student
class Student : public Person {
private:
    int classNumber;
    float score;

public:
    // 构造函数
    Student(int id, const std::string& name, int classNumber, float score)
        : Person(id, name), classNumber(classNumber), score(score) {}

    // 重写显示方法
    void display() const override {
        Person::display();
        std::cout << "Class Number: " << classNumber << ", Score: " << score << std::endl;
    }
};

// 派生类 Teacher
class Teacher : public Person {
private:
    std::string title;
    std::string department;

public:
    // 构造函数
    Teacher(int id, const std::string& name, std::string  title, std::string  department)
        : Person(id, name), title(std::move(title)), department(std::move(department)) {}

    // 重写显示方法
    void display() const override {
        Person::display();
        std::cout << "Title: " << title << ", Department: " << department << std::endl;
    }
};

int main() {
    // 创建学生对象并显示信息
    Student student(1, "Alice", 101, 95.5);
    student.display();

    // 创建教师对象并显示信息
    Teacher teacher(2, "Bob", "Professor", "Computer Science");
    teacher.display();

    return 0;
}

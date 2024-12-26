#include <iostream>
#include <string>

// 基类 Teacher
class Teacher {
protected:
    std::string name;
    int age;
    char gender;
    std::string address;
    std::string phone;
    std::string title;

public:
    // 构造函数
    Teacher(const std::string& name, int age, char gender, const std::string& address, const std::string& phone, const std::string& title)
        : name(name), age(age), gender(gender), address(address), phone(phone), title(title) {}

    // 显示教师信息
    void display() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Gender: " << gender << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Phone: " << phone << std::endl;
        std::cout << "Title: " << title << std::endl;
    }
};

// 基类 Cadre
class Cadre {
protected:
    std::string name;
    int age;
    char gender;
    std::string address;
    std::string phone;
    std::string post;

public:
    // 构造函数
    Cadre(const std::string& name, int age, char gender, const std::string& address, const std::string& phone, const std::string& post)
        : name(name), age(age), gender(gender), address(address), phone(phone), post(post) {}

    // 获取职务
    std::string getPost() const {
        return post;
    }
};

// 派生类 Teacher_Cadre
class Teacher_Cadre : public Teacher, public Cadre {
private:
    double wages;

public:
    // 构造函数
    Teacher_Cadre(const std::string& name, int age, char gender, const std::string& address, const std::string& phone,
                  const std::string& title, const std::string& post, double wages)
        : Teacher(name, age, gender, address, phone, title), Cadre(name, age, gender, address, phone, post), wages(wages) {}

    // 显示教师兼干部信息
    void show() const {
        Teacher::display();  // 调用Teacher类的display函数
        std::cout << "Post: " << Cadre::getPost() << std::endl;  // 使用Cadre类的作用域获取职务
        std::cout << "Wages: " << wages << std::endl;
    }
};

int main() {
    // 创建Teacher_Cadre对象并显示信息
    Teacher_Cadre teacherCadre("Alice", 45, 'F', "123 Main St", "123-456-7890", "Associate Professor", "Department Head", 8000.0);
    teacherCadre.show();

    return 0;
}

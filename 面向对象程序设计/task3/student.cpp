#include <iostream>
#include <string>

class Student {
public:
    int id;
    float score;

    Student(int id, float score) : id(id), score(score) {}
};

// 函数声明
void printStudents(Student* students);
void max(Student* students);

int main() {
    // 创建5个学生的数组
    Student students[5] = {
        Student(1, 85.0),
        Student(2, 90.5),
        Student(3, 78.0),
        Student(4, 88.5),
        Student(5, 95.0)
    };

    // 用指针指向数组首元素，输出第1，3，5个学生的数据
    printStudents(students);

    // 找出成绩最高的学生并输出其学号
    max(students);

    return 0;
}

// 输出第1，3，5个学生的数据
void printStudents(Student* students) {
    std::cout << "Student 1: ID = " << students[0].id << ", Score = " << students[0].score << std::endl;
    std::cout << "Student 3: ID = " << students[2].id << ", Score = " << students[2].score << std::endl;
    std::cout << "Student 5: ID = " << students[4].id << ", Score = " << students[4].score << std::endl;
}

// 找出成绩最高的学生并输出其学号
void max(Student* students) {
    Student* maxStudent = students;

    for (int i = 1; i < 5; ++i) {
        if (students[i].score > maxStudent->score) {
            maxStudent = &students[i];
        }
    }

    std::cout << "The student with the highest score is: ID = " << maxStudent->id << ", Score = " << maxStudent->score << std::endl;
}

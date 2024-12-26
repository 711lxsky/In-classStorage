#include <iostream>

class Matrix {
private:
    int data[2][3];

public:
    // 默认构造函数
    Matrix() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                data[i][j] = 0;
            }
        }
    }

    // 友元函数，重载流提取运算符 >>
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);

    // 友元函数，重载流插入运算符 <<
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

// 重载流提取运算符 >>
std::istream& operator>>(std::istream& is, Matrix& matrix) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}

// 重载流插入运算符 <<
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

int main() {
    Matrix mat;

    std::cout << "Enter the elements of a 2x3 matrix (6 integers):" << std::endl;
    std::cin >> mat;

    std::cout << "The matrix you entered is:" << std::endl;
    std::cout << mat;

    return 0;
}

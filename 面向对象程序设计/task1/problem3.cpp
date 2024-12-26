#include <iostream>
using namespace std;

// 整型排序函数
void sort(int &a, int &b, int &c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}

// 浮点型排序函数
void sort(float &a, float &b, float &c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}

int main() {
    int x = 5, y = 1, z = 3;
    float a = 5.5, b = 1.1, c = 3.3;

    // 对整型排序
    sort(x, y, z);
    cout << "Sorted integers: " << x << " " << y << " " << z << endl;

    // 对浮点型排序
    sort(a, b, c);
    cout << "Sorted floats: " << a << " " << b << " " << c << endl;

    return 0;
}

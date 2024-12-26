#include <iostream>
using namespace std;

// 函数模板实现排序
template<typename T>
void sort(T &a, T &b, T &c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}

int main() {
    int x = 6, y = 2, z = 4;
    float a = 6.6, b = 2.2, c = 4.4;

    // 对整型排序
    sort(x, y, z);
    cout << "Sorted integers: " << x << " " << y << " " << z << endl;

    // 对浮点型排序
    sort(a, b, c);
    cout << "Sorted floats: " << a << " " << b << " " << c << endl;

    return 0;
}

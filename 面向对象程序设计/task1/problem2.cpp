#include <iostream>
using namespace std;

// 使用引用参数交换两个数
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort(int &a, int &b, int &c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);  // 再次确保a <= b
}

int main() {
    int x, y, z;
    cout << "Enter three integers: ";
    cin >> x >> y >> z;
    sort(x, y, z);
    cout << "Sorted numbers: " << x << " " << y << " " << z << endl;
    return 0;
}

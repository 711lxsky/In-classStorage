#include <iostream>
using namespace std;

// 带默认参数的函数，第三个参数默认值为0
int max(int a, int b, int c = 0) {
    return (a > b && a > c) ? a : (b > c ? b : c);
}

int main() {
    int x = 0, y = 0, z = 0;
    cout << "get out your numbers :" << endl;
    cin >> x >> y >> z;
    // 求2个数的最大值
    cout << "Max of 2 numbers: " << max(x, y) << endl;
    // 求3个数的最大值
    cout << "Max of 3 numbers: " << max(x, y, z) << endl;
    return 0;
}

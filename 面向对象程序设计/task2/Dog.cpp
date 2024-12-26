#include "Dog.h"

int main() {
    // 使用对象指针创建Dog对象
    Dog* dog1 = new Dog("Rex", 5, 'M', 30.5);
    Dog* dog2 = new Dog("Bella", 3, 'F', 20.0);

    // 打印狗的信息
    dog1->print();
    dog2->print();

    // 更改dog2的名字
    dog2->setName("Luna");

    // 再次打印信息，查看更改结果
    dog1->print();
    dog2->print();

    // 清理，防止内存泄漏
    delete dog1;
    delete dog2;

    return 0;
}

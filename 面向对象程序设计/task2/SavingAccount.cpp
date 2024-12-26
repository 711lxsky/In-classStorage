#include "SavingAccount.h"

int main() {
    // 创建账户
    SavingsAccount myAccount("123456789", "John Doe", "pwd123", 10000, 0.02);

    // 打印账户信息
    myAccount.printAccountInfo();

    // 测试存款功能
    myAccount.deposit(2000);
    myAccount.printAccountInfo();

    // 测试取款功能
    if (myAccount.withdraw(3000)) {
        myAccount.printAccountInfo();
    }

    // 测试取款失败（余额不足）
    if (!myAccount.withdraw(10000)) {
        myAccount.printAccountInfo();
    }

    // 计算并显示年利息
    double interest = myAccount.calculateInterest();
    cout << "Estimated annual interest: " << interest << endl;

    return 0;
}

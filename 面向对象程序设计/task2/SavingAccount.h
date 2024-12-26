#include <iostream>
#include <string>
#include <utility>

using namespace std;

class SavingsAccount {
private:
    string accountNumber; // 账号
    string accountName;   // 户名
    string password;      // 密码
    double balance;       // 余额
    double annualInterestRate; // 年利率

public:
    // 构造函数
    SavingsAccount(string num, string name, string pwd, double bal, double rate)
        : accountNumber(std::move(num)), accountName(std::move(name)), password(std::move(pwd)), balance(bal), annualInterestRate(rate) {}

    // 存钱方法
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful, Amount: " << amount << endl;
        } else {
            cout << "Please enter a valid deposit amount!" << endl;
        }
    }

    // 取钱方法
    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance, withdrawal failed!" << endl;
            return false;
        } else if (amount <= 0) {
            cout << "Please enter a valid withdrawal amount!" << endl;
            return false;
        } else {
            balance -= amount;
            cout << "Withdrawal successful, Amount: " << amount << endl;
            return true;
        }
    }

    // 计算年利息
    double calculateInterest() const {
        return balance * annualInterestRate;
    }

    // 打印账户信息
    void printAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Annual Interest Rate: " << annualInterestRate * 100 << "%" << endl;
    }
};

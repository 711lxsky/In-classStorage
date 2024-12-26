#include "SavingAccount.h"

int main() {
    // �����˻�
    SavingsAccount myAccount("123456789", "John Doe", "pwd123", 10000, 0.02);

    // ��ӡ�˻���Ϣ
    myAccount.printAccountInfo();

    // ���Դ���
    myAccount.deposit(2000);
    myAccount.printAccountInfo();

    // ����ȡ���
    if (myAccount.withdraw(3000)) {
        myAccount.printAccountInfo();
    }

    // ����ȡ��ʧ�ܣ����㣩
    if (!myAccount.withdraw(10000)) {
        myAccount.printAccountInfo();
    }

    // ���㲢��ʾ����Ϣ
    double interest = myAccount.calculateInterest();
    cout << "Estimated annual interest: " << interest << endl;

    return 0;
}

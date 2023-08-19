/* 此文件为启动文件
 * main函数放在此处，作为启动项*/

// 引入主功能头文件
#include "MainFunction.h"

// 直接调用函数接口
int main(void)
{
    getSourceData();
    elementManage();
    calculateRes();

    return 0;
}

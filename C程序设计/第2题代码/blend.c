/* 此源文件为启动文件
 * main主函数放在此处，对应题给要求*/

#include "MainFunction.h"

int main(int argc, char* argv[])
{
    // 直接调用头文件中相关接口
    getArgVs(argc,argv);
    operateBmp();
    return 0;
}


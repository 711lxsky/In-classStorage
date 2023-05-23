/* 此源文件是启动文件，
 * main函数放在此文件中*/

/* 引入系统头文件*/
#include "System.h"

int main(void)
/* 主函数入口*/
{
    /* 系统未初始化，调用相关函数进行初始化*/
    if(initializeSystemJud == NULL){
        setIniSysJud();
        initializeSystem();
    }
    /* 初始化过，调用菜单函数*/
    initializeMenu();
    //realDeleteAllPerson(manager);
    return 0;
}

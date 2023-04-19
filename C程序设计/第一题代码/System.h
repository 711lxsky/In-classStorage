/* 此头文件用来集合"Menu.h"和"MainFunction"的功能
 * 作为唯一系统头文件*/

/* 引入自己编写的头文件*/
#include "Menu.h"
#include "MainFunction.h"

/* 定义全局系统初始化判断变量，控制系统初始化*/
static int * initializeSystemJud = NULL;
/* 定义全局联系人管理员变量，用以控制系统链表*/
static PersonManage * manager = NULL;

/* 定义全局操作选项枚举变量
 * 各自一一对应相关功能选项*/
enum option{Exit,Enter,Del,List,Search,Save,Load,Renew};

void setIniSysJud()
/* 对initializeSystemJud 变量进行设置*/
{
    /* 显示申请内存*/
    initializeSystemJud = (int *) malloc(sizeof(int));
    /* 值置 1 */
    * initializeSystemJud = 1 ;
}

void initializeSystem()
/* 系统初始化*/
{
    /* 调用API接口，加载管理员*/
    manager = loadManage();
}

void initializeMenu()
/* 菜单初始化，
 * 对用户选择的功能进行函数调用*/
{
    /* 定义退出菜单变量*/
    int getExit = 0;
    /* 开始循环，进入系统*/
    while (getExit == 0) {
        /* 定义功能选择变量*/
        int GetOption = -1;
        /* 展示主菜单，进行用户交互*/
        getMenu();
        /* 读入用户选择的功能*/
        scanf("%d", &GetOption);
        /* 对应选择的功能一一跳转*/
        switch (GetOption) {
            /* 退出功能，
             * 将getExit 置1，以跳出循环*/
            case Exit:
                getExit = 1;
                break;
                /* 录入功能，调用enter接口*/
            case Enter:
                enter(manager);
                continueMenu();
                break;
                /* 删除功能，调用del接口*/
            case Del:
                del(manager);
                continueMenu();
                break;
                /* 显示功能，调用list接口*/
            case List:
                list(manager);
                continueMenu();
                break;
                /* 查询功能，调用search接口*/
            case Search:
                search(manager);
                continueMenu();
                break;
                /* 保存功能，调用save接口*/
            case Save:
                save(manager);
                continueMenu();
                break;
                /* 加载功能，调用load接口*/
            case Load:
                load(manager);
                continueMenu();
                break;
                /* 恢复出厂设置*/
            case Renew:
                fakeDeleteAllPerson(manager);
                break;
                /* 用户没有输入有效数字*/
            default:
                printf("没有此选项！\n");
        }
    }
    /* 退出菜单*/
    exitMenu();
}

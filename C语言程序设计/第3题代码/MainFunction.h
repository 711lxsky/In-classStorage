/* 此头文件主要集成功能函数
 * 封装接口以供调用*/

// 引入自定义头文件和标准库库头文件
#include "StackOfChar.h"
#include "StackOfInt.h"
#include <string.h>
#include <ctype.h>

// 宏定义最大量
#define MaxNum 1000

// 重命名元素数据类型
typedef char ElementType;

// 声明字符列表
ElementType sourceList[MaxNum];
// 声明最终运算式列表
ElementType destList[MaxNum];
// 声明操作符字符栈
StackOfChar * opStack;
// 声明运算整数栈
StackOfInt * calStack;

// 运算式长度
int lenDest = 0;
// 计算结果
int calRes = 0;

/* 初始化结构函数*/
void initializeAll()
{
    // 初始化两列表
    for(int i = 0 ; i < MaxNum ; i ++){
        sourceList[i] = '\0';
        destList[i] = '\0';
    }
    // 创建字符栈
    opStack = createStackOfChar();
}

/* 抓取初始运算式*/
void getSourceData()
{
    // 调用初始化函数
    initializeAll();
    // 打印提示信息
    printf("please enter your calculations:\n");
    // 读入并提示
    gets(sourceList);
    printf("OK , I get it:\n");
    printf("%s\n",sourceList);
}

/* 判断字符是否是运算符函数*/
Status operatorJud(ElementType ope)
{
    // 直接if判断
    if(ope == '(' || ope == ')' || ope == '+' || ope == '-' || ope == '*' || ope == '/'){
        return Ture;
    }
    else return False;
}

/* 比较运算符等级函数
 * 前比后高，则True
 * 反之，则False*/
Status operatorCmp(ElementType ope , ElementType popOpe)
{
     /* 设置比较逻辑
      * ( + - * / 之间进行比较*/
    if(ope == '(' || popOpe == '('){
        return Ture;
    }
    else if(ope == '+' || ope == '-'){
        return False;
    }
    else {
        if(popOpe == '+' || popOpe == '-'){
            return Ture;
        }
        else return False;
    }
}

/* 对操作符进行出入栈操作函数
 * 可进行递归调用*/
void operatorManage(ElementType ope)
{
    // 声明弹出的数据
    ElementType getOpe;
    /* 建立逻辑对弹出的操作符和本操作符进行操作
     * 进入运算式
     * 或 入栈*/
    if(isEmptySOC(opStack)){
        pushSOC(opStack, ope);
    }
    else if(ope == ')'){
        while((getOpe = popSOC(opStack)) != '('){
            destList[lenDest++] = getOpe;
        }
    }
    else {
        getOpe = popSOC(opStack);
        if(operatorCmp(ope,getOpe)){
            pushSOC(opStack, getOpe);
            pushSOC(opStack, ope);
        }
        else {
            destList[lenDest++] = getOpe;
            // 重复递归调用，直到入栈成功
            operatorManage(ope);
        }
    }
}

/* 初始表达式字符操作函数*/
void elementManage()
{
    // 得到长度，迭代操作
    int lenSource = strlen(sourceList);
    for(int i = 0; i < lenSource; i++){
        // 数字字符直接进入最终表达式
        if(isdigit(sourceList[i])){
            destList[lenDest++]= sourceList[i];
        }
        // 运算符进入逻辑判断，对应操作
        else if(operatorJud(sourceList[i])){
            operatorManage(sourceList[i]);
        }
        // 剔除非运算符和数字
        else ;
    }
    // 栈非空，持续弹出元素
    while(isEmptySOC(opStack) == False){
        destList[lenDest++] = popSOC(opStack);
    }
    // 得到最终式，打印提示
    printf("the nifix expression of it is:\n%s\n",destList);
    // 清空栈内存
    deleteStackOfChar(opStack);
}

/* 根据运算符种类计算两元素计算结果*/
int calByOpe(int numUp , int numDown , ElementType operator)
{
    // 方便计算，声明整数变量
    int res ;
    switch (operator) {
        case '+':
            res = numDown + numUp;
            break;
        case '-':
            res = numDown - numUp;
            break;
        case '*':
            res = numDown * numUp;
            break;
        case '/':
            res = numDown / numUp;
            break;
        default:
            res = 0 ;
    }
    return res ;
}

/* 计算最终表达式结果函数*/
void calculateRes()
{
    // 创建整数栈，方便运算
    calStack = createStackOfInt();
    // 遍历表达式计算
    for(int i = 0 ; i < lenDest ; i++){
        if(isdigit(destList[i])){
            // 数字进栈
            pushSOI(calStack,destList[i]-'0');
        }
        // 遇运算符弹出两个数字运算
        else {
            int digit1 = popSOI(calStack) ;
            int digit2 = popSOI(calStack) ;
            int tempRes = calByOpe(digit1,digit2,destList[i]);
            // 运算结果入栈
            pushSOI(calStack,tempRes);
        }
    }
    // 最终结果弹出，运算完成
    calRes = popSOI(calStack);
    // 回收内存
    deleteStackOfInt(calStack);
    // 打印最终结果
    printf("the answer is %d\n",calRes);
}


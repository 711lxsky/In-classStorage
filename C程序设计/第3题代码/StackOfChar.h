/* 此头文件定义栈结构，并封装字符栈的相关函数
 * 出栈，入栈，判空,以及将初始栈释放*/

// 引入所需头文件
#include <stdio.h>
#include <stdlib.h>

// 宏定义布尔值
#define Ture 1
#define False 0

// 重命名所需相关数据类型
typedef int Status;
typedef char NodeType;

// 创建栈节点结构
typedef struct SNode{
    // 数据值
    NodeType data;
    // 指针
    struct SNode * pointer;
}StackNodeOfChar;

// 构造栈结构
typedef struct stack{
    // 栈底
    StackNodeOfChar * bottom;
    // 栈顶
    StackNodeOfChar * top;
    // 栈大小
    Status size;
}StackOfChar;


/* 创建空栈函数*/
StackOfChar * createStackOfChar()
{
    // 显式申请空栈内存，并打印提示信息
    StackOfChar * newStack =(StackOfChar *) malloc(sizeof(StackOfChar));
    if(newStack == NULL){
        printf("there is no space for stack of char!\n");
        // 未申请成功则退出
        exit(-12);
    }
    // 设置初始值
    newStack->size = 0;
    // 显式申请哑节点内存，失败打印消息
    newStack->bottom = newStack->top = (StackNodeOfChar *) malloc(sizeof(StackNodeOfChar));
    if(newStack->bottom == NULL){
        printf("there is no space for node!\n");
        exit(-22);
    }
    // 置栈底哑节点初值
    newStack->bottom->data = '!';
    // 返回创建的栈指针
    return newStack;
}

/* 栈判空函数*/
Status isEmptySOC(StackOfChar * stack)
{
    // 根据栈大小返回判断值
    if(stack->size == 0){
        return Ture;
    }
    else {
        return False;
    }
}

/* 栈压入数据函数*/
void pushSOC(StackOfChar * stack , NodeType addElem)
{
    // 显式申请新节点内存，申请失败打印消息并退出
    StackNodeOfChar * newNode = (StackNodeOfChar *) malloc(sizeof(StackNodeOfChar));
    if(newNode == NULL){
        printf("no space for StackNodeOfChar!\n");
        exit(-22);
    }
    // 加入数据
    newNode->data = addElem;
    // 更新栈大小
    stack->size += 1;
    // 建立内存联系
    newNode->pointer = stack->top;
    // 栈顶更新
    stack->top = newNode;
}

/* 栈弹出数据函数*/
NodeType popSOC(StackOfChar * stack){
    // 抓取数据
    NodeType res = stack->top->data;
    // 暂存内存指针，方便后续连接
    StackNodeOfChar * tempPtr = stack->top->pointer;
    // 释放内存
    free(stack->top);
    // 连接
    stack->top = tempPtr;
    // 更新大小
    stack->size -= 1;
    return res;
}

/* 删除哑节点，清空栈函数*/
void deleteStackOfChar(StackOfChar * stack){
    // 直接释放内存
    free(stack->bottom);
    free(stack);
    // 打印提示信息
    //printf("delete stack of char success\n");
}

/* ��ͷ�ļ�����ջ�ṹ������װ�ַ�ջ����غ���
 * ��ջ����ջ���п�,�Լ�����ʼջ�ͷ�*/

// ��������ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>

// �궨�岼��ֵ
#define Ture 1
#define False 0

// ���������������������
typedef int Status;
typedef char NodeType;

// ����ջ�ڵ�ṹ
typedef struct SNode{
    // ����ֵ
    NodeType data;
    // ָ��
    struct SNode * pointer;
}StackNodeOfChar;

// ����ջ�ṹ
typedef struct stack{
    // ջ��
    StackNodeOfChar * bottom;
    // ջ��
    StackNodeOfChar * top;
    // ջ��С
    Status size;
}StackOfChar;


/* ������ջ����*/
StackOfChar * createStackOfChar()
{
    // ��ʽ�����ջ�ڴ棬����ӡ��ʾ��Ϣ
    StackOfChar * newStack =(StackOfChar *) malloc(sizeof(StackOfChar));
    if(newStack == NULL){
        printf("there is no space for stack of char!\n");
        // δ����ɹ����˳�
        exit(-12);
    }
    // ���ó�ʼֵ
    newStack->size = 0;
    // ��ʽ�����ƽڵ��ڴ棬ʧ�ܴ�ӡ��Ϣ
    newStack->bottom = newStack->top = (StackNodeOfChar *) malloc(sizeof(StackNodeOfChar));
    if(newStack->bottom == NULL){
        printf("there is no space for node!\n");
        exit(-22);
    }
    // ��ջ���ƽڵ��ֵ
    newStack->bottom->data = '!';
    // ���ش�����ջָ��
    return newStack;
}

/* ջ�пպ���*/
Status isEmptySOC(StackOfChar * stack)
{
    // ����ջ��С�����ж�ֵ
    if(stack->size == 0){
        return Ture;
    }
    else {
        return False;
    }
}

/* ջѹ�����ݺ���*/
void pushSOC(StackOfChar * stack , NodeType addElem)
{
    // ��ʽ�����½ڵ��ڴ棬����ʧ�ܴ�ӡ��Ϣ���˳�
    StackNodeOfChar * newNode = (StackNodeOfChar *) malloc(sizeof(StackNodeOfChar));
    if(newNode == NULL){
        printf("no space for StackNodeOfChar!\n");
        exit(-22);
    }
    // ��������
    newNode->data = addElem;
    // ����ջ��С
    stack->size += 1;
    // �����ڴ���ϵ
    newNode->pointer = stack->top;
    // ջ������
    stack->top = newNode;
}

/* ջ�������ݺ���*/
NodeType popSOC(StackOfChar * stack){
    // ץȡ����
    NodeType res = stack->top->data;
    // �ݴ��ڴ�ָ�룬�����������
    StackNodeOfChar * tempPtr = stack->top->pointer;
    // �ͷ��ڴ�
    free(stack->top);
    // ����
    stack->top = tempPtr;
    // ���´�С
    stack->size -= 1;
    return res;
}

/* ɾ���ƽڵ㣬���ջ����*/
void deleteStackOfChar(StackOfChar * stack){
    // ֱ���ͷ��ڴ�
    free(stack->bottom);
    free(stack);
    // ��ӡ��ʾ��Ϣ
    //printf("delete stack of char success\n");
}

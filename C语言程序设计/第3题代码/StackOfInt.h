/* ��ͷ�ļ�����ջ�ṹ������װ����ջ����غ���
 * ��ջ����ջ���п�,�Լ�����ʼջ�ͷ�*/

// ��������ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>

// �궨�岼��ֵ
#define Ture 1
#define False 0

// ���������������������
typedef int Status;
typedef int NodeTypeSOI;

// ����ջ�ڵ�ṹ
typedef struct sNode{
    // ����ֵ
    NodeTypeSOI data;
    // ָ��
    struct sNode * pointer;
}StackNodeOfInt;

// ����ջ�ṹ
typedef struct Stack{
    // ջ��
    StackNodeOfInt * bottom;
    // ջ��
    StackNodeOfInt * top;
    // ջ��С
    Status size;
}StackOfInt;


/* ������ջ����*/
StackOfInt * createStackOfInt()
{
    // ��ʽ�����ջ�ڴ棬����ӡ��ʾ��Ϣ
    StackOfInt * newStack =(StackOfInt *) malloc(sizeof(StackOfInt));
    if(newStack == NULL){
        printf("there is no space for stack of int!\n");
        // δ����ɹ����˳�
        exit(-12);
    }
    // ���ó�ʼֵ
    newStack->size = 0;
    // ��ʽ�����ƽڵ��ڴ棬ʧ�ܴ�ӡ��Ϣ
    newStack->bottom = newStack->top = (StackNodeOfInt *) malloc(sizeof(StackNodeOfInt));
    if(newStack->bottom == NULL){
        printf("there is no space for node!\n");
        exit(-22);
    }
    // ��ջ���ƽڵ��ֵ
    newStack->bottom->data = -12;
    // ���ش�����ջָ��
    return newStack;
}

/* ջ�пպ���*/
Status isEmptySOI(StackOfInt * stack)
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
void pushSOI(StackOfInt * stack , NodeTypeSOI addElem)
{
    // ��ʽ�����½ڵ��ڴ棬����ʧ�ܴ�ӡ��Ϣ���˳�
    StackNodeOfInt * newNode = (StackNodeOfInt *) malloc(sizeof(StackNodeOfInt));
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
NodeTypeSOI popSOI(StackOfInt * stack){
    // ץȡ����
    NodeTypeSOI res = stack->top->data;
    // �ݴ��ڴ�ָ�룬�����������
    StackNodeOfInt * tempPtr = stack->top->pointer;
    // �ͷ��ڴ�
    free(stack->top);
    // ����
    stack->top = tempPtr;
    // ���´�С
    stack->size -= 1;
    return res;
}

/* ɾ���ƽڵ㣬���ջ����*/
void deleteStackOfInt(StackOfInt * stack){
    // ֱ���ͷ��ڴ�
    free(stack->bottom);
    free(stack);
    // ��ӡ��ʾ��Ϣ
    //printf("delete stack success\n");
}

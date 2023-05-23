/* ��ͷ�ļ���Ҫ���ɹ��ܺ���
 * ��װ�ӿ��Թ�����*/

// �����Զ���ͷ�ļ��ͱ�׼���ͷ�ļ�
#include "StackOfChar.h"
#include "StackOfInt.h"
#include <string.h>
#include <ctype.h>

// �궨�������
#define MaxNum 1000

// ������Ԫ����������
typedef char ElementType;

// �����ַ��б�
ElementType sourceList[MaxNum];
// ������������ʽ�б�
ElementType destList[MaxNum];
// �����������ַ�ջ
StackOfChar * opStack;
// ������������ջ
StackOfInt * calStack;

// ����ʽ����
int lenDest = 0;
// ������
int calRes = 0;

/* ��ʼ���ṹ����*/
void initializeAll()
{
    // ��ʼ�����б�
    for(int i = 0 ; i < MaxNum ; i ++){
        sourceList[i] = '\0';
        destList[i] = '\0';
    }
    // �����ַ�ջ
    opStack = createStackOfChar();
}

/* ץȡ��ʼ����ʽ*/
void getSourceData()
{
    // ���ó�ʼ������
    initializeAll();
    // ��ӡ��ʾ��Ϣ
    printf("please enter your calculations:\n");
    // ���벢��ʾ
    gets(sourceList);
    printf("OK , I get it:\n");
    printf("%s\n",sourceList);
}

/* �ж��ַ��Ƿ������������*/
Status operatorJud(ElementType ope)
{
    // ֱ��if�ж�
    if(ope == '(' || ope == ')' || ope == '+' || ope == '-' || ope == '*' || ope == '/'){
        return Ture;
    }
    else return False;
}

/* �Ƚ�������ȼ�����
 * ǰ�Ⱥ�ߣ���True
 * ��֮����False*/
Status operatorCmp(ElementType ope , ElementType popOpe)
{
     /* ���ñȽ��߼�
      * ( + - * / ֮����бȽ�*/
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

/* �Բ��������г���ջ��������
 * �ɽ��еݹ����*/
void operatorManage(ElementType ope)
{
    // ��������������
    ElementType getOpe;
    /* �����߼��Ե����Ĳ������ͱ����������в���
     * ��������ʽ
     * �� ��ջ*/
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
            // �ظ��ݹ���ã�ֱ����ջ�ɹ�
            operatorManage(ope);
        }
    }
}

/* ��ʼ���ʽ�ַ���������*/
void elementManage()
{
    // �õ����ȣ���������
    int lenSource = strlen(sourceList);
    for(int i = 0; i < lenSource; i++){
        // �����ַ�ֱ�ӽ������ձ��ʽ
        if(isdigit(sourceList[i])){
            destList[lenDest++]= sourceList[i];
        }
        // ����������߼��жϣ���Ӧ����
        else if(operatorJud(sourceList[i])){
            operatorManage(sourceList[i]);
        }
        // �޳��������������
        else ;
    }
    // ջ�ǿգ���������Ԫ��
    while(isEmptySOC(opStack) == False){
        destList[lenDest++] = popSOC(opStack);
    }
    // �õ�����ʽ����ӡ��ʾ
    printf("the nifix expression of it is:\n%s\n",destList);
    // ���ջ�ڴ�
    deleteStackOfChar(opStack);
}

/* ������������������Ԫ�ؼ�����*/
int calByOpe(int numUp , int numDown , ElementType operator)
{
    // ������㣬������������
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

/* �������ձ��ʽ�������*/
void calculateRes()
{
    // ��������ջ����������
    calStack = createStackOfInt();
    // �������ʽ����
    for(int i = 0 ; i < lenDest ; i++){
        if(isdigit(destList[i])){
            // ���ֽ�ջ
            pushSOI(calStack,destList[i]-'0');
        }
        // �����������������������
        else {
            int digit1 = popSOI(calStack) ;
            int digit2 = popSOI(calStack) ;
            int tempRes = calByOpe(digit1,digit2,destList[i]);
            // ��������ջ
            pushSOI(calStack,tempRes);
        }
    }
    // ���ս���������������
    calRes = popSOI(calStack);
    // �����ڴ�
    deleteStackOfInt(calStack);
    // ��ӡ���ս��
    printf("the answer is %d\n",calRes);
}


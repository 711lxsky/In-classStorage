/* ��Դ�ļ��������ļ���
 * main�������ڴ��ļ���*/

/* ����ϵͳͷ�ļ�*/
#include "System.h"

int main(void)
/* ���������*/
{
    /* ϵͳδ��ʼ����������غ������г�ʼ��*/
    if(initializeSystemJud == NULL){
        setIniSysJud();
        initializeSystem();
    }
    /* ��ʼ���������ò˵�����*/
    initializeMenu();
    //realDeleteAllPerson(manager);
    return 0;
}

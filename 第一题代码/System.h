/* ��ͷ�ļ���������"Menu.h"��"MainFunction"�Ĺ���
 * ��ΪΨһϵͳͷ�ļ�*/

/* �����Լ���д��ͷ�ļ�*/
#include "Menu.h"
#include "MainFunction.h"

/* ����ȫ��ϵͳ��ʼ���жϱ���������ϵͳ��ʼ��*/
static int * initializeSystemJud = NULL;
/* ����ȫ����ϵ�˹���Ա���������Կ���ϵͳ����*/
static PersonManage * manager = NULL;

/* ����ȫ�ֲ���ѡ��ö�ٱ���
 * ����һһ��Ӧ��ع���ѡ��*/
enum option{Exit,Enter,Del,List,Search,Save,Load,Renew};

void setIniSysJud()
/* ��initializeSystemJud ������������*/
{
    /* ��ʾ�����ڴ�*/
    initializeSystemJud = (int *) malloc(sizeof(int));
    /* ֵ�� 1 */
    * initializeSystemJud = 1 ;
}

void initializeSystem()
/* ϵͳ��ʼ��*/
{
    /* ����API�ӿڣ����ع���Ա*/
    manager = loadManage();
}

void initializeMenu()
/* �˵���ʼ����
 * ���û�ѡ��Ĺ��ܽ��к�������*/
{
    /* �����˳��˵�����*/
    int getExit = 0;
    /* ��ʼѭ��������ϵͳ*/
    while (getExit == 0) {
        /* ���幦��ѡ�����*/
        int GetOption = -1;
        /* չʾ���˵��������û�����*/
        getMenu();
        /* �����û�ѡ��Ĺ���*/
        scanf("%d", &GetOption);
        /* ��Ӧѡ��Ĺ���һһ��ת*/
        switch (GetOption) {
            /* �˳����ܣ�
             * ��getExit ��1��������ѭ��*/
            case Exit:
                getExit = 1;
                break;
                /* ¼�빦�ܣ�����enter�ӿ�*/
            case Enter:
                enter(manager);
                continueMenu();
                break;
                /* ɾ�����ܣ�����del�ӿ�*/
            case Del:
                del(manager);
                continueMenu();
                break;
                /* ��ʾ���ܣ�����list�ӿ�*/
            case List:
                list(manager);
                continueMenu();
                break;
                /* ��ѯ���ܣ�����search�ӿ�*/
            case Search:
                search(manager);
                continueMenu();
                break;
                /* ���湦�ܣ�����save�ӿ�*/
            case Save:
                save(manager);
                continueMenu();
                break;
                /* ���ع��ܣ�����load�ӿ�*/
            case Load:
                load(manager);
                continueMenu();
                break;
                /* �ָ���������*/
            case Renew:
                fakeDeleteAllPerson(manager);
                break;
                /* �û�û��������Ч����*/
            default:
                printf("û�д�ѡ�\n");
        }
    }
    /* �˳��˵�*/
    exitMenu();
}

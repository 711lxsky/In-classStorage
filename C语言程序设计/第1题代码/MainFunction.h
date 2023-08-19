/*��ͷ�ļ���ϵͳ��������
 * ����������ʽ�ṹ������ṹ
 * ������ɾ�Ĳ鹦��*/


/*������ر�׼��*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* �궨����ϵ�˴洢����*/
#define PersonCapacity 100
/* �궨�������ַ�����*/
#define NameSize 22
/* �궨���Ա��ַ�����*/
#define GenderSize 12
/* �궨��绰�����ַ�����*/
#define PhoneNumberSize 12

/* ȫ�־�̬����ָ�������
 * �Ե�ǰϵͳ��ϵ���������м���*/
static int * PersonNum = NULL;


/* ������ϵ�� ˫������ṹ �����Զ�������*/
typedef struct PersonNode
{
    /* ��ϵ������*/
    char name[NameSize];
    /* ��ϵ���Ա�*/
    char gender[GenderSize];
    /* ��ϵ�˵绰����*/
    char phoneNumber[PhoneNumberSize];
    /* ǰָ��*/
    struct PersonNode * prev;
    /* ��ָ��*/
    struct PersonNode * next;
}Person;

/* ������ϵ�˹���Ա�ṹ*/
typedef struct TraceNode
{
    /* traceMap ����Ϊ��ϵ��ָ�����飬
     * ���������ʽ��������й���*/
    Person * traceMap[PersonCapacity];
    /* stateMap�������Ը��ٶ�Ӧ��ϵ�˽ڵ�״̬
     * �ж�����ϵ����Ϣ�Ƿ�ɾ��
     * ��ɾ������0����ʾ����д����Ϣ
     * ��û��ɾ����Ϊ1����ʾ�˴����ݲ��ɸ���*/
    int stateMap[PersonCapacity];
}PersonManage;

void initializePersonNum()
/* ��PersonNum��ʼ��*/
{
    /* malloc��ʽ�����ڴ�*/
    PersonNum = (int *) malloc(sizeof(int));
    /* �� PersonNum ����ֵ*/
    * PersonNum = 0 ;
}

void initializeOnePerson(Person* person)
/* ��Person�ڵ�����ʼ����
 * ����name��gender�ַ�������Ϊ'\0'��
 * ����phoneNumber�ַ�������Ϊȫ0��
 * ���õ�ǰ�ڵ�ǰ��ָ��Ϊ��*/
{
    /* �ֱ��name��gender��phoneNumber����memset���������������� */
    memset(person->name ,'\0' , sizeof(char)*(NameSize));
    //ptr->name[NameSize-1] = '\0' ;
    memset(person->gender,'\0', sizeof(char)*(GenderSize));
    //ptr->gender[GenderSize-1] ='\0' ;
    memset(person->phoneNumber ,'0' , sizeof(char) * (PhoneNumberSize-1));
    person->phoneNumber[PhoneNumberSize-1] = '\0' ;
    /* ����ǰ��ָ��*/
    person->prev = NULL ;
    person->next = NULL ;

}

void fakeInitializeOnePerson(Person* person)
/* ��Person�ڵ���������ʼ������
 * ������name��gender��phoneNumberԭ�����ݣ�����д���ʼֵ*/
{
    memset(person->name ,'\0' , sizeof(char)*(NameSize-1));
    //ptr->name[NameSize-1] = '\0' ;
    memset(person->gender,'\0', sizeof(char)*(GenderSize-1));
    //ptr->gender[GenderSize-1] ='\0' ;
    memset(person->phoneNumber ,'0' , sizeof(char) * (PhoneNumberSize-1));
    person->phoneNumber[PhoneNumberSize-1] = '\0' ;

}

Person* createOnePerson()
/* ����������Person�ڵ�*/
{
    /* malloc��ʽ����Person�ڵ��ڴ棬���⺯���������Ч*/
    Person *ptr =  (Person *) malloc(sizeof(Person));
    if ( ptr != NULL){
        /* �����ڴ�ɹ�
         * ��ӡ��Ϣ�����г�ʼ��*/
        //printf("��ϵ���ڴ�����ɹ�!\n");
        initializeOnePerson(ptr);
    }
    else {
        /* �����ڴ�ʧ��
         * ��ӡ��Ϣ���˳�*/
        printf("���ź�����ϵ�������ڴ�����ʧ��!\n");
        exit(-1);
    }
    return  ptr ;
}

void createPersons(PersonManage* manager)
/* ����PersonManage��������������*/
{
    /* ����ͷ���*/
    manager->traceMap[0] = createOnePerson();
    manager->stateMap[0] = 0 ;
    for(int i = 1 ; i < PersonCapacity ; ++i){
        /* ������̽ڵ㣬��������˫������*/
        manager->traceMap[i-1]->next = manager->traceMap[i] = createOnePerson();
        manager->traceMap[i]->prev = manager->traceMap[i-1];
        /* ����stateMap��Ϣ*/
        manager->stateMap[i] = 0 ;
    }
    /*�˴�Ϊ����id���٣�ʹ��������ʽ
     * һ��ʹ������ķ�ʽ�������ӣ�
     * Person * head = createOnePerson();
     * for(int i = 1 ; i < PersonCapacity ; ++i{
     * Person * rep = createOnePerson();
     * head->next = rep; rep->prev = head; head = head->next;
     * }
     * */
}

PersonManage * loadManage()
/* ���ز���ʼ��PersonManage�ṹ
 * �ǹ���ʵ�ֵĻ�����ʼ*/
{
    /* ����PersonNum*/
    initializePersonNum();
    /* ͬ����ʽ�����ڴ�*/
    PersonManage * manage = (PersonManage *) malloc(sizeof(PersonManage));

    if(manage != NULL){
        /* �����ɹ�����ʼ��*/
        printf("������ϵ�˹���Ա�ڴ�ɹ���\n");
        createPersons(manage);
    }
    else {
        /* ����ʧ�ܣ��˳�*/
        printf("�������Ա�ڴ�ʧ�� ��\n");
        exit(-1);
    }
    /* ���ش�����PersonManage*/
    return manage;
}

int findJud( PersonManage * manager , Person * person)
/* ���ҽ�Ҫ�½�����ϵ���Ƿ��Ѿ���ϵͳ�д���
 * ��int��ʽ���ؽ��ֵ*/
/* ע�⣬���غ�������ظ���Ϣʱ����phoneNumberΪ�ؼ���
* ����ʵ���������������ͬһ����ӵ�ж����ϵ�绰*/
{
    /* �����ж�ֵ*/
    int jud = 0 ;
    /* ʹ��forѭ��������PersonManage��������*/
    for(int i = 0 ; i < PersonCapacity ; i++){
        /* ����strcmp������
        * ���½���ϵ�˵绰����Ϊ���ݣ��ж���Ϣ�Ƿ��ظ�*/
        if(strcmp(person->phoneNumber,manager->traceMap[i]->phoneNumber) == 0){
            /* ���ظ���jud��1��������ѭ��*/
            jud = 1 ;
            break;
        }
    }
    /* ���������жϽ��*/
    return jud;
}


void addPerson(Person * personDes , Person * personSou)
/* �½���ϵ����Ϣ*/
{
    /* ����strcpy��������ϵ����Ϣ���и��ƣ�д��ϵͳPerson�ڵ�*/
    strcpy(personDes->name,personSou->name);
    strcpy(personDes->gender,personSou->gender);
    strcpy(personDes->phoneNumber,personSou->phoneNumber);
}


void fakeDeleteOnePerson(int index , PersonManage * manager)
/* ����indexָ���manager����Ա ����ɾ����ϵ�ˣ�
 * ʵ����ֻ�Ƕ�Person���ݸ�д��û���ͷ�ɾ���ڴ�*/
{
    /* ���������ʼ������*/
    fakeInitializeOnePerson(manager->traceMap[index]);
    /* stateMap ״̬��Ϣ���£������ٴ�¼��*/
    manager->stateMap[index] = 0 ;
}

void fakeDeleteAllPerson(PersonManage * manager)
/* ����ɾ��������ϵ��
 * �����ϵͳ�����ָ���������*/
{
    /* ����ϵ����������*/
    (*PersonNum) = 0 ;
    /* ����ѭ�������ú���*/
    for(int i = 0 ; i < PersonCapacity ; ++i){
        fakeDeleteOnePerson(i,manager);
    }
    /* ��ӡ��ʾ��Ϣ*/
    printf("\n�ָ��������óɹ� !\n");
    printf("��ǰϵͳ������ϵ����Ϣ�����\n");
}

void realDeleteAllPerson(PersonManage * manager)
/* ��ʵɾ��������ϵ�ˡ�����Ա��Ϣ
 * ���ϵͳ�ڴ沢�ͷ�
 * ͬ�����˺���ֻ�����ӿڵ��ã��Թ����Խ׶��ͷ��ڴ棬����й¶
 * ��û����ϵͳ��ʹ��*/
{
    /* ����ͷ�PersonNum */
    free(PersonNum);
    /* ����β���*/
    Person * rep = manager->traceMap[PersonCapacity-1];
    /* ʹ��ѭ�����Ӻ���ǰ��������
    * ����ͷ�Person����ӡ��ʾ��Ϣ*/
    while(rep != NULL){
        Person * Prev = rep->prev;
        printf("deleting...\n");
        free(rep);
        rep = Prev;
    }
    /* ����ͷ�PersonManage*/
    free(manager);
}

void enter(PersonManage * manager)
/* ¼�빦�ܺ���*/
{
    /* index��Ϊ�±�*/
    int index = 0 ;
    /* ѭ����������stateMap���鿴����Person�ڵ�¼��״̬*/
    while( index < PersonCapacity && manager->stateMap[index] != 0){
        index++;
    }
    if(index == PersonCapacity) {
        /* ���������index��PersonCapacity��С��ȣ�˵��û��Person�ڵ�ɹ�¼��
        * ��ӡ��ʾ��Ϣ */
        printf("��Ǹ �� ͨѶ¼�洢�ռ��Ѿ����ˣ��������½���ϵ���ˣ�");
    }
    else {
        /* ��֮��������½���ϵ����Ϣ׼������*/
        /* ����һ��Person�ṹ�������ݴ�¼�����Ϣ*/
        Person * tempPerson = createOnePerson();
        printf("\n��������Ϊ���½���ϵ�ˣ�\n");
        printf("�����μ��� ��ϵ���������Ա𡢵绰����\n");
        printf("���������Ա𡢵绰��������֮��ʹ�ûس��ָ�����\n ");
        /* ���û��������Ϣд���ݴ�Person��*/
        scanf("%s", tempPerson->name);
        scanf("%s", tempPerson->gender);
        scanf("%s", tempPerson->phoneNumber);
        /* ����fineJud�������Լ�����أ�
         * ���ؾͲ��Ὣ��Ϣд��ϵͳ����*/
        if(findJud(manager,tempPerson) != 0){
            /* ��ӡ�ظ���Ϣ��ʾ*/
            printf("��Ǹ������ϵ���Ѵ��ڣ�\n");
        }
        /* ��֮�����û����Ϣ�ظ���
         * �����addPerson����Ϣд��ϵͳ����*/
        else {
            addPerson(manager->traceMap[index],tempPerson);
            /* stateMao״̬����*/
            manager->stateMap[index] = 1 ;
            /* PersonNum ����*/
            (*PersonNum)++;
            /* ��ӡ�ɹ�¼����ʾ��Ϣ*/
            printf("�½���ϵ�˳ɹ����������洢�� %d ����ϵ�ˣ� \n" ,*PersonNum);
        }
        /* �ͷ��ݴ����ڴ棬�����ڴ�й¶*/
        free(tempPerson);
    }
}

void del(PersonManage * manager)
/* ɾ����ϵ����Ϣ����
 * ������Ϊ�ؼ���
 * ��ɾ������Ŀ����ϵ�˵���Ϣ*/
{
    /* ��ӡ��ʾ��Ϣ*/
    printf("\nĿǰ����ִ�е���ɾ����ϵ�ˣ�\n");
    printf("����������Ҫɾ������ϵ��������\n");
    /* �����û�����������ַ���*/
    char name[NameSize] = {'\0'};
    /* ����Ŀ������*/
    scanf("%s" , name);
    /* index�±����*/
    int index = 0 ;
    /* ptrΪͷ�ڵ㣬���������Ҫ*/
    Person * ptr = manager->traceMap[0];
    /* ���ñ����ж��Ƿ�ɾ������Ϣ*/
    int delJud = 0 ;
    /* ѭ����������Ŀ����ϵ��*/
    while(ptr != NULL){
        /* �ж�������Ϣ�Ƿ����ɸѡҪ��
         * ���������Person�ڵ���Ϣ���*/
        if(strcmp(name,ptr->name) == 0){
            fakeDeleteOnePerson(index,manager);
            /* ����PersonNum*/
            (*PersonNum)--;
            /* ����delJud*/
            delJud ++ ;
        }
        /* ����ѭ��ָ��*/
        ptr = ptr->next ;
        /* ����index�±�*/
        index ++ ;
    }
    /* ���delJudΪ0,˵��û���ҵ�Ŀ����ϵ��*/
    if(delJud == 0){
        /* ��ӡ��ʾ��Ϣ*/
        printf("���ź�������û���ҵ������ϵ�ˣ�\n");
    }
    /* ��֮��˵���ҵ���Ŀ����ϵ��*/
    else{
        /* ��ӡ��ʾ��Ϣ*/
        printf("ɾ����ϵ�˳ɹ�����������ͨѶ¼���� %d ����ϵ�ˣ� \n" ,*PersonNum);
    }
}

void list(PersonManage * manager)
/* ��ʾ������ϵ����Ϣ����*/
{
    /* ��ӡ��ʾ��Ϣ*/
    printf("\n���ڽ�Ϊ��ִ�д�ӡ��ϵ�˹��ܣ�\n");
    /* index�±����*/
    int index = 0 ;
    /* num���Լ�������¼��ӡ��ϵ������*/
    int num = 0 ;
    /* ѭ������*/
    while (index < PersonCapacity){
        /* ��stateMap��0 ��˵����Person�ڵ�д������Ϣ�������ӡ*/
        if(manager->stateMap[index] != 0){
            /* ����num*/
            num++;
            /* ��ӡ��Ϣ*/
            printf("��%dλ��ϵ��������[%s]\n" , num,manager->traceMap[index]->name);
            printf("�Ա� [%s]\n" ,manager->traceMap[index]->gender);
            printf("�绰���룺 [%s]\n" , manager->traceMap[index]->phoneNumber);
        }
        /* �±����*/
        index++;
    }
    /* ��ӡ�ܽ���Ϣ*/
    printf("��Ϊ����ӡ�� %d ����ϵ����Ϣ \n" ,num);
}


void search(PersonManage * manager)
/* ��ϵ����Ϣ��ѯ����
 * ��nameΪ�ؼ���*/
{
    /* �����û������*/
    char personName[NameSize] = {'\0'};
    /* ��ӡ������Ϣ*/
    printf("\n����Ϊ��ִ�в�ѯ��ϵ�˹���\n");
    printf("�������Ҫ��ѯ����ϵ��������\n");
    /* ����Ŀ����ϵ������*/
    scanf("%s" , personName);
    /* �����ѯ�ɹ��жϱ���*/
    int findJud = 0 ;
    /* ͷ�ڵ�*/
    Person * person = manager->traceMap[0];
    /* ѭ������*/
    while (person != NULL){
        /* ��������ɸѡ*/
        if(strcmp(personName , person->name) == 0){
            /* ��ѯ�ɹ���findJud ����*/
            findJud ++ ;
            /* ��ӡĿ����ϵ����Ϣ*/
            printf("\n�����������ҵ���ϵ����Ϣ��\n");
            printf("��ϵ��������[%s]\n" , person->name);
            printf("�Ա�[%s]\n" , person->gender);
            printf("�绰���룺[%s]\n" , person->phoneNumber);
        }
        /* ����ѭ��ָ��*/
        person = person->next;
    }
    /* ����û���ҵ�Ŀ��*/
    if(findJud == 0){
        /* ��ӡ��ʾ��Ϣ*/
        printf("���ź���û���ҵ������ϵ��!\n");
    }
}

void save(PersonManage * manager)
/* ��ϵ����Ϣ���溯��
 * ��txt�ı��ļ���ʽ���д洢
 * Ĭ���ڵ�ǰĿ¼���б���*/
{
    /* ���屣���ļ������洢·�����ַ���*/
    char saveFileName[64] = {'\0'};
    /* ��ӡ������ʾ��Ϣ*/
    printf("\n����Ϊ��ִ�е�����ϵ���ļ����湦��!\n");
    printf("���ǽ���������ϵ����Ϣ�洢������ָ���ĵ��ļ���\n");
    printf("����������ָ�����ļ�����ʹ��Ӣ�ģ���.txt��β����\n");
    /* ��ȡ�û������Ŀ���ļ���*/
    scanf("%s" , saveFileName);
    /* �����ļ���дָ�룬����Ŀ���ļ�
     * ��Ŀ���ļ������ڣ���ᴴ��һ��*/
    FILE * inFilePtr = fopen(saveFileName , "a+");
    /* inFilePtrΪ��ָ�룬˵����ʧ��*/
    if(inFilePtr == NULL){
        /* ��ӡ��ʾ��Ϣ*/
        printf("�����ļ���ʧ�ܣ�");
    }
    /* ��֮���򿪳ɹ�*/
    else {
        /* ��ӡ��ʾ��Ϣ*/
        printf("�����ļ��ɹ��򿪣�����Ϊ��������ϵ�ˣ�\n");
        /* ѭ������ϵͳ����*/
        for(int index = 0 ; index < PersonCapacity ; index++){
            /* �жϵ�ǰPerson�ڵ��Ƿ�����Ϣ������д���ļ�*/
            if(manager->stateMap[index] != 0){
                /* �����ļ�д������������Ϣд��*/
                fputs(manager->traceMap[index]->name , inFilePtr);
                fputs("\n" , inFilePtr);
                fputs(manager->traceMap[index]->gender , inFilePtr);
                fputs("\n" , inFilePtr);
                fputs(manager->traceMap[index]->phoneNumber , inFilePtr);
                fputs("\n" , inFilePtr);
            }
        }
        /* ������������ӡ��ʾ��Ϣ*/
        printf("����������ϵ�˳ɹ���\n");
    }
    /* �ر�Ŀ���ļ�*/
    fclose(inFilePtr);
}

void load(PersonManage * manager)
/* ��ϵ����Ϣ���ݼ��غ���
 * Ĭ�ϴӵ�ǰĿ¼��Ѱ��Ŀ���ļ�
 * ʹ���ı��ļ���ʽ*/
{
    /* ��ӡ������Ϣ*/
    printf("\n����Ϊ��ִ����ϵ���ļ����ݼ��ع��ܣ�\n");
    printf("����������Ҫ��ȡ����ϵ���ı��ļ���(��.txt��β����\n");
    /* ����Ŀ���ļ����ַ���*/
    char loadFileName[64] = {'\0'};
    /* ����Ŀ���ļ���*/
    scanf("%s" , loadFileName);
    /* �����ļ�ָ�룬����Ŀ���ļ�
     * Ŀ���ļ����������Զ�����*/
    FILE * readFilePtr = fopen(loadFileName , "a+");
    /* ��ʧ��*/
    if(readFilePtr == NULL){
        /* ��ӡ��ʾ��Ϣ*/
        printf("��Ǹ�������޷����ش��ļ���\n");
    }
    /* �򿪳ɹ�*/
    else {
        /* ��ӡ��ʾ��Ϣ*/
        printf("Ŀ���ļ��򿪳ɹ���\n");
        /* �������ݼ�������¼����*/
        int loadPersonNum = 0 ;
        /* ѭ��ɨ��Ŀ���ļ�*/
        while (feof(readFilePtr) == 0){
            /* �½��ݴ�Person�ڵ�*/
            Person * tempPerson = createOnePerson();
            /* �����ļ�������������Ϣ�����ݴ���*/
            fscanf(readFilePtr,"%s%s%s",tempPerson->name,tempPerson->gender,tempPerson->phoneNumber );
            /* ���� ��ϵͳ������ �����Ϣλ�� �� ����*/
            int addPos = 0 ;
            /* �����ҵ�����д����Ϣ��ϵͳPerson�ڵ�*/
            while( addPos < PersonCapacity && manager->stateMap[addPos] != 0){
                /* ����addPos�±�*/
                addPos++;
            }
            /* ��addPos�ﵽPersonCapacity��
             * ˵��ϵͳ������û�п�д��ڵ�
             * ֱ������ѭ��*/
            if(addPos == PersonCapacity){
                break;
            }
            /* ���Ƚ��в��أ�ͨ������ʽ�����ϵ����Ϣ*/
            if(findJud(manager,tempPerson) == 0){
                /* ����addPerson��������ȡ������ϵ����Ϣд��ϵͳ����*/
                addPerson(manager->traceMap[addPos],tempPerson);
                /* stateMap����*/
                manager->stateMap[addPos] = 1;
                /* PersonNum����*/
                (*PersonNum)++;
                /* ���ݼ���������*/
                loadPersonNum++;
            }
            /* �ͷ��ݴ����ڴ�*/
            free(tempPerson);

        }
        /* ������ϣ���ӡ��ʾ��Ϣ*/
        printf("��ϵ���ļ����ݼ�����ɣ�\n");
        printf("����Ϊ����ȡ�� %d ����ϵ����Ϣ������ͨѶ¼ϵͳ�й��� %d ����ϵ��\n",loadPersonNum,*PersonNum);
    }
    /* �ر��ļ�*/
    fclose(readFilePtr);
}



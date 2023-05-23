/*此头文件是系统主功能区
 * 定义链表链式结构和数组结构
 * 集成增删改查功能*/


/*引入相关标准库*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 宏定义联系人存储数量*/
#define PersonCapacity 100
/* 宏定义姓名字符数量*/
#define NameSize 22
/* 宏定义性别字符数量*/
#define GenderSize 12
/* 宏定义电话号码字符数量*/
#define PhoneNumberSize 12

/* 全局静态整数指针变量，
 * 对当前系统联系人数量进行计数*/
static int * PersonNum = NULL;


/* 定义联系人 双向链表结构 并加以二次命名*/
typedef struct PersonNode
{
    /* 联系人姓名*/
    char name[NameSize];
    /* 联系人性别*/
    char gender[GenderSize];
    /* 联系人电话号码*/
    char phoneNumber[PhoneNumberSize];
    /* 前指针*/
    struct PersonNode * prev;
    /* 后指针*/
    struct PersonNode * next;
}Person;

/* 定义联系人管理员结构*/
typedef struct TraceNode
{
    /* traceMap 定义为联系人指针数组，
     * 以数组的形式对链表进行管理*/
    Person * traceMap[PersonCapacity];
    /* stateMap数组用以跟踪对应联系人节点状态
     * 判断其联系人信息是否删除
     * 若删除则置0，表示可以写入信息
     * 若没有删除则为1，表示此处内容不可更改*/
    int stateMap[PersonCapacity];
}PersonManage;

void initializePersonNum()
/* 对PersonNum初始化*/
{
    /* malloc显式申请内存*/
    PersonNum = (int *) malloc(sizeof(int));
    /* 对 PersonNum 赋初值*/
    * PersonNum = 0 ;
}

void initializeOnePerson(Person* person)
/* 对Person节点作初始化，
 * 设置name、gender字符串内容为'\0'，
 * 设置phoneNumber字符串内容为全0，
 * 设置当前节点前后指针为空*/
{
    /* 分别对name、gender、phoneNumber调用memset函数进行内容设置 */
    memset(person->name ,'\0' , sizeof(char)*(NameSize));
    //ptr->name[NameSize-1] = '\0' ;
    memset(person->gender,'\0', sizeof(char)*(GenderSize));
    //ptr->gender[GenderSize-1] ='\0' ;
    memset(person->phoneNumber ,'0' , sizeof(char) * (PhoneNumberSize-1));
    person->phoneNumber[PhoneNumberSize-1] = '\0' ;
    /* 设置前后指针*/
    person->prev = NULL ;
    person->next = NULL ;

}

void fakeInitializeOnePerson(Person* person)
/* 对Person节点进行虚拟初始化设置
 * 即覆盖name、gender、phoneNumber原有内容，重新写入初始值*/
{
    memset(person->name ,'\0' , sizeof(char)*(NameSize-1));
    //ptr->name[NameSize-1] = '\0' ;
    memset(person->gender,'\0', sizeof(char)*(GenderSize-1));
    //ptr->gender[GenderSize-1] ='\0' ;
    memset(person->phoneNumber ,'0' , sizeof(char) * (PhoneNumberSize-1));
    person->phoneNumber[PhoneNumberSize-1] = '\0' ;

}

Person* createOnePerson()
/* 创建并返回Person节点*/
{
    /* malloc显式申请Person节点内存，避免函数外调用无效*/
    Person *ptr =  (Person *) malloc(sizeof(Person));
    if ( ptr != NULL){
        /* 申请内存成功
         * 打印消息并进行初始化*/
        //printf("联系人内存申请成功!\n");
        initializeOnePerson(ptr);
    }
    else {
        /* 申请内存失败
         * 打印消息并退出*/
        printf("很遗憾，联系人所需内存申请失败!\n");
        exit(-1);
    }
    return  ptr ;
}

void createPersons(PersonManage* manager)
/* 借助PersonManage将链表连接起来*/
{
    /* 创建头结点*/
    manager->traceMap[0] = createOnePerson();
    manager->stateMap[0] = 0 ;
    for(int i = 1 ; i < PersonCapacity ; ++i){
        /* 创建后继节点，建立链表双向连接*/
        manager->traceMap[i-1]->next = manager->traceMap[i] = createOnePerson();
        manager->traceMap[i]->prev = manager->traceMap[i-1];
        /* 设置stateMap信息*/
        manager->stateMap[i] = 0 ;
    }
    /*此处为了有id跟踪，使用数组形式
     * 一般使用链表的方式建立连接，
     * Person * head = createOnePerson();
     * for(int i = 1 ; i < PersonCapacity ; ++i{
     * Person * rep = createOnePerson();
     * head->next = rep; rep->prev = head; head = head->next;
     * }
     * */
}

PersonManage * loadManage()
/* 加载并初始化PersonManage结构
 * 是功能实现的基础开始*/
{
    /* 设置PersonNum*/
    initializePersonNum();
    /* 同理，显式申请内存*/
    PersonManage * manage = (PersonManage *) malloc(sizeof(PersonManage));

    if(manage != NULL){
        /* 创建成功，初始化*/
        printf("申请联系人管理员内存成功！\n");
        createPersons(manage);
    }
    else {
        /* 创建失败，退出*/
        printf("申请管理员内存失败 ！\n");
        exit(-1);
    }
    /* 返回创建的PersonManage*/
    return manage;
}

int findJud( PersonManage * manager , Person * person)
/* 查找将要新建的联系人是否已经在系统中存在
 * 以int形式返回结果值*/
/* 注意，查重函数检查重复信息时，以phoneNumber为关键词
* 根据实际生活情况，允许同一个人拥有多个联系电话*/
{
    /* 存在判断值*/
    int jud = 0 ;
    /* 使用for循环并借助PersonManage遍历链表*/
    for(int i = 0 ; i < PersonCapacity ; i++){
        /* 调用strcmp函数，
        * 以新建联系人电话号码为依据，判断信息是否重复*/
        if(strcmp(person->phoneNumber,manager->traceMap[i]->phoneNumber) == 0){
            /* 若重复，jud置1，并跳出循环*/
            jud = 1 ;
            break;
        }
    }
    /* 返回最终判断结果*/
    return jud;
}


void addPerson(Person * personDes , Person * personSou)
/* 新建联系人信息*/
{
    /* 调用strcpy函数对联系人信息进行复制，写入系统Person节点*/
    strcpy(personDes->name,personSou->name);
    strcpy(personDes->gender,personSou->gender);
    strcpy(personDes->phoneNumber,personSou->phoneNumber);
}


void fakeDeleteOnePerson(int index , PersonManage * manager)
/* 借助index指向和manager管理员 虚拟删除联系人，
 * 实际上只是对Person内容覆写，没有释放删除内存*/
{
    /* 调用虚拟初始化函数*/
    fakeInitializeOnePerson(manager->traceMap[index]);
    /* stateMap 状态信息更新，可以再次录入*/
    manager->stateMap[index] = 0 ;
}

void fakeDeleteAllPerson(PersonManage * manager)
/* 虚拟删除所有联系人
 * 即清空系统链表，恢复出厂设置*/
{
    /* 将联系人数量清零*/
    (*PersonNum) = 0 ;
    /* 借助循环，调用函数*/
    for(int i = 0 ; i < PersonCapacity ; ++i){
        fakeDeleteOnePerson(i,manager);
    }
    /* 打印提示信息*/
    printf("\n恢复出厂设置成功 !\n");
    printf("当前系统所有联系人信息已清空\n");
}

void realDeleteAllPerson(PersonManage * manager)
/* 真实删除所有联系人、管理员信息
 * 清空系统内存并释放
 * 同样，此函数只保留接口调用，以供测试阶段释放内存，避免泄露
 * 并没有在系统中使用*/
{
    /* 清空释放PersonNum */
    free(PersonNum);
    /* 设置尾结点*/
    Person * rep = manager->traceMap[PersonCapacity-1];
    /* 使用循环，从后往前遍历链表，
    * 清空释放Person，打印提示信息*/
    while(rep != NULL){
        Person * Prev = rep->prev;
        printf("deleting...\n");
        free(rep);
        rep = Prev;
    }
    /* 清空释放PersonManage*/
    free(manager);
}

void enter(PersonManage * manager)
/* 录入功能函数*/
{
    /* index作为下标*/
    int index = 0 ;
    /* 循环遍历搜索stateMap，查看各个Person节点录入状态*/
    while( index < PersonCapacity && manager->stateMap[index] != 0){
        index++;
    }
    if(index == PersonCapacity) {
        /* 如果遍历完index和PersonCapacity大小相等，说明没有Person节点可供录入
        * 打印提示信息 */
        printf("抱歉 ， 通讯录存储空间已经满了，不能再新建联系人了！");
    }
    else {
        /* 反之，则进行新建联系人信息准备工作*/
        /* 创建一个Person结构，用以暂存录入的信息*/
        Person * tempPerson = createOnePerson();
        printf("\n现在正在为您新建联系人！\n");
        printf("请依次键入 联系人姓名、性别、电话号码\n");
        printf("（姓名、性别、电话号码三者之间使用回车分隔）：\n ");
        /* 将用户输入的信息写入暂存Person区*/
        scanf("%s", tempPerson->name);
        scanf("%s", tempPerson->gender);
        scanf("%s", tempPerson->phoneNumber);
        /* 利用fineJud函数加以检验查重，
         * 查重就不会将信息写入系统链表*/
        if(findJud(manager,tempPerson) != 0){
            /* 打印重复消息提示*/
            printf("抱歉，此联系人已存在！\n");
        }
        /* 反之，如果没有信息重复，
         * 则调用addPerson将信息写入系统链表*/
        else {
            addPerson(manager->traceMap[index],tempPerson);
            /* stateMao状态更新*/
            manager->stateMap[index] = 1 ;
            /* PersonNum 更新*/
            (*PersonNum)++;
            /* 打印成功录入提示信息*/
            printf("新建联系人成功！现在您存储了 %d 个联系人！ \n" ,*PersonNum);
        }
        /* 释放暂存区内存，避免内存泄露*/
        free(tempPerson);
    }
}

void del(PersonManage * manager)
/* 删除联系人信息函数
 * 以姓名为关键词
 * 将删除所有目标联系人的信息*/
{
    /* 打印提示信息*/
    printf("\n目前正在执行的是删除联系人！\n");
    printf("请输入您需要删除的联系人姓名：\n");
    /* 定义用户输入的名称字符串*/
    char name[NameSize] = {'\0'};
    /* 读入目标名字*/
    scanf("%s" , name);
    /* index下标跟踪*/
    int index = 0 ;
    /* ptr为头节点，方便遍历需要*/
    Person * ptr = manager->traceMap[0];
    /* 设置变量判断是否删除了信息*/
    int delJud = 0 ;
    /* 循环遍历搜索目标联系人*/
    while(ptr != NULL){
        /* 判断姓名信息是否符合筛选要求
         * 符合则进行Person节点信息清空*/
        if(strcmp(name,ptr->name) == 0){
            fakeDeleteOnePerson(index,manager);
            /* 更新PersonNum*/
            (*PersonNum)--;
            /* 更新delJud*/
            delJud ++ ;
        }
        /* 更新循环指针*/
        ptr = ptr->next ;
        /* 更新index下标*/
        index ++ ;
    }
    /* 如果delJud为0,说明没有找到目标联系人*/
    if(delJud == 0){
        /* 打印提示信息*/
        printf("很遗憾，我们没有找到这个联系人！\n");
    }
    /* 反之，说明找到了目标联系人*/
    else{
        /* 打印提示信息*/
        printf("删除联系人成功！现在您的通讯录中有 %d 个联系人！ \n" ,*PersonNum);
    }
}

void list(PersonManage * manager)
/* 显示所有联系人信息函数*/
{
    /* 打印提示信息*/
    printf("\n现在将为您执行打印联系人功能！\n");
    /* index下标跟踪*/
    int index = 0 ;
    /* num用以计数，记录打印联系人数量*/
    int num = 0 ;
    /* 循环遍历*/
    while (index < PersonCapacity){
        /* 若stateMap非0 ，说明此Person节点写入了信息，将其打印*/
        if(manager->stateMap[index] != 0){
            /* 更新num*/
            num++;
            /* 打印信息*/
            printf("第%d位联系人姓名：[%s]\n" , num,manager->traceMap[index]->name);
            printf("性别： [%s]\n" ,manager->traceMap[index]->gender);
            printf("电话号码： [%s]\n" , manager->traceMap[index]->phoneNumber);
        }
        /* 下标更新*/
        index++;
    }
    /* 打印总结信息*/
    printf("共为您打印了 %d 条联系人信息 \n" ,num);
}


void search(PersonManage * manager)
/* 联系人信息查询函数
 * 以name为关键词*/
{
    /* 定义用户输入的*/
    char personName[NameSize] = {'\0'};
    /* 打印交互信息*/
    printf("\n现在为您执行查询联系人功能\n");
    printf("请键入需要查询的联系人姓名：\n");
    /* 读入目标联系人姓名*/
    scanf("%s" , personName);
    /* 定义查询成功判断变量*/
    int findJud = 0 ;
    /* 头节点*/
    Person * person = manager->traceMap[0];
    /* 循环遍历*/
    while (person != NULL){
        /* 根据姓名筛选*/
        if(strcmp(personName , person->name) == 0){
            /* 查询成功，findJud 更新*/
            findJud ++ ;
            /* 打印目标联系人信息*/
            printf("\n这是您所查找的联系人信息：\n");
            printf("联系人姓名：[%s]\n" , person->name);
            printf("性别：[%s]\n" , person->gender);
            printf("电话号码：[%s]\n" , person->phoneNumber);
        }
        /* 更新循环指针*/
        person = person->next;
    }
    /* 遍历没有找到目标*/
    if(findJud == 0){
        /* 打印提示信息*/
        printf("很遗憾，没有找到这个联系人!\n");
    }
}

void save(PersonManage * manager)
/* 联系人信息保存函数
 * 以txt文本文件形式进行存储
 * 默认在当前目录进行保存*/
{
    /* 定义保存文件名（存储路径）字符串*/
    char saveFileName[64] = {'\0'};
    /* 打印交互提示信息*/
    printf("\n现在为您执行的是联系人文件保存功能!\n");
    printf("我们将把所有联系人信息存储到由您指定的的文件中\n");
    printf("现在请输入指定的文件名（使用英文，以.txt结尾）：\n");
    /* 读取用户输入的目标文件名*/
    scanf("%s" , saveFileName);
    /* 定义文件读写指针，并打开目标文件
     * 若目标文件不存在，则会创建一个*/
    FILE * inFilePtr = fopen(saveFileName , "a+");
    /* inFilePtr为空指针，说明打开失败*/
    if(inFilePtr == NULL){
        /* 打印提示信息*/
        printf("保存文件打开失败！");
    }
    /* 反之，打开成功*/
    else {
        /* 打印提示信息*/
        printf("保存文件成功打开，正在为您保存联系人！\n");
        /* 循环遍历系统链表*/
        for(int index = 0 ; index < PersonCapacity ; index++){
            /* 判断当前Person节点是否含有信息，有则写入文件*/
            if(manager->stateMap[index] != 0){
                /* 调用文件写函数，进行信息写入*/
                fputs(manager->traceMap[index]->name , inFilePtr);
                fputs("\n" , inFilePtr);
                fputs(manager->traceMap[index]->gender , inFilePtr);
                fputs("\n" , inFilePtr);
                fputs(manager->traceMap[index]->phoneNumber , inFilePtr);
                fputs("\n" , inFilePtr);
            }
        }
        /* 遍历结束，打印提示信息*/
        printf("保存所有联系人成功！\n");
    }
    /* 关闭目标文件*/
    fclose(inFilePtr);
}

void load(PersonManage * manager)
/* 联系人信息数据加载函数
 * 默认从当前目录下寻找目标文件
 * 使用文本文件形式*/
{
    /* 打印交互信息*/
    printf("\n现在为您执行联系人文件数据加载功能！\n");
    printf("请输入您需要读取的联系人文本文件名(以.txt结尾）：\n");
    /* 定义目标文件名字符串*/
    char loadFileName[64] = {'\0'};
    /* 读入目标文件名*/
    scanf("%s" , loadFileName);
    /* 定义文件指针，并打开目标文件
     * 目标文件不存在则自动创建*/
    FILE * readFilePtr = fopen(loadFileName , "a+");
    /* 打开失败*/
    if(readFilePtr == NULL){
        /* 打印提示信息*/
        printf("抱歉，我们无法加载此文件！\n");
    }
    /* 打开成功*/
    else {
        /* 打印提示信息*/
        printf("目标文件打开成功！\n");
        /* 定义数据加载量记录变量*/
        int loadPersonNum = 0 ;
        /* 循环扫描目标文件*/
        while (feof(readFilePtr) == 0){
            /* 新建暂存Person节点*/
            Person * tempPerson = createOnePerson();
            /* 调用文件读函数，将信息存入暂存区*/
            fscanf(readFilePtr,"%s%s%s",tempPerson->name,tempPerson->gender,tempPerson->phoneNumber );
            /* 定义 在系统链表中 添加信息位置 的 变量*/
            int addPos = 0 ;
            /* 遍历找到可以写入信息的系统Person节点*/
            while( addPos < PersonCapacity && manager->stateMap[addPos] != 0){
                /* 更新addPos下标*/
                addPos++;
            }
            /* 若addPos达到PersonCapacity，
             * 说明系统链表中没有可写入节点
             * 直接跳出循环*/
            if(addPos == PersonCapacity){
                break;
            }
            /* 首先进行查重，通过后正式添加联系人信息*/
            if(findJud(manager,tempPerson) == 0){
                /* 调用addPerson函数将读取到的联系人信息写入系统链表*/
                addPerson(manager->traceMap[addPos],tempPerson);
                /* stateMap更新*/
                manager->stateMap[addPos] = 1;
                /* PersonNum更新*/
                (*PersonNum)++;
                /* 数据加载量更新*/
                loadPersonNum++;
            }
            /* 释放暂存区内存*/
            free(tempPerson);

        }
        /* 加载完毕，打印提示信息*/
        printf("联系人文件数据加载完成！\n");
        printf("本次为您读取了 %d 条联系人信息，现在通讯录系统中共有 %d 个联系人\n",loadPersonNum,*PersonNum);
    }
    /* 关闭文件*/
    fclose(readFilePtr);
}



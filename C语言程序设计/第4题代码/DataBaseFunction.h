/* ��ͷ�ļ���Ҫ����ʵ�����ݿ����
 * �����Ҫ���ݿ��������*/

// ���뱾�ؿ�
#include "TableFunction.h"

/* ��ȡ���ݿ����ѡ���*/
int getDataBaseOperator(char * arg){
    if(strcmp(arg,"exit") == 0){
        return Exit;
    }
    else if(strcmp(arg,"create") == 0){
        return CreateDataBase;
    }
    else if(strcmp(arg,"drop") == 0){
        return DropDataBase;
    }
    else if(strcmp(arg,"use") == 0){
        return UseDataBase;
    }
    else {
        return Error;
    }
}

/* �˳����ݿ����*/
void exitDataBase(){
    printf("so, you' ll out of this database system.\n");
    printf("goodbye,\n");
}

/* �������ݿ��������*/
void creatDataBase(char * dataBaseName){
    /* �ж�Ŀ�����ݿ��ļ�Ŀ¼�Ƿ����*/
    if(_access(dataBaseName,0) == -1){
        /* �����ڣ�����Ŀ¼*/
        _mkdir(dataBaseName);
        printf("I have created it.\n");
    }
    else {
        printf("It had exited\n");
    }
}

/* ���ݿ�ע������*/
void dropDataBase(char * dataBaseName){
    if(_access(dataBaseName,0) == -1){
        printf("this folder is not exit\n");
    }
    else{
        /* ���ڣ����Ŀ¼*/
        rmdir(dataBaseName);
        printf("drop database success.\n");
    }
}

/* ���ݿ�ʹ�ú���*/
void useDataBase(char * DBPath) {
    if (_access(DBPath, 0) == -1) {
        printf("error, there is no such a database.\n");
    }
    else {
        printf("OK, now enter the database\n");
        tableManage(DBPath);
    }
}

/* ��ȡ���ݿ���������������*/
void getDBArgs(DataBaseInfo * DBInfo){
    printf("\n--now,you can manage the databases,\n"
           "so, have some operates for them.\n");
    char args[DataTypeSize*CharSize] = {'\0'};
    gets(args);
    /* ��ȡ+���*/
    char arg[5][22] = {'\0'};
    unsigned long lenArgs = strlen(args);
    int argNum = 0 ;
    for(int i = 0 , j = 0; i < lenArgs ; i++){
        if(args[i] == ' '){
            argNum++;
            j = 0;
        }
        else if(args[i] == ';'){
            arg[++argNum][0] = ';';
        }
        else {
            arg[argNum][j++] = args[i];
        }
    }
    DBInfo->operate = getDataBaseOperator(arg[0]);
    /* д��ؼ���Ϣ*/
    if(DBInfo->operate == UseDataBase){
        strcpy(DBInfo->dataBaseName,arg[1]);
    }
    else if(DBInfo->operate == CreateDataBase || DBInfo->operate == DropDataBase){
        strcpy(DBInfo->dataBaseName,arg[2]);
    }
    else {
        strcpy(DBInfo->dataBaseName,"null");
    }
}

/* ���ݿ������*/
void dataBaseManage(){
    /* ��ʽ�����ڴ�*/
    DataBaseInfo * newDBInfo =(DataBaseInfo *) malloc(sizeof(DataBaseInfo));
    char * DBPath = (char *) malloc(sizeof(char)*DataTypeSize*CharSize);
    while (1){
        resetString(newDBInfo->dataBaseName);
        resetString(DBPath);
        getDBArgs(newDBInfo);
        sprintf(DBPath,"%s%s",rootPath,newDBInfo->dataBaseName);
        /* ��Ӧ���ݿ����ѡ����ù��ܺ���*/
        if(newDBInfo->operate == Exit){
            exitDataBase();
            break;
        }
        else if(newDBInfo->operate == CreateDataBase){
            creatDataBase(DBPath);
        }
        else if(newDBInfo->operate == DropDataBase){
            dropDataBase(DBPath);
        }
        else if(newDBInfo->operate == UseDataBase){
            useDataBase(DBPath);
        }
        else {
            printf("You entered anything wrong!\n");
        }
    }
    /* �ͷ��ڴ�*/
    free(newDBInfo);
    free(DBPath);
}


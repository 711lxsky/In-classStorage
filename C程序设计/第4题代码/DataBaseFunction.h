/* 此头文件主要用于实现数据库操作
 * 存放主要数据库操作函数*/

// 引入本地库
#include "TableFunction.h"

/* 获取数据库操作选项函数*/
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

/* 退出数据库操作*/
void exitDataBase(){
    printf("so, you' ll out of this database system.\n");
    printf("goodbye,\n");
}

/* 创建数据库操作函数*/
void creatDataBase(char * dataBaseName){
    /* 判断目标数据库文件目录是否存在*/
    if(_access(dataBaseName,0) == -1){
        /* 不存在，创建目录*/
        _mkdir(dataBaseName);
        printf("I have created it.\n");
    }
    else {
        printf("It had exited\n");
    }
}

/* 数据库注销操作*/
void dropDataBase(char * dataBaseName){
    if(_access(dataBaseName,0) == -1){
        printf("this folder is not exit\n");
    }
    else{
        /* 存在，清除目录*/
        rmdir(dataBaseName);
        printf("drop database success.\n");
    }
}

/* 数据库使用函数*/
void useDataBase(char * DBPath) {
    if (_access(DBPath, 0) == -1) {
        printf("error, there is no such a database.\n");
    }
    else {
        printf("OK, now enter the database\n");
        tableManage(DBPath);
    }
}

/* 获取数据库操作命令参数函数*/
void getDBArgs(DataBaseInfo * DBInfo){
    printf("\n--now,you can manage the databases,\n"
           "so, have some operates for them.\n");
    char args[DataTypeSize*CharSize] = {'\0'};
    gets(args);
    /* 读取+拆分*/
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
    /* 写入关键信息*/
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

/* 数据库管理函数*/
void dataBaseManage(){
    /* 显式申请内存*/
    DataBaseInfo * newDBInfo =(DataBaseInfo *) malloc(sizeof(DataBaseInfo));
    char * DBPath = (char *) malloc(sizeof(char)*DataTypeSize*CharSize);
    while (1){
        resetString(newDBInfo->dataBaseName);
        resetString(DBPath);
        getDBArgs(newDBInfo);
        sprintf(DBPath,"%s%s",rootPath,newDBInfo->dataBaseName);
        /* 对应数据库操作选项，调用功能函数*/
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
    /* 释放内存*/
    free(newDBInfo);
    free(DBPath);
}


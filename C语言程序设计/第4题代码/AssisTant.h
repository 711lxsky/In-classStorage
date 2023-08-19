/* 因为代码量过大，所以将功能文件拆分
 * 此头文件主要用于声明所需的全局变量、常量等，
 * 以及部分功能函数，
 * 同时用于创建所需数据类型、数据结构*/

/* 引入所需标准库文件*/
#include <io.h>
#include <direct.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 操作选项枚举类型*/
// 错误，退出
enum Operate{Error=-1222,Exit,
    // 创建数据库，删除数据库，使用数据库
    CreateDataBase,DropDataBase,UseDataBase,
    //创建表，删除表，查询表信息(列数量，列信息)，插入表信息，删除表信息，选择表信息
    CreateTable,DropTable,GetTableInfo,InsertTableInfo,DeleteTableInfo,SelectTableInfo};

/* 数据种类枚举类型*/
// 整数，浮点数，字符串，种类错误
enum Type{Int,Float,String,TypeError};

/* 条件选项*/
// 小于，等于，大于，升序，降序，假，真
enum condition{Small=1222,Equal,Large,Asc,Desc,False,True};

/* 宏定义数据大小*/
// 数据种类数量
#define DataTypeSize 10
// 数据量
#define DataNum 100
// 字符数据大小
#define CharSize 24

/* 数据库信息结构*/
typedef struct dbInfo{
    // 数据操作选项
    int operate;
    // 数据库名
    char dataBaseName[CharSize];
}DataBaseInfo;

/* 数据表中列信息结构*/
typedef struct lineInfo{
    // 数据类型
    int dataType;
    // 列名
    char name[CharSize];
    // 列数据值
    char value[CharSize];
}LineInfo;

/* 表信息结构*/
typedef struct tableInfo{
    // 操作选项
    int operate;
    // 列数量
    int lineSize;
    // 是否选择所有
    int chooseAll;
    // 条件
    int condition;
    // 排序
    int sort;
    // 关键字段
    char key[CharSize];
    // 排序关键字
    char orderKey[CharSize];
    // 比较偏移值
    char compare[CharSize];
    // 表名
    char tableName[CharSize];
    // 列信息
    LineInfo lines[DataTypeSize];
}TableInfo;

// 数据类型对应字符串
char dataType[][10] = {"int","float","string"};
// 根目录
char rootPath[] = ".\\";
// 备用目录
char rootPathReserve[] = ".\\DataBaseSystem\\";

/* 重新初始化字符串函数
 * 将字符串重新设置为全'\0'*/
void resetString(char * string){
    unsigned long lenStr = strlen(string);
    for(int i = 0 ; i < lenStr ; i ++){
        string[i] = '\0';
    }
}

/* 交换字符串函数
 * 将两个字符指针指向的字符串内容进行交换*/
void swapString(char * str1 , char * str2){
    char rep[CharSize] = {'\0'};
    strcpy(rep,str1);
    resetString(str1);
    strcpy(str1,str2);
    resetString(str2);
    strcpy(str2,rep);
}

/* 判断两个值是否符合比较条件函数
 * str1,str2是值1、值2，way是比较方法*/
int compareValue(char * str1 , char * str2 , int way){
    if(strcmp(str1,str2) < 0){
        if(way == Small){
            return True;
        }
        else {
            return False;
        }
    }
    else if(strcmp(str1,str2) == 0){
        if(way == Equal){
            return True;
        }
        else {
            return False;
        }
    }
    else {
        if(way == Large){
            return True;
        }
        else {
            return False;
        }
    }
}

/* 重新初始化表信息函数*/
void reSetTableInfo(TableInfo * tableInfo){
    tableInfo->lineSize = 0;
    tableInfo->chooseAll = False;
    tableInfo->sort = False;
    tableInfo->operate = Error;
    tableInfo->condition = TypeError;
    resetString(tableInfo->tableName);
    resetString(tableInfo->key);
    resetString(tableInfo->orderKey);
    resetString(tableInfo->compare);
    for(int i = 0 ; i < DataTypeSize ; i ++){
        resetString(tableInfo->lines[i].name);
        resetString(tableInfo->lines[i].value);
    }
}

/* 获取表文件路径函数
 * 因为数据库系统是通过文件读写实现，所以需要指定文件创建位置*/
void getTablePath(char * TbPath, char * DBPath, TableInfo * tableInfo){
    resetString(TbPath);
    sprintf(TbPath,"%s%s%s%s",DBPath,"//",tableInfo->tableName,".txt");
}

/* 获取表操作选项函数
 * 通过比较字符串参数，返回对应的枚举变量*/
int getTableOperator(char * arg){
    if(strcmp(arg,"exit") == 0){
        return Exit;
    }
    else if(strcmp(arg,"create") == 0){
        return CreateTable;
    }
    else if(strcmp(arg,"drop") == 0){
        return DropTable;
    }
    else if(strcmp(arg,"info") == 0){
        return GetTableInfo;
    }
    else if(strcmp(arg,"insert") == 0){
        return InsertTableInfo;
    }
    else if(strcmp(arg,"delete") == 0){
        return DeleteTableInfo;
    }
    else if(strcmp(arg,"select") == 0){
        return SelectTableInfo;
    }
    else{
        return Error;
    }
}

/* 获取列数据类型函数
 * 根据参数字符串，获取对应枚举数据类型*/
int getLineType(char * type){
    if(strcmp(type,dataType[0]) == 0){
        return Int;
    }
    else if(strcmp(type,dataType[1]) == 0){
        return Float;
    }
    else if(strcmp(type,dataType[2]) == 0){
        return String;
    }
    else {
        return TypeError;
    }
}


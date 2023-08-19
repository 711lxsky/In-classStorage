/* ��Ϊ�������������Խ������ļ����
 * ��ͷ�ļ���Ҫ�������������ȫ�ֱ����������ȣ�
 * �Լ����ֹ��ܺ�����
 * ͬʱ���ڴ��������������͡����ݽṹ*/

/* ���������׼���ļ�*/
#include <io.h>
#include <direct.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ����ѡ��ö������*/
// �����˳�
enum Operate{Error=-1222,Exit,
    // �������ݿ⣬ɾ�����ݿ⣬ʹ�����ݿ�
    CreateDataBase,DropDataBase,UseDataBase,
    //������ɾ������ѯ����Ϣ(������������Ϣ)���������Ϣ��ɾ������Ϣ��ѡ�����Ϣ
    CreateTable,DropTable,GetTableInfo,InsertTableInfo,DeleteTableInfo,SelectTableInfo};

/* ��������ö������*/
// ���������������ַ������������
enum Type{Int,Float,String,TypeError};

/* ����ѡ��*/
// С�ڣ����ڣ����ڣ����򣬽��򣬼٣���
enum condition{Small=1222,Equal,Large,Asc,Desc,False,True};

/* �궨�����ݴ�С*/
// ������������
#define DataTypeSize 10
// ������
#define DataNum 100
// �ַ����ݴ�С
#define CharSize 24

/* ���ݿ���Ϣ�ṹ*/
typedef struct dbInfo{
    // ���ݲ���ѡ��
    int operate;
    // ���ݿ���
    char dataBaseName[CharSize];
}DataBaseInfo;

/* ���ݱ�������Ϣ�ṹ*/
typedef struct lineInfo{
    // ��������
    int dataType;
    // ����
    char name[CharSize];
    // ������ֵ
    char value[CharSize];
}LineInfo;

/* ����Ϣ�ṹ*/
typedef struct tableInfo{
    // ����ѡ��
    int operate;
    // ������
    int lineSize;
    // �Ƿ�ѡ������
    int chooseAll;
    // ����
    int condition;
    // ����
    int sort;
    // �ؼ��ֶ�
    char key[CharSize];
    // ����ؼ���
    char orderKey[CharSize];
    // �Ƚ�ƫ��ֵ
    char compare[CharSize];
    // ����
    char tableName[CharSize];
    // ����Ϣ
    LineInfo lines[DataTypeSize];
}TableInfo;

// �������Ͷ�Ӧ�ַ���
char dataType[][10] = {"int","float","string"};
// ��Ŀ¼
char rootPath[] = ".\\";
// ����Ŀ¼
char rootPathReserve[] = ".\\DataBaseSystem\\";

/* ���³�ʼ���ַ�������
 * ���ַ�����������Ϊȫ'\0'*/
void resetString(char * string){
    unsigned long lenStr = strlen(string);
    for(int i = 0 ; i < lenStr ; i ++){
        string[i] = '\0';
    }
}

/* �����ַ�������
 * �������ַ�ָ��ָ����ַ������ݽ��н���*/
void swapString(char * str1 , char * str2){
    char rep[CharSize] = {'\0'};
    strcpy(rep,str1);
    resetString(str1);
    strcpy(str1,str2);
    resetString(str2);
    strcpy(str2,rep);
}

/* �ж�����ֵ�Ƿ���ϱȽ���������
 * str1,str2��ֵ1��ֵ2��way�ǱȽϷ���*/
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

/* ���³�ʼ������Ϣ����*/
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

/* ��ȡ���ļ�·������
 * ��Ϊ���ݿ�ϵͳ��ͨ���ļ���дʵ�֣�������Ҫָ���ļ�����λ��*/
void getTablePath(char * TbPath, char * DBPath, TableInfo * tableInfo){
    resetString(TbPath);
    sprintf(TbPath,"%s%s%s%s",DBPath,"//",tableInfo->tableName,".txt");
}

/* ��ȡ�����ѡ���
 * ͨ���Ƚ��ַ������������ض�Ӧ��ö�ٱ���*/
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

/* ��ȡ���������ͺ���
 * ���ݲ����ַ�������ȡ��Ӧö����������*/
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


/* ��ͷ�ļ��Ǳ��������ʵ���ļ���
 * ��Ŵ󲿷ֱ�������躯��*/

// ���뱾��ͷ�ļ�
#include "AssisTant.h"

/* �˳����������*/
void exitTable(){
    /* ��ӡ��ʾ��Ϣ*/
    printf("you will out of the table manege.\n");
    printf("bye\n");
}

/* �������������*/
void createTable(char * tablePath, TableInfo * tableInfo){
    /* �����ж�Ŀ���ļ��Ƿ����*/
    if(_access(tablePath,0) == -1){
        /* ���ڣ����ļ�*/
        FILE * writeBasicInfo = fopen(tablePath,"a+");
        printf("OK, this table is created.\n");
        /* ����Ļ�����Ϣд���ļ�
         * ��һ����������
         * �ڶ��������ֶ���������
         * �����������ֶ���*/
        fprintf(writeBasicInfo,"%d\n",tableInfo->lineSize );
        for(int i = 0 ; i < tableInfo->lineSize ; i++){
            fprintf(writeBasicInfo,"%d ",tableInfo->lines[i].dataType);
        }
        fprintf(writeBasicInfo,"\n");
        for(int i = 0 ; i < tableInfo->lineSize ; i ++){
            fprintf(writeBasicInfo,"%s ",tableInfo->lines[i].name);
        }
        fprintf(writeBasicInfo,"\n");
        /* �ر��ļ���*/
        fclose(writeBasicInfo);
    }
    else {
        /* ���������ӡ��ʾ��Ϣ*/
        printf("this table is existed.\n");
        printf("thus, new create table is invalid.\n");
    }
}

/* ע�����������*/
void dropTable(char * tablePath){
    /* �����ڶ�Ӧ�ļ�����ӡ��Ϣ*/
    if(_access(tablePath,0) == -1){
        printf("sorry, this table is not existed.\n");
    }
    /* ������ɾ���ļ�*/
    else {
        remove(tablePath);
        printf("table delete success.\n");
    }
}

/* ��ȡ����Ϣ����*/
void getTableInfo(char * tablePath){
    /* �����ڣ�����*/
    if(_access(tablePath,0) == -1){
        printf("error, this table isn't existed.\n");
    }
    /* ���ڣ���*/
    else {
        FILE * readBasicInfo = fopen(tablePath,"a+");
        /* �½�����Ϣ�ṹ�����Դ�Ŷ�ȡ���ı���Ϣ*/
        TableInfo getTbInfo;
        fscanf(readBasicInfo,"%d",&getTbInfo.lineSize);
        for(int i = 0 ; i < getTbInfo.lineSize ; i ++){
            fscanf(readBasicInfo,"%d ", &getTbInfo.lines[i].dataType);
        }
        for(int i = 0 ; i < getTbInfo.lineSize ; i ++){
            fscanf(readBasicInfo,"%s",getTbInfo.lines[i].name);
        }
        fclose(readBasicInfo);
        /* ����ȡ�����ݴ�ӡ*/
        printf("these are some basic information for this table:\n");
        printf("line size: %d\n",getTbInfo.lineSize);
        printf("lines: ");
        for(int i = 0 ; i < getTbInfo.lineSize  ; i ++){
            printf("%s(%s), ", getTbInfo.lines[i].name, dataType[getTbInfo.lines[i].dataType]);
        }
        printf("\n");
    }
}

/* ��������ݺ���*/
void insertTable(char * tablePath, TableInfo * tableInfo){
    /* ������Ŀ���ļ�����ӡ������ʾ*/
    if(_access(tablePath,0) == -1){
        printf("can not insert into information, this table is not existed.\n");
    }
    /* ���ڣ����ļ�*/
    else {
        FILE * insert = fopen(tablePath,"a+");
        /* ֱ�ӽ�����׷���ڱ��ļ���*/
        for(int i = 0 ; i < tableInfo->lineSize ; i ++){
            fprintf(insert,"%s ",tableInfo->lines[i].value);
        }
        fprintf(insert,"\n");
        fclose(insert);
        printf("OK, insert success.\n");
    }
}

/* ɾ������Ϣ����*/
void deleteTableInfo(char * tablePath, TableInfo * tableInfo){
    /* �½�����Ϣ�ṹ�Դ洢�����ı���Ϣ*/
    TableInfo getTbInfo;
    /* ͬ���ж��Ƿ����Ŀ���ļ�*/
    if(_access(tablePath,0) == -1){
        printf("sorry, there is no such a table.\n");
    }
    else {
        /* ��ȡ����Ϣ*/
        FILE * getInfo = fopen(tablePath,"a+");
        fscanf(getInfo,"%d",&getTbInfo.lineSize);
        for(int i = 0 ; i < getTbInfo.lineSize; i++){
            fscanf(getInfo,"%d",&getTbInfo.lines[i].dataType);
        }
        for(int i = 0 ; i < getTbInfo.lineSize; i++){
            fscanf(getInfo,"%s",getTbInfo.lines[i].name);
        }
        /* ���ݴ洢��*/
        char dataArea[DataNum][DataTypeSize][CharSize]={'\0'};
        int row = 0 ;
        /* ���������ݶ���洢��*/
        while (feof(getInfo) == 0){
            for(int j = 0 ; j < getTbInfo.lineSize; j ++){
                if(feof(getInfo) != 0){
                    break;
                }
                fscanf(getInfo,"%s",dataArea[row][j]);
            }
            row ++;
        }
        /* ע��˴������һ��'\n'��������������Ҫ-1*/
        row--;
        fclose(getInfo);
        /* �ٴδ��ļ�*/
        FILE * updateData = fopen(tablePath,"w");
        /* д�������Ϣ*/
        fprintf(updateData,"%d\n",getTbInfo.lineSize);
        for(int i = 0 ; i < getTbInfo.lineSize ; i++){
            fprintf(updateData,"%d ",getTbInfo.lines[i].dataType);
        }
        fprintf(updateData,"\n");
        for(int i = 0 ; i < getTbInfo.lineSize; i++){
            fprintf(updateData,"%s ",getTbInfo.lines[i].name);
        }
        fprintf(updateData,"\n");
        /* �������ɾ�������ֶΣ��ٵ�����������ɸѡ*/
        if(tableInfo->chooseAll == False){
            /* ��λɸѡ����������*/
            int labelKey = -1;
            for(int i = 0 ; i < getTbInfo.lineSize ; i++ ){
                if(strcmp(getTbInfo.lines[i].name,tableInfo->key) == 0){
                    labelKey = i;
                    break;
                }
            }
            /* δ�ҵ��������˳�*/
            if(labelKey == -1){
                printf("sorry , the key is invalid.\n");
                exit(-22);
            }
            /* ɸѡ����������������д������
             * ��ˣ����������������ݾͱ�ɾ���������ٴγ����ڴ˱���*/
            for(int i = 0 ; i < row ; i ++){
                if(compareValue(dataArea[i][labelKey],tableInfo->compare,tableInfo->condition)==False){
                    for(int j = 0 ; j < getTbInfo.lineSize; j++){
                        fprintf(updateData,"%s ",dataArea[i][j]);
                    }
                    fprintf(updateData,"\n");
                }
            }
        }
        fclose(updateData);
        printf("delete success.\n");
    }
}

/* ��ѯ�����ݺ���*/
void selectTableInfo(TableInfo * tableInfo , char * tablePath){
    /* ͬ���ж��Ƿ����Ŀ���ļ�*/
    if(_access(tablePath,0) == -1){
        printf("something is wrong, this table is not existed.\n");
    }
    else {
        /* ���ļ�����ȡ������Ϣ������*/
        FILE * getData = fopen(tablePath,"a+");
        TableInfo readTableInfo;
        char dataArea[DataNum][DataTypeSize][CharSize] = {'\0'};
        fscanf(getData,"%d\n",&readTableInfo.lineSize);
        for(int i = 0 ; i < readTableInfo.lineSize ; i++){
            fscanf(getData,"%d",&readTableInfo.lines[i].dataType);
        }
        for(int i = 0 ; i < readTableInfo.lineSize; i ++){
            fscanf(getData,"%s",readTableInfo.lines[i].name);
        }
        int row = 0 ;
        while(feof(getData) == 0){
            for(int i = 0 ; i < readTableInfo.lineSize ; i ++){
                fscanf(getData,"%s",dataArea[row][i]);
            }
            row++;
        }
        row--;
        fclose(getData);
        /* ��������*/
        if(tableInfo->sort == Desc){
            /* ��ȡ����ؼ��ֶ�������*/
            int orderLabel = -1;
            for(int i = 0 ; i < readTableInfo.lineSize ; i++){
                if(strcmp(readTableInfo.lines[i].name,tableInfo->orderKey) == 0){
                    orderLabel = i;
                }
            }
            /* δ�ҵ��������˳�*/
            if(orderLabel == -1){
                printf("sorry , the order key is invalid.\n");
                exit(-22);
            }
            /* ð������ʵ�����������ݽ���*/
            for(int i = row - 1 ; i >= 0 ; i--){
                for(int j = 0 ; j < i ; j ++){
                    if(strcmp(dataArea[j][orderLabel],dataArea[j+1][orderLabel]) < 0){
                        for(int k = 0 ; k < readTableInfo.lineSize ; k++){
                            swapString(dataArea[j][k],dataArea[j+1][k]);
                        }
                    }
                }
            }
        }
        /* ͬ����������*/
        else if(tableInfo->sort == Asc){
            int orderLabel = -1;
            for(int i = 0 ; i < readTableInfo.lineSize ; i++){
                if(strcmp(readTableInfo.lines[i].name,tableInfo->orderKey) == 0){
                    orderLabel = i;
                }
            }
            if(orderLabel == -1){
                printf("sorry , the order key is invalid.\n");
                exit(-22);
            }
            for(int i = row - 1 ; i >= 0 ; i--){
                for(int j = 0 ; j < i ; j ++){
                    if(strcmp(dataArea[j][orderLabel],dataArea[j+1][orderLabel]) > 0){
                        for(int k = 0 ; k < readTableInfo.lineSize ; k++){
                            swapString(dataArea[j][k],dataArea[j+1][k]);
                        }
                    }
                }
            }
        }
        printf("OK, these are your destinations:\n");
        /* �ж��Ƿ�������ɸѡ�������Ƿ�ѡ�������ֶ�
         * �ٸ���Ҫ���ӡ��Ϣ*/
        if(tableInfo->condition == False){
            if(tableInfo->chooseAll == True){
                for(int i = 0 ; i < row; i++){
                    for(int j = 0 ; j < readTableInfo.lineSize ; j++){
                        printf("%s:%s, ",readTableInfo.lines[j].name,dataArea[i][j]);
                    }
                    printf("\n");
                }
            }
            else {
                for(int i = 0 ; i < row; i++){
                    for(int j = 0 ; j < tableInfo->lineSize ; j ++){
                        for(int k = 0 ; k < readTableInfo.lineSize ; k++){
                            /* ��ȡĿ���ֶ���Ϣ*/
                            if(strcmp(tableInfo->lines[j].name, readTableInfo.lines[k].name) == 0){
                                printf("%s:%s, ", tableInfo->lines[j].name,dataArea[i][k]);
                            }
                        }
                    }
                    printf("\n");
                }
            }
        }
        else {
            /* �ҵ�ɸѡ�ؼ��ֶ�������*/
            int keyLabel = -1;
            for(int i = 0 ; i < readTableInfo.lineSize ; i++){
                if(strcmp(readTableInfo.lines[i].name,tableInfo->key) == 0){
                    keyLabel = i;
                }
            }
            /* δ�ҵ��������˳�*/
            if(keyLabel == -1){
                printf("sorry , the key is invalid.\n");
                exit(-22);
            }
            if(tableInfo->chooseAll == True){
                for(int i = 0 ; i < row ; i ++){
                    /* ��������ɸѡ����*/
                    if(compareValue(dataArea[i][keyLabel],tableInfo->compare,tableInfo->condition) == True){
                        for(int j = 0 ; j < readTableInfo.lineSize ; j++){
                            printf("%s:%s, ",readTableInfo.lines[j].name,dataArea[i][j]);
                        }
                        printf("\n");
                    }
                }
            }
            else {
                for(int i = 0 ; i < row ; i ++){
                    /* ɸѡ��*/
                    if(compareValue(dataArea[i][keyLabel],tableInfo->compare,tableInfo->condition) == True){
                        for(int j = 0 ; j < tableInfo->lineSize ; j ++){
                            for(int k = 0 ; k < readTableInfo.lineSize ; k ++){
                                /* ��ȡĿ��������*/
                                if(strcmp(tableInfo->lines[j].name,readTableInfo.lines[k].name) == 0){
                                    printf("%s:%s, ",tableInfo->lines[j].name,dataArea[i][k]);
                                }
                            }
                        }
                        printf("\n");
                    }
                }
            }
        }
    }
}

/* ��ȡ��������������������*/
void getArgsTbCreate(TableInfo * tableInfo , char * args){
    char repArgs[DataTypeSize*CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    /* �����޳�(��)*/
    for(int i = 0 , j = 0 ; i < lenArgs ; i ++){
        if(args[i] != '(' && args[i] != ')'){
            repArgs[j++] = args[i];
        }
    }
    char arg[DataTypeSize*4][CharSize] = {'\0'};
    int argNum = 0 ;
    unsigned long lenRepArgs = strlen(repArgs);
    /* �ٽ�����������*/
    for(int i = 0 , j = 0 ; i < lenRepArgs ; i++){
        if(repArgs[i] == ' '){
            argNum ++;
            j = 0 ;
        }
        else if(repArgs[i] == ','){
            arg[++argNum][0] = ',';
            argNum++;
            j = 0 ;
        }
        else if(repArgs[i] == ';'){
            arg[++argNum][0] = ',';
        }
        else {
            arg[argNum][j++] = repArgs[i];
        }
    }
    /* ��ȡ�ؼ���Ϣ������tableInfo*/
    for(int i = 0 ; i <= argNum ; i ++){
        if(strcmp(arg[i],"table") == 0){
            strcpy(tableInfo->tableName,arg[i+1]);
        }
        else if(strcmp(arg[i],",") == 0){
            strcpy(tableInfo->lines[tableInfo->lineSize].name,arg[i-1]);
            tableInfo->lines[tableInfo->lineSize].dataType = getLineType(arg[i-2]);
            tableInfo->lineSize ++;
        }
    }
}

/* ��ȡ��ע���ʹ�ӡ����Ϣ�����������*/
void getArgsTbDropAndInfo(TableInfo * tableInfo,char * args){
    char arg[DataTypeSize][CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    int argNum = 0 ;
    /* ��������ʲ��*/
    for(int i = 0 , j = 0; i < lenArgs ; i ++){
        if(args[i] == ' '){
            argNum ++ ;
            j = 0 ;
        }
        else if(args[i] == ';'){
            arg[++argNum][0] = ';';
        }
        else {
            arg[argNum][j++] = args[i];
        }
    }
    /* �ؼ���Ϣ����tableInfo*/
    for(int i = 0 ; i <= argNum ; i ++){
        if(strcmp(arg[i], "table") == 0){
            strcpy(tableInfo->tableName,arg[i+1]);
        }
    }
}

/* ��ȡ�����������������*/
void getArgsTbInsert(TableInfo * tableInfo, char * args) {
    char repArgs[DataTypeSize * 2 * CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    /* �޳�'*/
    for (int i = 0 , j = 0; i < lenArgs; i++) {
        if (args[i] != '\''){
            repArgs[j++] = args[i];
        }
    }
    char arg[DataTypeSize*4][CharSize] = {'\0'};
    int argNum = 0 ;
    unsigned long lenRep = strlen(repArgs);
    /* ���*/
    for(int i = 0 , j = 0 ; i < lenRep ; i ++){
        if(repArgs[i] == ' '){
            argNum ++;
            j = 0 ;
        }
        else if(repArgs[i] == '=' || repArgs[i] == ','){
            arg[++argNum][0] = repArgs[i];
            argNum ++;
            j = 0 ;
        }
        else if(repArgs[i] == ';'){
            arg[++argNum][0] = ';';
        }
        else {
            arg[argNum][j++] = repArgs[i];
        }
    }
    /* ץȡ�ؼ��ֶ�*/
    for(int i = 0 ; i <= argNum ; i ++){
        if(strcmp(arg[i], "set") == 0){
            strcpy(tableInfo->tableName,arg[i-1]);
        }
        else if(strcmp(arg[i],"=") == 0){
            strcpy(tableInfo->lines[tableInfo->lineSize].name,arg[i-1]);
            strcpy(tableInfo->lines[tableInfo->lineSize].value,arg[i+1]);
            tableInfo->lineSize++;
        }
    }
}

/* ��ȡ��ɾ����Ϣ�������������*/
void getArgsTbDelete(TableInfo * tableInfo , char * args){
    char repArgs[DataTypeSize*2*CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    /* �޳�'*/
    for(int i = 0 , j = 0 ; i < lenArgs ;i ++){
        if(args[i] !='\''){
            repArgs[j++] = args[i];
        }
    }
    char arg[DataTypeSize*4][CharSize] = {'\0'};
    int argNum = 0 ;
    unsigned long lenRep = strlen(repArgs);
    /* ���*/
    for(int i = 0 , j = 0; i < lenRep ; i ++){
        if(repArgs[i] == ' '){
            argNum++;
            j = 0 ;
        }
        else if(repArgs[i] == '<' || repArgs[i] == '=' || repArgs[i] == '>'){
            arg[++argNum][0] = repArgs[i];
            argNum ++;
            j = 0 ;
        }
        else if(repArgs[i] == ';'){
            arg[++argNum][0] = ';';
        }
        else {
            arg[argNum][j++] = repArgs[i];
        }
    }
    /* ��ʼʱ����chooseAll��Ϊ��*/
    tableInfo->chooseAll = True;
    for(int i = 0 ; i <= argNum ; i ++){
        if(strcmp(arg[i],"from") == 0){
            strcpy(tableInfo->tableName,arg[i+1]);
        }
        /* > = < ������ɸѡѡ��*/
        else if(strcmp(arg[i],"<") == 0){
            tableInfo->condition = Small;
            strcpy(tableInfo->key,arg[i-1]);
            strcpy(tableInfo->compare,arg[i+1]);
        }
        else if(strcmp(arg[i],"=") == 0){
            tableInfo->condition = Equal;
            strcpy(tableInfo->key,arg[i-1]);
            strcpy(tableInfo->compare,arg[i+1]);
        }
        else if(strcmp(arg[i],">") == 0){
            tableInfo->condition = Large;
            strcpy(tableInfo->key,arg[i-1]);
            strcpy(tableInfo->compare,arg[i+1]);
        }
        /* �����where��˵������ɸѡ����
         * chooseAll���*/
        if(strcmp(arg[i],"where") == 0){
            tableInfo->chooseAll = False;
        }
    }
}

/* ��ȡ���ѯ���ݲ������������*/
void getArgsTbSelect(TableInfo * tableInfo,char * args){
    unsigned long lenArgs = strlen(args);
    char str[DataTypeSize*2*CharSize] = {'\0'};
    /* ͬ����ȡ��������*/
    for(int i = 0 , j = 0; i < lenArgs ; i ++){
        if(args[i] != '\''){
            str[j++]=args[i];
        }
    }
    char arg[DataTypeSize*4][CharSize] = {'\0'};
    int num = 0;
    unsigned long lenStr = strlen(str);
    for(int i = 0 , j = 0 ; i < lenStr ; i ++ ){
        if(str[i] == ' '){
            num ++;
            j = 0;
        }
        else if(str[i] == ',' || str[i] == '<' || str[i] == '=' || str[i] == '>' || str[i] == '*'){
            arg[++num][0] = str[i];
            num++;
            j = 0;
        }
        else if(str[i] == ';'){
            arg[++num][0] = ';';
        }
        else {
            arg[num][j++] = str[i];
        }
    }
    tableInfo->chooseAll = False;
    tableInfo->sort = False;
    tableInfo->condition = False;
    /* ������� * �ж�chooseAll��ֵ
     * ���� < = > �ж�ɸѡ������ɸѡ�ֶ�
     * �� by �ж��Ƿ������������asc,descָ����/����*/
    for(int i = 0 ; i <= num; i++){
        if(strcmp(arg[i],",") == 0 ){
            strcpy(tableInfo->lines[tableInfo->lineSize].name,arg[i-1]);
            tableInfo->lineSize ++;
        }
        else if(strcmp(arg[i],"from") == 0){
            strcpy(tableInfo->lines[tableInfo->lineSize].name,arg[i-1]);
            strcpy(tableInfo->tableName,arg[i+1]);
            tableInfo->lineSize ++;
        }
        else if(strcmp(arg[i],"*") == 0){
            tableInfo->chooseAll = True;
        }
        else if(strcmp(arg[i],"<") == 0){
            tableInfo->condition = Small;
            strcpy(tableInfo->key,arg[i-1]);
            strcpy(tableInfo->compare,arg[i+1]);
        }
        else if(strcmp(arg[i],"=") == 0){
            tableInfo->condition = Equal;
            strcpy(tableInfo->key,arg[i-1]);
            strcpy(tableInfo->compare,arg[i+1]);
        }
        else if(strcmp(arg[i],">") == 0){
            tableInfo->condition = Large;
            strcpy(tableInfo->key,arg[i-1]);
            strcpy(tableInfo->compare,arg[i+1]);
        }
        else if(strcmp(arg[i],"desc") == 0){
            tableInfo->sort = Desc;
        }
        else if(strcmp(arg[i],"asc") == 0){
            tableInfo->sort = Asc;
        }
        else if(strcmp(arg[i],"by") == 0){
            tableInfo->sort = True;
            strcpy(tableInfo->orderKey,arg[i+1]);
        }
    }
}

/* ��ȡ�����������*/
void getTableArgs(TableInfo * tableInfo){
    /* ��ʾ��Ϣ*/
    printf("\n--now, you can manage table\n");
    printf("so, give some operates for it\n");
    char operator[CharSize] = {'\0'};
    char * args = (char *) malloc(sizeof (char )*DataTypeSize*2*CharSize);
    resetString(args);
    /* �Ȼ�ȡ����ѡ��*/
    scanf("%s", operator);
    /* ��ץȡ����*/
    gets(args);
    tableInfo->operate = getTableOperator(operator);
    /* �ɲ�ͬ�Ĳ���ѡ����ö�Ӧ�Ĳ�������*/
    if(tableInfo->operate == Exit){
        printf("pause.\n");
    }
    else if(tableInfo->operate == CreateTable){
        getArgsTbCreate(tableInfo,args);
    }
    else if(tableInfo->operate == DropTable || tableInfo->operate == GetTableInfo){
        getArgsTbDropAndInfo(tableInfo,args);
    }
    else if(tableInfo->operate == InsertTableInfo){
        getArgsTbInsert(tableInfo,args);
    }
    else if(tableInfo->operate == DeleteTableInfo){
        getArgsTbDelete(tableInfo,args);
    }
    else if(tableInfo->operate == SelectTableInfo){
        getArgsTbSelect(tableInfo,args);
    }
    else {
        printf("wait,");
    }
    free(args);
}

/* �������*/
void tableManage(char * dataBasePath){
    /* ��ʽ�����ڴ�*/
    TableInfo * tableInfo = (TableInfo*) malloc(sizeof(TableInfo));
    char * tablePath = (char *) malloc(sizeof(char)*DataTypeSize*CharSize);
    /* �������*/
    while (1){
        reSetTableInfo(tableInfo);
        getTableArgs(tableInfo);
        /* ��ȡ�������������ö�Ӧ����*/
        if(tableInfo->operate == Exit){
            exitTable();
            break;
        }
        else if(tableInfo->operate == CreateTable){
            getTablePath(tablePath,dataBasePath,tableInfo);
            createTable(tablePath,tableInfo);
        }
        else if(tableInfo->operate == DropTable){
            getTablePath(tablePath,dataBasePath,tableInfo);
            dropTable(tablePath);
        }
        else if(tableInfo->operate == GetTableInfo){
            getTablePath(tablePath,dataBasePath,tableInfo);
            getTableInfo(tablePath);
        }
        else if(tableInfo->operate == InsertTableInfo){
            getTablePath(tablePath,dataBasePath,tableInfo);
            insertTable(tablePath,tableInfo);
        }
        else if(tableInfo->operate == DeleteTableInfo){
            getTablePath(tablePath,dataBasePath,tableInfo);
            deleteTableInfo(tablePath,tableInfo);
        }
        else if(tableInfo->operate == SelectTableInfo){
            getTablePath(tablePath,dataBasePath,tableInfo);
            selectTableInfo(tableInfo,tablePath);
        }
        else {
            printf("you entered is wrong.\n");
        }
    }
    /* �ͷ��ڴ�*/
    free(tableInfo);
    free(tablePath);
}


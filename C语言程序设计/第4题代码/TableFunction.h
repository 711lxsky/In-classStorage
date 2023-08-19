/* 此头文件是表操作功能实现文件，
 * 存放大部分表操作所需函数*/

// 引入本地头文件
#include "AssisTant.h"

/* 退出表操作函数*/
void exitTable(){
    /* 打印提示信息*/
    printf("you will out of the table manege.\n");
    printf("bye\n");
}

/* 创建表操作函数*/
void createTable(char * tablePath, TableInfo * tableInfo){
    /* 首先判断目标文件是否存在*/
    if(_access(tablePath,0) == -1){
        /* 存在，打开文件*/
        FILE * writeBasicInfo = fopen(tablePath,"a+");
        printf("OK, this table is created.\n");
        /* 将表的基本信息写入文件
         * 第一行是列数量
         * 第二行是列字段数据类型
         * 第三行是列字段名*/
        fprintf(writeBasicInfo,"%d\n",tableInfo->lineSize );
        for(int i = 0 ; i < tableInfo->lineSize ; i++){
            fprintf(writeBasicInfo,"%d ",tableInfo->lines[i].dataType);
        }
        fprintf(writeBasicInfo,"\n");
        for(int i = 0 ; i < tableInfo->lineSize ; i ++){
            fprintf(writeBasicInfo,"%s ",tableInfo->lines[i].name);
        }
        fprintf(writeBasicInfo,"\n");
        /* 关闭文件流*/
        fclose(writeBasicInfo);
    }
    else {
        /* 不存在则打印提示信息*/
        printf("this table is existed.\n");
        printf("thus, new create table is invalid.\n");
    }
}

/* 注销表操作函数*/
void dropTable(char * tablePath){
    /* 不存在对应文件，打印信息*/
    if(_access(tablePath,0) == -1){
        printf("sorry, this table is not existed.\n");
    }
    /* 存在则删除文件*/
    else {
        remove(tablePath);
        printf("table delete success.\n");
    }
}

/* 获取表信息函数*/
void getTableInfo(char * tablePath){
    /* 不存在，报错*/
    if(_access(tablePath,0) == -1){
        printf("error, this table isn't existed.\n");
    }
    /* 存在，打开*/
    else {
        FILE * readBasicInfo = fopen(tablePath,"a+");
        /* 新建表信息结构，用以存放读取到的表信息*/
        TableInfo getTbInfo;
        fscanf(readBasicInfo,"%d",&getTbInfo.lineSize);
        for(int i = 0 ; i < getTbInfo.lineSize ; i ++){
            fscanf(readBasicInfo,"%d ", &getTbInfo.lines[i].dataType);
        }
        for(int i = 0 ; i < getTbInfo.lineSize ; i ++){
            fscanf(readBasicInfo,"%s",getTbInfo.lines[i].name);
        }
        fclose(readBasicInfo);
        /* 将读取的数据打印*/
        printf("these are some basic information for this table:\n");
        printf("line size: %d\n",getTbInfo.lineSize);
        printf("lines: ");
        for(int i = 0 ; i < getTbInfo.lineSize  ; i ++){
            printf("%s(%s), ", getTbInfo.lines[i].name, dataType[getTbInfo.lines[i].dataType]);
        }
        printf("\n");
    }
}

/* 插入表数据函数*/
void insertTable(char * tablePath, TableInfo * tableInfo){
    /* 不存在目标文件，打印错误提示*/
    if(_access(tablePath,0) == -1){
        printf("can not insert into information, this table is not existed.\n");
    }
    /* 存在，打开文件*/
    else {
        FILE * insert = fopen(tablePath,"a+");
        /* 直接将数据追加在表文件中*/
        for(int i = 0 ; i < tableInfo->lineSize ; i ++){
            fprintf(insert,"%s ",tableInfo->lines[i].value);
        }
        fprintf(insert,"\n");
        fclose(insert);
        printf("OK, insert success.\n");
    }
}

/* 删除表信息操作*/
void deleteTableInfo(char * tablePath, TableInfo * tableInfo){
    /* 新建表信息结构以存储读到的表信息*/
    TableInfo getTbInfo;
    /* 同理，判断是否存在目标文件*/
    if(_access(tablePath,0) == -1){
        printf("sorry, there is no such a table.\n");
    }
    else {
        /* 读取表信息*/
        FILE * getInfo = fopen(tablePath,"a+");
        fscanf(getInfo,"%d",&getTbInfo.lineSize);
        for(int i = 0 ; i < getTbInfo.lineSize; i++){
            fscanf(getInfo,"%d",&getTbInfo.lines[i].dataType);
        }
        for(int i = 0 ; i < getTbInfo.lineSize; i++){
            fscanf(getInfo,"%s",getTbInfo.lines[i].name);
        }
        /* 数据存储区*/
        char dataArea[DataNum][DataTypeSize][CharSize]={'\0'};
        int row = 0 ;
        /* 将表中数据读入存储区*/
        while (feof(getInfo) == 0){
            for(int j = 0 ; j < getTbInfo.lineSize; j ++){
                if(feof(getInfo) != 0){
                    break;
                }
                fscanf(getInfo,"%s",dataArea[row][j]);
            }
            row ++;
        }
        /* 注意此处会读到一个'\n'，数据行数量需要-1*/
        row--;
        fclose(getInfo);
        /* 再次打开文件*/
        FILE * updateData = fopen(tablePath,"w");
        /* 写入基本信息*/
        fprintf(updateData,"%d\n",getTbInfo.lineSize);
        for(int i = 0 ; i < getTbInfo.lineSize ; i++){
            fprintf(updateData,"%d ",getTbInfo.lines[i].dataType);
        }
        fprintf(updateData,"\n");
        for(int i = 0 ; i < getTbInfo.lineSize; i++){
            fprintf(updateData,"%s ",getTbInfo.lines[i].name);
        }
        fprintf(updateData,"\n");
        /* 如果不是删除所有字段，再迭代进行条件筛选*/
        if(tableInfo->chooseAll == False){
            /* 定位筛选条件所在列*/
            int labelKey = -1;
            for(int i = 0 ; i < getTbInfo.lineSize ; i++ ){
                if(strcmp(getTbInfo.lines[i].name,tableInfo->key) == 0){
                    labelKey = i;
                    break;
                }
            }
            /* 未找到，报错，退出*/
            if(labelKey == -1){
                printf("sorry , the key is invalid.\n");
                exit(-22);
            }
            /* 筛选条件，符合条件则写入数据
             * 因此，不符合条件的数据就被删除，不会再次出现在此表中*/
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

/* 查询表数据函数*/
void selectTableInfo(TableInfo * tableInfo , char * tablePath){
    /* 同理，判断是否存在目标文件*/
    if(_access(tablePath,0) == -1){
        printf("something is wrong, this table is not existed.\n");
    }
    else {
        /* 打开文件，读取基本信息、数据*/
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
        /* 降序排列*/
        if(tableInfo->sort == Desc){
            /* 获取排序关键字段所在列*/
            int orderLabel = -1;
            for(int i = 0 ; i < readTableInfo.lineSize ; i++){
                if(strcmp(readTableInfo.lines[i].name,tableInfo->orderKey) == 0){
                    orderLabel = i;
                }
            }
            /* 未找到，报错退出*/
            if(orderLabel == -1){
                printf("sorry , the order key is invalid.\n");
                exit(-22);
            }
            /* 冒泡排序，实现行数据内容交换*/
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
        /* 同理，升序排列*/
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
        /* 判断是否有数据筛选条件、是否选择所有字段
         * 再根据要求打印信息*/
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
                            /* 获取目标字段信息*/
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
            /* 找到筛选关键字段所在列*/
            int keyLabel = -1;
            for(int i = 0 ; i < readTableInfo.lineSize ; i++){
                if(strcmp(readTableInfo.lines[i].name,tableInfo->key) == 0){
                    keyLabel = i;
                }
            }
            /* 未找到，报错退出*/
            if(keyLabel == -1){
                printf("sorry , the key is invalid.\n");
                exit(-22);
            }
            if(tableInfo->chooseAll == True){
                for(int i = 0 ; i < row ; i ++){
                    /* 根据条件筛选数据*/
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
                    /* 筛选行*/
                    if(compareValue(dataArea[i][keyLabel],tableInfo->compare,tableInfo->condition) == True){
                        for(int j = 0 ; j < tableInfo->lineSize ; j ++){
                            for(int k = 0 ; k < readTableInfo.lineSize ; k ++){
                                /* 获取目标列数据*/
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

/* 获取表创建操作所需的命令参数*/
void getArgsTbCreate(TableInfo * tableInfo , char * args){
    char repArgs[DataTypeSize*CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    /* 首先剔除(和)*/
    for(int i = 0 , j = 0 ; i < lenArgs ; i ++){
        if(args[i] != '(' && args[i] != ')'){
            repArgs[j++] = args[i];
        }
    }
    char arg[DataTypeSize*4][CharSize] = {'\0'};
    int argNum = 0 ;
    unsigned long lenRepArgs = strlen(repArgs);
    /* 再将命令逐个拆分*/
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
    /* 获取关键信息，放入tableInfo*/
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

/* 获取表注销和打印表信息操作命令参数*/
void getArgsTbDropAndInfo(TableInfo * tableInfo,char * args){
    char arg[DataTypeSize][CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    int argNum = 0 ;
    /* 将命令逐词拆分*/
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
    /* 关键信息传入tableInfo*/
    for(int i = 0 ; i <= argNum ; i ++){
        if(strcmp(arg[i], "table") == 0){
            strcpy(tableInfo->tableName,arg[i+1]);
        }
    }
}

/* 获取表创建操作的命令参数*/
void getArgsTbInsert(TableInfo * tableInfo, char * args) {
    char repArgs[DataTypeSize * 2 * CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    /* 剔除'*/
    for (int i = 0 , j = 0; i < lenArgs; i++) {
        if (args[i] != '\''){
            repArgs[j++] = args[i];
        }
    }
    char arg[DataTypeSize*4][CharSize] = {'\0'};
    int argNum = 0 ;
    unsigned long lenRep = strlen(repArgs);
    /* 拆分*/
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
    /* 抓取关键字段*/
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

/* 获取表删除信息操作的命令参数*/
void getArgsTbDelete(TableInfo * tableInfo , char * args){
    char repArgs[DataTypeSize*2*CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    /* 剔除'*/
    for(int i = 0 , j = 0 ; i < lenArgs ;i ++){
        if(args[i] !='\''){
            repArgs[j++] = args[i];
        }
    }
    char arg[DataTypeSize*4][CharSize] = {'\0'};
    int argNum = 0 ;
    unsigned long lenRep = strlen(repArgs);
    /* 拆分*/
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
    /* 初始时，将chooseAll设为真*/
    tableInfo->chooseAll = True;
    for(int i = 0 ; i <= argNum ; i ++){
        if(strcmp(arg[i],"from") == 0){
            strcpy(tableInfo->tableName,arg[i+1]);
        }
        /* > = < 是条件筛选选项*/
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
        /* 如果有where，说明条件筛选成立
         * chooseAll设假*/
        if(strcmp(arg[i],"where") == 0){
            tableInfo->chooseAll = False;
        }
    }
}

/* 获取表查询数据操作的命令参数*/
void getArgsTbSelect(TableInfo * tableInfo,char * args){
    unsigned long lenArgs = strlen(args);
    char str[DataTypeSize*2*CharSize] = {'\0'};
    /* 同理，获取单个命令*/
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
    /* 这里根据 * 判断chooseAll的值
     * 根据 < = > 判断筛选条件，筛选字段
     * 由 by 判断是否有排序操作，asc,desc指定升/降序*/
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

/* 获取命令参数操作*/
void getTableArgs(TableInfo * tableInfo){
    /* 提示信息*/
    printf("\n--now, you can manage table\n");
    printf("so, give some operates for it\n");
    char operator[CharSize] = {'\0'};
    char * args = (char *) malloc(sizeof (char )*DataTypeSize*2*CharSize);
    resetString(args);
    /* 先获取操作选项*/
    scanf("%s", operator);
    /* 再抓取参数*/
    gets(args);
    tableInfo->operate = getTableOperator(operator);
    /* 由不同的操作选项调用对应的操作函数*/
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

/* 表管理函数*/
void tableManage(char * dataBasePath){
    /* 显式申请内存*/
    TableInfo * tableInfo = (TableInfo*) malloc(sizeof(TableInfo));
    char * tablePath = (char *) malloc(sizeof(char)*DataTypeSize*CharSize);
    /* 永真迭代*/
    while (1){
        reSetTableInfo(tableInfo);
        getTableArgs(tableInfo);
        /* 获取操作参数，调用对应函数*/
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
    /* 释放内存*/
    free(tableInfo);
    free(tablePath);
}


#include <io.h>
#include <direct.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DataTypeSize 10
#define DataNum 100
#define CharSize 24

typedef struct dbInfo{
    int operate;
    char dataBaseName[CharSize];
}DataBaseInfo;

typedef struct lineInfo{
    int dataType;
    char name[CharSize];
    char value[CharSize];
}LineInfo;

typedef struct tableInfo{
    int operate;
    int lineSize;
    int chooseAll;
    int condition;
    char key[CharSize];
    char compare[CharSize];
    char tableName[CharSize];
    LineInfo lines[DataTypeSize];
}TableInfo;

/*
typedef struct dataArea{
    int intArea[DataTypeSize][DataNum];
    float floatArea[DataTypeSize][DataNum];
    char charArea[DataTypeSize][DataNum][CharSize];
}DataRegion;
*/

enum Operate{Error=-1222,Exit,
        CreateDataBase,DropDataBase,UseDataBase,
        CreateTable,DropTable,GetTableInfo,InsertTableInfo,DeleteTableInfo,SelectTableInfo};

enum tableType{Int,Float,String,TypeError};

enum condition{Small=1222,Equal,Large,False,True};

char dataType[][10] = {"int","float","string"};
char rootPath[] = ".\\";

void creatDataBase(char * dataBaseName){
    if(_access(dataBaseName,0) == -1){
        _mkdir(dataBaseName);
        printf("I have created it.\n");
    }
    else {
        printf("It had exited\n");
    }
}

void dropDataBase(char * dataBaseName){
    if(_access(dataBaseName,0) == -1){
        printf("this folder is not exit\n");
    }
    else{
        rmdir(dataBaseName);
        printf("drop database success.\n");
    }
}

void exitDataBase(){
    printf("so, you' ll out of this database system.\n");
    printf("goodbye,\n");
}

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

void exitTable(){
    printf("you will out of the table manege.\n");
    printf("bye\n");
}

void createTable(char * tablePath, TableInfo * tableInfo){
    if(_access(tablePath,0) == -1){
        FILE * writeBasicInfo = fopen(tablePath,"a+");
        printf("OK, this table is created.\n");
        fprintf(writeBasicInfo,"%d\n",tableInfo->lineSize );
        for(int i = 0 ; i < tableInfo->lineSize ; i++){
            fprintf(writeBasicInfo,"%d ",tableInfo->lines[i].dataType);
        }
        fprintf(writeBasicInfo,"\n");
        for(int i = 0 ; i < tableInfo->lineSize ; i ++){
            fprintf(writeBasicInfo,"%s ",tableInfo->lines[i].name);
        }
        fprintf(writeBasicInfo,"\n");
        fclose(writeBasicInfo);
    }
    else {
        printf("this table is existed.\n");
        printf("thus, new create table is invalid.\n");
    }
}

void dropTable(char * tablePath){
    if(_access(tablePath,0) == -1){
        printf("sorry, this table is not existed.\n");
    }
    else {
        remove(tablePath);
        printf("table delete success.\n");
    }
}

void getTableInfo(char * tablePath){
    if(_access(tablePath,0) == -1){
        printf("error, this table isn't existed.\n");
    }
    else {
        FILE * readBasicInfo = fopen(tablePath,"a+");
        TableInfo getTbInfo;
        fscanf(readBasicInfo,"%d",&getTbInfo.lineSize);
        for(int i = 0 ; i < getTbInfo.lineSize ; i ++){
            fscanf(readBasicInfo,"%d ", &getTbInfo.lines[i].dataType);
        }
        for(int i = 0 ; i < getTbInfo.lineSize ; i ++){
            fscanf(readBasicInfo,"%s",getTbInfo.lines[i].name);
        }
        printf("these are some basic information for this table:\n");
        printf("line size: %d\n",getTbInfo.lineSize);
        printf("lines: ");
        for(int i = 0 ; i < getTbInfo.lineSize  ; i ++){
            printf("%s(%s) ", getTbInfo.lines[i].name, dataType[getTbInfo.lines[i].dataType]);
        }
    }
}

void insertTable(char * tablePath, TableInfo * tableInfo){
    if(_access(tablePath,0) == -1){
        printf("can not insert into information, this table is not existed.\n");
    }
    else {
        FILE * insert = fopen(tablePath,"a+");
        for(int i = 0 ; i < tableInfo->lineSize ; i ++){
            fprintf(insert,"%s ",tableInfo->lines[i].value);
        }
        fprintf(insert,"\n");
        fclose(insert);
        printf("OK, insert success.\n");
    }
}

void deleteTableInfo(char * tablePath, TableInfo * tableInfo){
    TableInfo getTbInfo;
    if(_access(tablePath,0) == -1){
        printf("sorry, there is no such a table.\n");
    }
    else {
        FILE * getInfo = fopen(tablePath,"a+");
        fscanf(getInfo,"%d",&getTbInfo.lineSize);
        for(int i = 0 ; i < getTbInfo.lineSize; i++){
            fscanf(getInfo,"%d",&getTbInfo.lines[i].dataType);
        }
        for(int i = 0 ; i < getTbInfo.lineSize; i++){
            fscanf(getInfo,"%s",getTbInfo.lines[i].name);
        }
        char dataArea[DataNum][DataTypeSize][CharSize] = {'\0'};
        int row = 0 ;
        while (feof(getInfo) == 0){
            for(int j = 0 ; j < getTbInfo.lineSize; j ++){
                fscanf(getInfo,"%s",dataArea[row][j]);
            }
            row ++;
        }
        fclose(getInfo);
        int labelKey = 0;
        for(int i = 0 ; i < getTbInfo.lineSize ; i++ ){
            if(strcmp(getTbInfo.lines[i].name,tableInfo->key) == 0){
                labelKey = i;
                break;
            }
        }
        FILE * updateData = fopen(tablePath,"w");
        fprintf(updateData,"%d\n",getTbInfo.lineSize);
        for(int i = 0 ; i < getTbInfo.lineSize ; i++){
            fprintf(updateData,"%d ",getTbInfo.lines[i].dataType);
        }
        fprintf(updateData,"\n");
        for(int i = 0 ; i < getTbInfo.lineSize; i++){
            fprintf(updateData,"%s ",getTbInfo.lines[i].name);
        }
        fprintf(updateData,"\n");
        if(tableInfo->chooseAll == False){
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

int getTableOperator(char * arg){
    if(strcmp(arg,"create") == 0){
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

void resetString(char * string){
    unsigned long lenStr = strlen(string);
    for(int i = 0 ; i < lenStr ; i ++){
        string[i] = '\0';
    }
}

void getDBArgs(DataBaseInfo * DBInfo){
    printf("--now,you can manage the databases,\n"
           "so, have some operates for them.\n");
    char args[DataTypeSize*CharSize] = {'\0'};
    gets(args);
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

void getArgsTbCreate(TableInfo * tableInfo , char * args){
    char repArgs[DataTypeSize*CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    for(int i = 0 , j = 0 ; i < lenArgs ; i ++){
        if(args[i] != '(' && args[i] != ')'){
            repArgs[j++] = args[i];
        }
    }
    char arg[DataTypeSize*4][CharSize] = {'\0'};
    int argNum = 0 ;
    unsigned long lenRepArgs = strlen(repArgs);
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

void getArgsTbDropAndInfo(TableInfo * tableInfo,char * args){
    char arg[DataTypeSize][CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    int argNum = 0 ;
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
    for(int i = 0 ; i <= argNum ; i ++){
        if(strcmp(arg[i], "table") == 0){
            strcpy(tableInfo->tableName,arg[i+1]);
        }
    }
}

void getArgsTbInsert(TableInfo * tableInfo, char * args) {
    char repArgs[DataTypeSize * 2 * CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    for (int i = 0 , j = 0; i < lenArgs; i++) {
        if (args[i] != '\''){
            repArgs[j++] = args[i];
        }
    }
    char arg[DataTypeSize*4][CharSize] = {'\0'};
    int argNum = 0 ;
    unsigned long lenRep = strlen(repArgs);
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

void getArgsTbDelete(TableInfo * tableInfo , char * args){
    char repArgs[DataTypeSize*2*CharSize] = {'\0'};
    unsigned long lenArgs = strlen(args);
    for(int i = 0 , j = 0 ; i < lenArgs ;i ++){
        if(args[i] !='\''){
            repArgs[j++] = args[i];
        }
    }
    char arg[DataTypeSize*4][CharSize] = {'\0'};
    int argNum = 0 ;
    unsigned long lenRep = strlen(repArgs);
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
    tableInfo->chooseAll = True;
    for(int i = 0 ; i <= argNum ; i ++){
        if(strcmp(arg[i],"from") == 0){
            strcpy(tableInfo->tableName,arg[i+1]);
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
        if(strcmp(arg[i],"where") == 0){
            tableInfo->chooseAll = False;
        }
    }
}

void getTableArgs(TableInfo * tableInfo){
    printf("\n--now, you can manage tables\n");
    printf("so, give some operates for it\n");
    char operator[CharSize] = {'\0'};
    char * args = (char *) malloc(sizeof (char )*DataTypeSize*2*CharSize);
    resetString(args);
    scanf("%s", operator);
    gets(args);
    tableInfo->operate = getTableOperator(operator);
    if(tableInfo->operate == CreateTable){
        getArgsTbCreate(tableInfo,args);
    }
    else if(tableInfo->operate == DropTable){
        getArgsTbDropAndInfo(tableInfo,args);
    }
    else if(tableInfo->operate == GetTableInfo){
        getArgsTbDropAndInfo(tableInfo,args);
    }
    else if(tableInfo->operate == InsertTableInfo){
        getArgsTbInsert(tableInfo,args);
    }
    else if(tableInfo->operate == DeleteTableInfo){
        getArgsTbDelete(tableInfo,args);
    }
    free(args);
}

void getTablePath(char * TbPath, char * DBPath, TableInfo * tableInfo){
    resetString(TbPath);
    sprintf(TbPath,"%s%s%s%s",DBPath,"//",tableInfo->tableName,".txt");
}

void reSetTableInfo(TableInfo * tableInfo){
    tableInfo->lineSize = 0;
    tableInfo->chooseAll = 0;
    resetString(tableInfo->tableName);
    resetString(tableInfo->key);
    resetString(tableInfo->compare);
    for(int i = 0 ; i < DataTypeSize ; i ++){
        resetString(tableInfo->lines[i].name);
        resetString(tableInfo->lines[i].value);
    }
}

void tableManage(char * dataBasePath){
    TableInfo * tableInfo = (TableInfo*) malloc(sizeof(TableInfo));
    char * tablePath = (char *) malloc(sizeof(char)*DataTypeSize*CharSize);
    while (1){
        reSetTableInfo(tableInfo);
        getTableArgs(tableInfo);
        if(tableInfo->operate == Exit){
            free(tablePath);
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

    }
    free(tableInfo);
    free(tablePath);
}

void useDataBase(char * DBPath) {
    if (_access(DBPath, 0) == -1) {
        printf("error, there is no such a database.\n");
    }
    else {
        printf("OK, now enter the database\n");
        tableManage(DBPath);
    }
}


void dataBaseManage(){
    DataBaseInfo * newDBInfo =(DataBaseInfo *) malloc(sizeof(DataBaseInfo));
    char * DBPath = (char *) malloc(sizeof(char)*DataTypeSize*CharSize);
    while (1){
        resetString(newDBInfo->dataBaseName);
        resetString(DBPath);
        getDBArgs(newDBInfo);
        sprintf(DBPath,"%s%s",rootPath,newDBInfo->dataBaseName);
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
    free(newDBInfo);
    free(DBPath);
}

int main(void){
    dataBaseManage();

    return 0;
}

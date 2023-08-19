#include <stdio.h>
#include <string.h>

struct order {
    char Ntype[20];
    char Iput;
    char Oput;
    char move;
    char Stype[20];
};

int main() {
    //获得指令集
    int n;
    scanf("%d", &n);
    struct order opack[500];
    for (int i = 0; i < n; i++) {
        scanf("%s %c %c %c %s",
              &opack[i].Ntype, &opack[i].Iput,
              &opack[i].Oput, &opack[i].move,
              &opack[i].Stype);
    }
    //纸带
    char paper[100];
    scanf("%s", paper);
    //状态量定义
    char now[20] = "INIT";
    int  rwhloc;//读写头位置
    int  stop = 1; //0:停机 1：运行
    int  INSO = 0; //指令集 位置
    int   cmpt = 1;
    int   cmph = 1;
    //读写头定位
    for (int j = 99; j > -1; j--) {
        if (paper[j] == opack[0].Iput) {
            rwhloc = j;
            break;
        }
    }
    //图灵机循环
    do {//指令送入
        do {//状态一致
            //分步执行！
            cmpt = strcmp(now, opack[INSO].Ntype);
            if (cmpt == 0 ) {
                break;
            } else {
                INSO++;
            }
        } while (1);
        //读写头读写数据一致
        do {
            if (paper[rwhloc] == opack[INSO].Iput) {
                cmph = 0;
            } else {
                cmph = 1;
                INSO++;
            }
        } while (cmph != 0);

//指令执行
        //数据改动
        paper[rwhloc] = opack[INSO].Oput;
        //纸带移动
        switch (opack[INSO].move) {
            case 'R':
                rwhloc--;
                break;
            case 'L':
                rwhloc++;
                break;
            default:
                break;
        }
        //状态改变
        strcpy(now, opack[INSO].Stype);
        //    printf("%s\n", now);
        //停机判定
        stop = strcmp(now, "STOP");
    } while (stop != 0);
//纸带修饰
    int len = strlen(paper);
    for (int v = 0; v < len; v++) {
        if (paper[v] >= '0' && paper[v] <= '9') {
            printf("%c", paper[v]);
        }
    }
    return 0;
}

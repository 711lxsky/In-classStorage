/* 此头文件为主功能文件，
 * 引入BitMap.h进行功能开发*/

#include "BitMap.h"

// 宏定义点阵行列数
#define PointNumMax 1000
// 宏定义字符串大小
#define Size 100
// 宏定义颜色数
#define RGB 3

// 命令行参数结构
typedef struct argVs{
    // 参数个数
    int argsNum;
    // bmp源文件1
    char fileName1[Size];
    // bmp源文件2
    char fileName2[Size];
    // 混合百分比
    double percent;
    // 存储混合结果的bmp文件
    char desFileName[Size];
}argValues;

// 源文件1对应的点阵src1
char src1[PointNumMax][PointNumMax][RGB];
// 源文件2对应的点阵src2
char src2[PointNumMax][PointNumMax][RGB];
// 目标文件点阵goal
char goal[PointNumMax][PointNumMax][RGB];

// 存储命令行参数
argValues myArgs;
// 存储信息，对应src1、src2的位图文件头
BitMapFileHeader bmpFileSrc1 , bmpFileSrc2;
// 存储信息，对应src1、src2的位图信息头
BitMapInformationHeader bmpInfoSrc1 , bmpInfoSrc2;

/* 获取命令行参数的函数 */
void getArgVs(int num , char *argv[])
{
    // 直接得到变量个数
    myArgs.argsNum = num;
    // 复制源文件名
    strcpy(myArgs.fileName1,argv[1]);
    strcpy(myArgs.fileName2,argv[3]);

    // 利用循环求出混合比例
    unsigned long long lenPer = strlen(argv[2]);
    double tempRes = 0.0;
    double tempCount = 1.0;
    for(int i = 0 ; i < lenPer ; i++){
        // 数组更迭求值
        if(isdigit(argv[2][i])){
            tempRes = tempRes * 10.0 + (argv[2][i] - '0');
            tempCount *= 10.0;
        }
    }
    tempRes /= tempCount;
    myArgs.percent = tempRes;

    // 直接复制
    strcpy(myArgs.desFileName,argv[4]);
}

/* 混合操作函数*/
void operateBmp()
{
    // 打开源文件1，同时打印提示信息
    FILE * sourFile1 = fopen(myArgs.fileName1,"r+b");
    if(sourFile1==NULL){
        printf("文件1打开失败！\n");
    }
    else {
        printf("文件1打开成功！\n");
    }

    // 同理，打开文件2
    FILE * sourFile2 = fopen(myArgs.fileName2,"r+b");
    if(sourFile2==NULL){
        printf("文件2打开失败！\n");
    }
    else {
        printf("文件2打开成功！\n");
    }

    // 打开目标存储文件
    FILE * desFile = fopen(myArgs.desFileName,"w+b");
    if(desFile==NULL){
        printf("保存文件打开失败！\n");
    }
    else {
        printf("保存文件打开成功！\n");
    }

    // 对src1、src2的位图文件头和信息头进行读取，抓取信息
    fread(&bmpFileSrc1,2*sizeof(char)+2*sizeof(short)+2*sizeof(long),1,sourFile1);
    fread(&bmpFileSrc2,2*sizeof(char)+2*sizeof(short)+2*sizeof(long),1,sourFile2);
    fread(&bmpInfoSrc1,2*sizeof(short)+9*sizeof(long),1,sourFile1);
    fread(&bmpInfoSrc2,2*sizeof(short)+9*sizeof(long),1,sourFile2);

    // 首先判断两文件是否为bmp文件
    if(bmpFileSrc1.bfType[0]=='B'&&bmpFileSrc1.bfType[1]=='M'
       &&bmpFileSrc2.bfType[0]=='B'&&bmpFileSrc2.bfType[1]=='M'){
        // 打印提示信息
        printf("文件1，2都是.bmp文件，继续执行下一步操作\n");
        // 再判断两文件是否都是24位真彩图
        if(bmpInfoSrc1.biBitCount==24&&bmpInfoSrc2.biBitCount==24){
            // 打印对应提示信息
            printf("文件1，2都是24位真彩图，继续下一步操作\n");
            // 最后判断两文件宽度与高度，即大小是否一致
            if(bmpInfoSrc1.biWidth==bmpInfoSrc2.biWidth
               &&bmpInfoSrc1.biHeight==bmpInfoSrc2.biHeight){
                // 打印提示消息
                printf("两图片文件大小一致，准备混合\n");
                // 全部通过后进行混合操作
                // 抓取两文件大小信息
                int width = bmpInfoSrc1.biWidth;
                int height = bmpInfoSrc1.biHeight;
                // Windows二进制文件存储是逆序，所以从下往上读取文件信息，放到src1、src2点阵中
                for(int line = height - 1; line >= 0; line--){
                    for(int row = 0; row < width; row++){
                        // BGR形式存储，逆序RGB读取
                        for(int i = 2 ; i >= 0; i--){
                            fread(&src1[row][line][i],1,1,sourFile1);
                            fread(&src2[row][line][i],1,1,sourFile2);
                        }
                    }
                }

                // 将相关位图文件信息放到goal点阵中，并按比例混合，
                for(int line = height - 1; line >= 0; line--){
                    for(int row = 0 ; row < width; row++){
                        for(int i = 2 ; i >=0 ; i--){
                            goal[row][line][i]=
                                    ((src1[row][line][i] )*myArgs.percent
                                     + (src2[row][line][i])*(1.0-myArgs.percent));
                        }
                    }
                }

                // 将goal点阵信息、位图头相关信息写入存储文件中
                fwrite(&bmpFileSrc1,2*sizeof(char)+2*sizeof(short)+2*sizeof(long),1,desFile);
                fwrite(&bmpInfoSrc1,2*sizeof(short)+9*sizeof(long),1,desFile);
                for(int line = height - 1; line >= 0; line--){
                    for(int row = 0; row < width; row++){
                        for(int i = 2; i >= 0; i--){
                            fwrite(&goal[row][line][i],1,1,desFile);
                        }
                    }
                }

                printf("混合操作执行成功！\n");

            }
            else {
                printf("两图片大小不一致，混合操作无法进行\n");
            }
        }
        else {
            printf("文件1，2中含有非24位真彩图,操作终止\n");
        }
    }
    else {
        printf("文件1，2中有非bmp文件,无法继续操作\n");
    }

    // 执行完毕后关闭文件流
    fclose(sourFile1);
    fclose(sourFile2);
    fclose(desFile);

}


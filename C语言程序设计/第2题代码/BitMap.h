/*此头文件 用于存放位图结构
 *封装后便于引入 */

// 引入相关所需库
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 位图文件头 结构
typedef struct BMPFileHead{

    // 检查读入文件类型
    char  bfType[2];

    // 位图文件大小，以字节为单位
    long bfSize;
    // 保留与否，强制设为0
    short  bfReserved1;
    short  bfReserved2;
    // 从文件头开始到实际图像数据之间偏移量
    long bfOffBits;
}BitMapFileHeader;

// 位图信息头 结构
typedef struct BMPInfoHead{
    // BMP信息头结构占据的字节数
    long biSize;

    // 图宽，以像素为单位
    long biWidth;
    // 图高，以像素为单位
    long biHeight;

    // 为目标设备说明位面数，其值总是被置为1
    short  biPlanes;

    // 像素点位深度，值为1、4、8、16、24、32
    short  biBitCount;

    // 图像数据压缩类型，0(BI_RGB)表示不压缩
    long biCompression;
    // 图像大小，以字节为单位
    long biSizeImage;
    // 水平分辨率，单位为像素/米，一般可忽略
    long biXPelsPerMeter;
    // 垂直分辨率，单位为像素/米，一般可忽略
    long biYPelsPerMeter;
    // 位图实际使用的调色板中颜色索引数，0表示使用所有调色板颜色
    long biClrUsed;
    // 对图像显示有重要影响的颜色索引的数目，0表示所有颜色都重要
    long biClrImportant;
}BitMapInformationHeader;


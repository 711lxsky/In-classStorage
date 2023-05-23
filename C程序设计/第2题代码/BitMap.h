/*��ͷ�ļ� ���ڴ��λͼ�ṹ
 *��װ��������� */

// ������������
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// λͼ�ļ�ͷ �ṹ
typedef struct BMPFileHead{

    // �������ļ�����
    char  bfType[2];

    // λͼ�ļ���С�����ֽ�Ϊ��λ
    long bfSize;
    // �������ǿ����Ϊ0
    short  bfReserved1;
    short  bfReserved2;
    // ���ļ�ͷ��ʼ��ʵ��ͼ������֮��ƫ����
    long bfOffBits;
}BitMapFileHeader;

// λͼ��Ϣͷ �ṹ
typedef struct BMPInfoHead{
    // BMP��Ϣͷ�ṹռ�ݵ��ֽ���
    long biSize;

    // ͼ��������Ϊ��λ
    long biWidth;
    // ͼ�ߣ�������Ϊ��λ
    long biHeight;

    // ΪĿ���豸˵��λ��������ֵ���Ǳ���Ϊ1
    short  biPlanes;

    // ���ص�λ��ȣ�ֵΪ1��4��8��16��24��32
    short  biBitCount;

    // ͼ������ѹ�����ͣ�0(BI_RGB)��ʾ��ѹ��
    long biCompression;
    // ͼ���С�����ֽ�Ϊ��λ
    long biSizeImage;
    // ˮƽ�ֱ��ʣ���λΪ����/�ף�һ��ɺ���
    long biXPelsPerMeter;
    // ��ֱ�ֱ��ʣ���λΪ����/�ף�һ��ɺ���
    long biYPelsPerMeter;
    // λͼʵ��ʹ�õĵ�ɫ������ɫ��������0��ʾʹ�����е�ɫ����ɫ
    long biClrUsed;
    // ��ͼ����ʾ����ҪӰ�����ɫ��������Ŀ��0��ʾ������ɫ����Ҫ
    long biClrImportant;
}BitMapInformationHeader;


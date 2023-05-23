/* ��ͷ�ļ�Ϊ�������ļ���
 * ����BitMap.h���й��ܿ���*/

#include "BitMap.h"

// �궨�����������
#define PointNumMax 1000
// �궨���ַ�����С
#define Size 100
// �궨����ɫ��
#define RGB 3

// �����в����ṹ
typedef struct argVs{
    // ��������
    int argsNum;
    // bmpԴ�ļ�1
    char fileName1[Size];
    // bmpԴ�ļ�2
    char fileName2[Size];
    // ��ϰٷֱ�
    double percent;
    // �洢��Ͻ����bmp�ļ�
    char desFileName[Size];
}argValues;

// Դ�ļ�1��Ӧ�ĵ���src1
char src1[PointNumMax][PointNumMax][RGB];
// Դ�ļ�2��Ӧ�ĵ���src2
char src2[PointNumMax][PointNumMax][RGB];
// Ŀ���ļ�����goal
char goal[PointNumMax][PointNumMax][RGB];

// �洢�����в���
argValues myArgs;
// �洢��Ϣ����Ӧsrc1��src2��λͼ�ļ�ͷ
BitMapFileHeader bmpFileSrc1 , bmpFileSrc2;
// �洢��Ϣ����Ӧsrc1��src2��λͼ��Ϣͷ
BitMapInformationHeader bmpInfoSrc1 , bmpInfoSrc2;

/* ��ȡ�����в����ĺ��� */
void getArgVs(int num , char *argv[])
{
    // ֱ�ӵõ���������
    myArgs.argsNum = num;
    // ����Դ�ļ���
    strcpy(myArgs.fileName1,argv[1]);
    strcpy(myArgs.fileName2,argv[3]);

    // ����ѭ�������ϱ���
    unsigned long long lenPer = strlen(argv[2]);
    double tempRes = 0.0;
    double tempCount = 1.0;
    for(int i = 0 ; i < lenPer ; i++){
        // ���������ֵ
        if(isdigit(argv[2][i])){
            tempRes = tempRes * 10.0 + (argv[2][i] - '0');
            tempCount *= 10.0;
        }
    }
    tempRes /= tempCount;
    myArgs.percent = tempRes;

    // ֱ�Ӹ���
    strcpy(myArgs.desFileName,argv[4]);
}

/* ��ϲ�������*/
void operateBmp()
{
    // ��Դ�ļ�1��ͬʱ��ӡ��ʾ��Ϣ
    FILE * sourFile1 = fopen(myArgs.fileName1,"r+b");
    if(sourFile1==NULL){
        printf("�ļ�1��ʧ�ܣ�\n");
    }
    else {
        printf("�ļ�1�򿪳ɹ���\n");
    }

    // ͬ�����ļ�2
    FILE * sourFile2 = fopen(myArgs.fileName2,"r+b");
    if(sourFile2==NULL){
        printf("�ļ�2��ʧ�ܣ�\n");
    }
    else {
        printf("�ļ�2�򿪳ɹ���\n");
    }

    // ��Ŀ��洢�ļ�
    FILE * desFile = fopen(myArgs.desFileName,"w+b");
    if(desFile==NULL){
        printf("�����ļ���ʧ�ܣ�\n");
    }
    else {
        printf("�����ļ��򿪳ɹ���\n");
    }

    // ��src1��src2��λͼ�ļ�ͷ����Ϣͷ���ж�ȡ��ץȡ��Ϣ
    fread(&bmpFileSrc1,2*sizeof(char)+2*sizeof(short)+2*sizeof(long),1,sourFile1);
    fread(&bmpFileSrc2,2*sizeof(char)+2*sizeof(short)+2*sizeof(long),1,sourFile2);
    fread(&bmpInfoSrc1,2*sizeof(short)+9*sizeof(long),1,sourFile1);
    fread(&bmpInfoSrc2,2*sizeof(short)+9*sizeof(long),1,sourFile2);

    // �����ж����ļ��Ƿ�Ϊbmp�ļ�
    if(bmpFileSrc1.bfType[0]=='B'&&bmpFileSrc1.bfType[1]=='M'
       &&bmpFileSrc2.bfType[0]=='B'&&bmpFileSrc2.bfType[1]=='M'){
        // ��ӡ��ʾ��Ϣ
        printf("�ļ�1��2����.bmp�ļ�������ִ����һ������\n");
        // ���ж����ļ��Ƿ���24λ���ͼ
        if(bmpInfoSrc1.biBitCount==24&&bmpInfoSrc2.biBitCount==24){
            // ��ӡ��Ӧ��ʾ��Ϣ
            printf("�ļ�1��2����24λ���ͼ��������һ������\n");
            // ����ж����ļ������߶ȣ�����С�Ƿ�һ��
            if(bmpInfoSrc1.biWidth==bmpInfoSrc2.biWidth
               &&bmpInfoSrc1.biHeight==bmpInfoSrc2.biHeight){
                // ��ӡ��ʾ��Ϣ
                printf("��ͼƬ�ļ���Сһ�£�׼�����\n");
                // ȫ��ͨ������л�ϲ���
                // ץȡ���ļ���С��Ϣ
                int width = bmpInfoSrc1.biWidth;
                int height = bmpInfoSrc1.biHeight;
                // Windows�������ļ��洢���������Դ������϶�ȡ�ļ���Ϣ���ŵ�src1��src2������
                for(int line = height - 1; line >= 0; line--){
                    for(int row = 0; row < width; row++){
                        // BGR��ʽ�洢������RGB��ȡ
                        for(int i = 2 ; i >= 0; i--){
                            fread(&src1[row][line][i],1,1,sourFile1);
                            fread(&src2[row][line][i],1,1,sourFile2);
                        }
                    }
                }

                // �����λͼ�ļ���Ϣ�ŵ�goal�����У�����������ϣ�
                for(int line = height - 1; line >= 0; line--){
                    for(int row = 0 ; row < width; row++){
                        for(int i = 2 ; i >=0 ; i--){
                            goal[row][line][i]=
                                    ((src1[row][line][i] )*myArgs.percent
                                     + (src2[row][line][i])*(1.0-myArgs.percent));
                        }
                    }
                }

                // ��goal������Ϣ��λͼͷ�����Ϣд��洢�ļ���
                fwrite(&bmpFileSrc1,2*sizeof(char)+2*sizeof(short)+2*sizeof(long),1,desFile);
                fwrite(&bmpInfoSrc1,2*sizeof(short)+9*sizeof(long),1,desFile);
                for(int line = height - 1; line >= 0; line--){
                    for(int row = 0; row < width; row++){
                        for(int i = 2; i >= 0; i--){
                            fwrite(&goal[row][line][i],1,1,desFile);
                        }
                    }
                }

                printf("��ϲ���ִ�гɹ���\n");

            }
            else {
                printf("��ͼƬ��С��һ�£���ϲ����޷�����\n");
            }
        }
        else {
            printf("�ļ�1��2�к��з�24λ���ͼ,������ֹ\n");
        }
    }
    else {
        printf("�ļ�1��2���з�bmp�ļ�,�޷���������\n");
    }

    // ִ����Ϻ�ر��ļ���
    fclose(sourFile1);
    fclose(sourFile2);
    fclose(desFile);

}


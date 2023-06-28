package OMWork5.task2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

/* 引入相关包
* 浮点数二进制文件操作类*/
public class DataWriteTest {

    public static void main(String[] args) {
        /* 这里将浮点数存储于Double类数组中，
           方便后续调用类方法，直接转换成String类型*/
        Double[] digits = new Double[]{1.23, 69.88, 34.45, 67.98, 2345.67};
        /* 存放转换而来的Long类型数据*/
        long [] digitsLong = new long[5];
        for (int i = 0; i < 5; i++) {
            digitsLong[i] = Double.doubleToLongBits(digits[i]);
        }
        /* 存放转换而来的二进制double底层数据字符串*/
        String [] strNums = new String[5];
        for(int i = 0 ; i < 5 ; i ++){
            strNums[i] = Long.toBinaryString(digitsLong[i]);
        }
        /* 检验是否转换成功*/
        for (String str : strNums) {
            System.out.println(str);
        }
        /* 因为使用二进制数据存储，所以使用byte类型*/
        byte[][] byteData = new byte[5][];
        for (int i = 0 ; i < 5 ; i ++){
            byteData[i] = strNums[i].getBytes();
        }
        /* 打印信息，检验是否转换成功*/
        for(byte[] bytes : byteData){
            for (byte aByte : bytes) {
                System.out.print(aByte + "  ");
            }
            System.out.println("----------");
        }

        /* 这里直接新建文件类对象*/
        File dataFile = new File("data.dat");
        if(dataFile.exists()){
            System.out.println("data.dat has existed");
        }
        else {
            /* 异常块处理*/
            try {
                dataFile.createNewFile();
            }
            catch (Exception e){
                System.out.println("can't creat it.");
            }
        }

        /* 字节二进制流写入操作*/
        try {
            FileOutputStream dataPut = new FileOutputStream(dataFile);
            for (byte[] bytes : byteData){
                dataPut.write(bytes);
                dataPut.write("\n".getBytes());
            }
            /* 请空缓冲区，关闭流*/
            dataPut.flush();
            dataPut.close();
            System.out.println("data write is done.");
        }
        /* 两个catch处理可能出现的异常*/
        catch (FileNotFoundException e){
            System.out.println("can not fine it!");
        }
        catch (IOException e){
            System.out.println("can't write");
        }
    }
}

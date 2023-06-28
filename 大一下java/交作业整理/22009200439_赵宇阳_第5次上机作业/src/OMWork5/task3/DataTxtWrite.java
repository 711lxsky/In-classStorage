package OMWork5.task3;

/* 引入相关包*/
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

/* 数据本文形式写入类*/
public class DataTxtWrite {
    public static void main(String[] args) {
        /* 数据数组*/
        double [] digits = new double[]{1.23,69.88,34.45,67.98,2345.67};
        String [] stringNums = new String[5];
        /* 转换为字符串形式*/
        for(int i = 0 ; i < 5 ; i ++){
            stringNums[i] = Double.toString(digits[i]);
        }
        /* 新建文件操作*/
        File dataFile = new File("data.txt");
        if(dataFile.exists()){
            System.out.println("this file is existed.");
        }
        else {
            /* 不存在文件，则创建
            * 处理异常块*/
            try {
                dataFile.createNewFile();
                System.out.println("OK, I create id.");
            }
            catch (IOException e){
                System.out.println("can't create it.");
            }
        }
        /* 数据字符串写入*/
        try {
            /* 异常处理*/
            FileWriter fileWriter = new FileWriter(dataFile);
            for(String digit : stringNums){
                fileWriter.write(digit);
                fileWriter.write("\n");
            }
            /* 清空缓冲区，关闭流*/
            fileWriter.flush();
            fileWriter.close();
            System.out.println("Write with .txt is done.");
        } catch (IOException e) {
            System.out.println("can't write data.");
        }
    }
}

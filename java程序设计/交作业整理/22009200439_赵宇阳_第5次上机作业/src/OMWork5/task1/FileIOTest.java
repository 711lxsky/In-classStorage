package OMWork5.task1;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

/* 引入相关包
*  文件操作测试类，直接在main中写*/
public class FileIOTest {
    public static void main(String[] args) {
        /* 单纯写文件操作
           设计交互，打印信息*/
        System.out.println("now you can enter a file name by .txt, then I will creat it");
        Scanner myGet = new Scanner(System.in);
        /* 读取信息*/
        String fileName1 = myGet.nextLine();
        System.out.println("I get it: "+fileName1);
        /* 实例化文件对象*/
        File file1 = new File(fileName1);
        if(file1.exists()){
            System.out.println("it has existed");
        }
        else {
            /* 异常块处理
            * 注意，此处默认的是文件没有创建，本地新建后写入数据*/
            try {
                System.out.println("OK, I created it just now. Then, enter a sentence and I will write in the file1");
                String context1 = myGet.nextLine();
                FileWriter file1Write = new FileWriter(file1);
                file1Write.write(context1);
                /* 清空缓冲区，关闭流*/
                file1Write.flush();
                file1Write.close();
            }
            catch (Exception creatException){
                /* 处理异常*/
                System.out.println("can't creat this file!");
            }
            finally {
                System.out.println("write is done");
            }
        }

        /* 从刚才创建的文件中读取数据，并写入新文件
        *  打印交互信息*/
        System.out.println("now enter another one filename with .txt");
        String fileName2 = myGet.nextLine();
        System.out.println("OK, I get it: "+fileName2);
        File file2 = new File(fileName2);
        if(file2.exists()){
            System.out.println("it exists");
        }
        else {
            /* 异常块处理原理同上*/
            try {
                file2.createNewFile();
                /* 创建字符读写流*/
                FileReader reader = new FileReader(file1);
                FileWriter writer = new FileWriter(file2);
                /* 创建存储字符信息的内存块*/
                char [] getContext = new char[100];
                /* 从目标文件中读取数据，放入申请的内存块中*/
                reader.read(getContext);
                /* 关闭流*/
                reader.close();
                /* 把数据写入存储文件*/
                for (int i = 0 ; getContext[i] != '\0' ; i ++){
                    writer.write(getContext[i]);
                }
                /* 清空缓冲区，关闭流*/
                writer.flush();
                writer.close();
            }
            catch (Exception e){
                /* 同理，处理异常*/
                System.out.println("create error");
            }
            finally {
                System.out.println("read and write are done.");
            }
        }

    }
}

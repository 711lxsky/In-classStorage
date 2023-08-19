package OMWork5.task4;

/* 引入所需相关包*/
import java.io.*;
import java.util.Scanner;

/* 自定义文件操作类*/
public class FileIO {
    /* 类方法，对文件内容进行复制操作*/
    public static void fileCopy(String readFileName, String writeFileName){
        /* 先判断两个文件路径是否相同*/
        if(readFileName.equals(writeFileName)){
            System.out.println("those two file are equal.");
        }
        else {
            /* 创建文件操作类实例*/
            File sourceFile = new File(readFileName);
            File destFile = new File(writeFileName);
            if(! sourceFile.exists()){
                /* 源文件不存在*/
                System.out.println("error, the source file is not existed.");
            }
            else {
                if( destFile.exists()){
                    /* 目标文件已经存在*/
                    System.out.println("wrong, the dest file is existed.");
                }
                else {
                    try {
                        /* 目标文件不存在，创建文件*/
                        destFile.createNewFile();
                    }
                    catch (IOException e){
                        /* 处理异常*/
                        System.out.println("sorry, Can't create the dest file.");
                    }

                    /* 对内容进行操作*/
                    try {
                        /* 新建文件输入输出字节流*/
                        FileInputStream reader = new FileInputStream(sourceFile);
                        FileOutputStream writer = new FileOutputStream(destFile);
                        Long fileLength = sourceFile.length();
                        /* 获取文件长度，新建字节数组用以存储文件字节数据*/
                        byte[] content = new byte[fileLength.intValue()];
                        /* 读取*/
                        reader.read(content);
                        reader.close();
                        /* 写入*/
                        writer.write(content);
                        writer.flush();
                        writer.close();
                        /* 打印提示信息*/
                        System.out.println("OK, the copy is done.");
                    }
                    /* 异常块处理*/
                    catch (FileNotFoundException e){
                        System.out.println("sorry, can't find the source file");
                    }
                    catch (IOException e){
                        System.out.println("error, can't write into the dest file");
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        /* main中进行交互，调用静态类方法*/
        System.out.println("now, enter two file name, I'll copy the content.");
        Scanner myGet = new Scanner(System.in);
        System.out.println("So, enter the source file:");
        String sourceFileName = myGet.nextLine();
        System.out.println("and, the dest file:");
        String destFileName = myGet.nextLine();
        FileIO.fileCopy(sourceFileName,destFileName);
    }
}

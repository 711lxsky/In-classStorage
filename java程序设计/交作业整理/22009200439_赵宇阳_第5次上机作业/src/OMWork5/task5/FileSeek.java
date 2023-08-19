package OMWork5.task5;

/* 引入相关包*/
import java.io.*;
import java.util.Scanner;
import java.util.Vector;

/* 目标字符串查找类*/
public class FileSeek {

    /* 类静态方法，以目标字符串和目录为参数*/
    public static void seekFile(String dest, String folderName){
        /* 结果文件路径存储容器*/
        Vector<String> destFiles = new Vector<>();
        /* 对目录新建文件对象*/
        File folder = new File(folderName);
        /* 先检查目录是否存在且是否真的为目录*/
        if(folder.exists() && folder.isDirectory()){
            /* 返回子文件名列表，放入String数组中*/
            String [] fileNames = folder.list();
            int fileNum = 0;
            if (fileNames != null) {
                fileNum = fileNames.length;
            }
            /* 文件对象数组*/
            File [] files = new File[fileNum];
            for(int i = 0 ; i < fileNum ; i ++){
                /* 使用相对路径*/
                files[i] = new File(folder+".//"+fileNames[i]);
                try {
                    /* 读取并校验文本数据*/
                    FileReader reader = new FileReader(files[i]);
                    BufferedReader readPtr = new BufferedReader(reader);
                    String stringGet;
                    while ((stringGet = readPtr.readLine()) != null){
                        if(stringGet.contains(dest)){
                            destFiles.add(files[i].getAbsolutePath());
                            break;
                        }
                    }
                }
                /* 异常处理块*/
                catch (FileNotFoundException e){
                    System.out.println("can't find "+fileNames[i]);
                }
                catch (IOException e){
                    System.out.println("can't read it");
                }
            }
            /* 打印结果*/
            for (String destFile : destFiles) {
                System.out.println(destFile);
            }
        }
        else {
            System.out.println("sorry, this folder is not existed.");
        }
    }

    /* main中直接进行交互和方法测试*/
    public static void main(String[] args) {
        System.out.println("now enter your dest string.");
        Scanner myGet = new Scanner(System.in);
        String destString = myGet.nextLine();
        System.out.println("then, enter the folder name.");
        String folderName = myGet.nextLine();
        System.out.println("those are the results which file contains the dest string");
        FileSeek.seekFile(destString,folderName);
    }
}

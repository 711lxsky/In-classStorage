package OMWork5.task6;

/* 引入相关包*/
import java.io.*;
import java.util.Scanner;

/* 文件数据解析类*/
public class FileAnalyse {
    public static void main(String[] args) {
        /* 新建整数数组以存储读到的字符数据数量*/
        int [] letterNum = new int[26];
        /* 交互，数据录入*/
        System.out.println("now, enter your dest letter:");
        Scanner myGet = new Scanner(System.in);
        String destLetter = myGet.nextLine();
        System.out.println("then, enter your dest string");
        String destString = myGet.nextLine();
        System.out.println("last, enter your the special file path:");
        String fileName = myGet.nextLine();
        File readFile = new File(fileName);
        int strNum = 0 ;
        try {
            /* 字符数据读取流*/
            FileReader reader = new FileReader(readFile);
            char getChar;
            BufferedReader readPtr = new BufferedReader(reader);
            while ((getChar =(char) readPtr.read()) != (char)  -1){
                if(getChar >= 'a' && getChar <= 'z'){
                    letterNum[getChar-'a'] ++;
                }
            }
            readPtr.close();
            /* 字符串数据读取*/
            FileReader readerStr = new FileReader(fileName);
            BufferedReader readerStrPtr = new BufferedReader(readerStr);
            String strGet;
            while ((strGet = readerStrPtr.readLine()) != null){
                if(strGet.contains(destString)){
                    strNum++;
                }
            }
            readerStr.close();
            reader.close();
            /* 打印运行结果*/
            System.out.println("the dest letter times: "+letterNum[destLetter.charAt(0)-'a']);
            System.out.println("the dest string num: "+strNum);
        }
        /* 异常处理*/
        catch (FileNotFoundException e){
            System.out.println("sorry, can't find the file");
        }
        catch (IOException e){
            System.out.println("error, can't read it.");
        }
    }
}

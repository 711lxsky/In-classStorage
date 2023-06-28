package OMWork5.task7;

/* 引入相关包*/
import java.io.*;
import java.util.Scanner;

/* 英文文档数据分析类*/
public class EnglishFileAnalyse {
    public static void main(String[] args) {
        /* 字母个数*/
        int [] letterNum = new int[26];
        /* 段落数*/
        int paraNum = 1;
        /* 单词数*/
        int wordNum = 0;
        /* 交互，输入文件名*/
        System.out.println("now, enter the special file path: ");
        Scanner myGet = new Scanner(System.in);
        String fileName = myGet.nextLine();
        File file = new File(fileName);
        try {
            /* 新建文件读取流*/
            FileReader reader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(reader);
            char charGet;
            while ((charGet =(char) bufferedReader.read()) != (char) -1){
                /* 针对读到的每个字符进行判断*/
                if(charGet == ' '){
                    wordNum ++;
                }
                else if(charGet == '\n'){
                    paraNum ++;
                    wordNum++;
                }
                else if(charGet >= 'a' && charGet <= 'z'){
                    letterNum[charGet-'a']++;
                }
            }
            /* 打印信息*/
            for(int i = 0 ; i < 26 ; i ++){
                System.out.println("the letter "+(char)('a'+i)+" num: "+letterNum[i]);
            }
            System.out.println("the paragraph num: "+paraNum);
            System.out.println("the word num: "+wordNum);
        }
        /* 异常块处理*/
        catch (FileNotFoundException e){
            System.out.println("can' t find the file.");
        }
        catch (IOException e){
            System.out.println("sorry, can't read it");
        }
    }
}

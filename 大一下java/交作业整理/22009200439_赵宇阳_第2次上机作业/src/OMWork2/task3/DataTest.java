package OMWork2.task3;

import java.util.Scanner;

/* 数据测试类*/
public class DataTest {

    /* 将数字星期数转换为汉字星期*/
    public static void changeNum(int weekNum){
        switch (weekNum){
            case 0:
                System.out.print("日");
            case 1:
                System.out.print("一");
                break;
            case 2:
                System.out.print("二");
                break;
            case 3:
                System.out.print("三");
                break;
            case 4:
                System.out.print("四");
                break;
            case 5:
                System.out.print("五");
                break;
            case 6:
                System.out.print("六");
                break;
        }
        System.out.println();
    }
    /* 静态类方法，读取日期，返回星期数*/
    public static void getDataWeekNum(){
        System.out.println("请输入日期，我将计算其对应星期数");
        Scanner myGet = new Scanner(System.in);
        System.out.print("年份：");
        int year = myGet.nextInt();
        System.out.print(" 月份：");
        int month = myGet.nextInt();
        System.out.print(" 日：");
        int day = myGet.nextInt();
        DateOperator data = new DateOperator(year,month,day);
        int weekNum = data.getWeekNum();
        System.out.print("这天是星期");
        changeNum(weekNum);
    }

    /* 静态类方法，读取年份，打印年日历*/
    public static void getCalender(){
        System.out.println("请输入年份，我将打印该年份日历");
        System.out.print("年份：");
        Scanner myGet = new Scanner(System.in);
        int year = myGet.nextInt();
        System.out.println();
        DateOperator data = new DateOperator(year);
        data.printCalender();
    }
    /* 在main中测试*/
    public static void main(String[] args) {
        getDataWeekNum();
        getCalender();
    }
}

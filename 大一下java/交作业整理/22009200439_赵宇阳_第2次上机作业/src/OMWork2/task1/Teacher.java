package OMWork2.task1;

import java.util.Scanner;

// 老师类
public class Teacher {

    String identifier;
    String name;
    String job;
    String department;

    // 默认无参构造函数
    public Teacher(){

    }

    // 调用接口计算平均成绩，并打印
    public void getAndPrintStuGrade(double chinese, double English , double math){
        Student student = new Student(chinese , English , math);
        double aveGrade = student.getAverageGrade();
        System.out.println("this student's average grade is:"+aveGrade);
    }

    // 读入数据，实例化对象，调用API
    public static void main(String[] args) {
        Scanner myGet = new Scanner(System.in);
        System.out.println("please enter the student's three grades,\n" +
                "then I will give the average.");
        double chineseGrade = myGet.nextDouble();
        double EnglishGrade = myGet.nextDouble();
        double mathGrade = myGet.nextDouble();
        Teacher teacher = new Teacher();
        teacher.getAndPrintStuGrade(chineseGrade,EnglishGrade,mathGrade);
    }
}

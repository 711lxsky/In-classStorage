package OMWork2.task2;

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

    // 方法用以计算学生数组中每个学生的平均成绩
    public void getAndPrintAllStuGrades(Student[] students){
        int i = 0 ;
        for(Student student : students){
            i ++;
            double averageGrade = (student.chineseGrade+student.EnglishGrade+student.mathGrade)/3.0;
            System.out.println("the student "+i+"'s averageGrade is "+averageGrade);
        }
    }

    // 读入数据，实例化对象，调用API
    public static void main(String[] args) {
        // 新建指向
        Student[] students = new Student[10] ;
        Scanner myGet = new Scanner(System.in);
        // 读入数据
        System.out.println("please enter the students' grades,\n" +
                "then I will give those averages.");
        for (int i = 0 ; i < 10 ; i ++) {
            double chineseGrade = myGet.nextDouble();
            double EnglishGrade = myGet.nextDouble();
            double mathGrade = myGet.nextDouble();
            // 新建对象
            students[i] = new Student(chineseGrade,EnglishGrade,mathGrade);
        }
        Teacher teacher = new Teacher();
        // 调用teacher类方法
        teacher.getAndPrintAllStuGrades(students);
    }
}

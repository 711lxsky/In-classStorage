package OMWork3.task1;

/* 抽象类Student*/
public abstract class Student {
    String name;
    String course;
    double grade;

    public Student(){

    }

    /* 单grade参数构造函数*/
    public Student(double grade) {
        this.name = "normal student";
        this.course = "common course";
        this.grade = grade;
    }

    /* 全参构造函数*/
    public Student(String name, String course, double grade) {
        this.name = name;
        this.course = course;
        this.grade = grade;
    }

    /* 定义抽象方法，得到成绩等级*/
    public abstract String getGradeRank();

    /* 抽象方法，打印等级*/
    public abstract void printGradeRank();
}

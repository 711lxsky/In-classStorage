package OMWork2.task2;

//学生类
public class Student {

    String identifier;
    String name;
    String className;
    double chineseGrade;
    double EnglishGrade;
    double mathGrade;

    // 无参构造函数
    public Student(){

    }

    /* 类构造函数 */
    public Student(double chiGra,double EngGra,double mathGra){
        this.chineseGrade = chiGra;
        this.EnglishGrade = EngGra;
        this.mathGrade = mathGra;
    }

    /* 计算成绩平均值函数*/
    public double getAverageGrade(){
        double averageGrade = (chineseGrade + EnglishGrade + mathGrade) / 3.0;
        return averageGrade;
    }
}

package OMWork3.task1;

/* 子类Undergraduate 实现父类抽象类，实现多态*/
public class Undergraduate extends Student{

    public Undergraduate() {
    }

    public Undergraduate(double grade) {
        super(grade);
    }

    public Undergraduate(String name, String course, double grade) {
        super(name, course, grade);
    }

    /* 实现抽象方法，评价稍松*/
    @Override
    public String getGradeRank() {
        if(this.grade - 60.0 < 0.0){
            return "fail";
        }
        else if(this.grade - 80.0 < 0.0 && this.grade -60.0 >= 0.0){
            return "pass";
        }
        else if(this.grade - 90.0 < 0.0 && this.grade - 80.0 >= 0.0){
            return "good";
        }
        else {
            return "excellent";
        }
    }

    /* 抽象方法实现，打印信息和等级*/
    @Override
    public void printGradeRank() {
        System.out.print(this.name+"  "+this.course+"  "+this.grade);
        System.out.println("  here is a undergraduate, and this people's rank is: "+this.getGradeRank());
    }
}

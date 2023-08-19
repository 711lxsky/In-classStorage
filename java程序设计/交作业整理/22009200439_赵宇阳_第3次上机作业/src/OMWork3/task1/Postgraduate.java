package OMWork3.task1;

/* 子类Postgraduate实现抽象父类*/
public class Postgraduate extends Student{

    public Postgraduate() {
    }

    public Postgraduate(double grade) {
        super(grade);
    }

    public Postgraduate(String name, String course, double grade) {
        super(name, course, grade);
    }

    /* 同理，稍严格*/
    @Override
    public String getGradeRank() {
        if(this.grade - 60.0 < 0.0){
            return "fail";
        }
        else if(this.grade - 70.0 < 0.0 && this.grade -60.0 >= 0.0){
            return "pass";
        }
        else if(this.grade - 80.0 < 0.0 && this.grade - 70.0 >= 0.0){
            return "notBad";
        }
        else if(this.grade - 95.0 < 0.0 && this.grade - 80.0 >= 0.0){
            return "good";
        }
        else {
            return "excellent";
        }
    }

    /* 同理*/
    @Override
    public void printGradeRank() {
        System.out.print(this.name+"  "+this.course+"  "+this.grade);
        System.out.println("  here is a postgraduate, besides this people's rank is: "+this.getGradeRank());
    }
}

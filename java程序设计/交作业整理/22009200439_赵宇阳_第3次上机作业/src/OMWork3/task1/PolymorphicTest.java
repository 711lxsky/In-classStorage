package OMWork3.task1;

/* 测试类，新建数组，校验多态实现*/
public class PolymorphicTest {

    public static void main(String[] args) {
        Student [] students = new Student[10];
        for(int i = 0 ; i < 10 ; i ++){
            if(i % 2 != 0){
                students[i] = new Postgraduate("post"+i/2+1,"postCourse",i*10.0 + 9.0);
            }
            else {
                students[i] = new Undergraduate("under"+i/2,"underCourse",i*10.0 + 9.0);
            }
        }
        for(Student student : students){
            student.printGradeRank();
        }
    }
}

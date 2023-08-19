package OMWork4.task1;

import OMWork2.task1.Student;

/* 异常测试类D*/
public class ExceptionTestD {

    public static void main(String[] args) {

        /*try{
            newClass myClass = new newClass();
            test = 0;
        }
        catch (NoSuchFieldException checkException1){
            System.out.println("get checked, no suck a field");
        }
        catch (ClassNotFoundException checkException2){

        }
        finally {
            System.out.println("arrive the first finally");
        }*/
        /* 第一个大异常块是测试受检异常
        * 可以看到，在IDE中这一类异常会被直接发现
        * 使用命令行运行也会被直接找到，无法编译
        * 即无论怎样程序都无法正常运行*/

        try{
            Student student = null;
            student.getAverageGrade();
        }
        catch (NullPointerException notCheckException){
            System.out.println("this is a notCheckedException, the class point is null");
        }
        finally {
            System.out.println("get the second finally");
        }
        /* 第二个异常块用以检测免检异常
        * 通过这个块和前面几个测试类，可以知道
        * try块的异常被catch后程序可以运行，
        * 而未被catch则会终止程序
        * 即免检异常在合理的处理下是不会影响程序运行的*/
    }
}

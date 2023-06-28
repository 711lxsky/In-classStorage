package OMWork4.task1;

/* 异常测试类B*/
public class ExceptionTestB {
    public static void main(String[] args) {

        try {
            int temp = 5 / 0;
        }
        catch (ArithmeticException exception){
          //  return ;
        }
        finally {
            System.out.println("this is the first finally");
        }
        /* 第一个异常大块使用return,
         可以看到使用return，进入finally后直接终止了程序*/


        try {
            int  temp = 0;
            if(temp == 0 ){
                throw new ArithmeticException("you divide a 0 !");
            }
        }
        catch (ArithmeticException exception){
            System.out.print(exception.getMessage());
            System.out.println(" can't divide zero!");
            // throw new ArithmeticException("you divide a 0 !");
        }
        catch (ClassCastException exceptionTest){
            System.out.println("just test");
        }
        finally {
            System.out.println("this is the second finally");
        }
        /* 第二个大异常块使用throw，
        * 试运行后发现抛出异常并被catch后不会中断程序，将继续运行
        * 而如果没有被接受到，将有jvm显示异常信息，直接终止*/
    }
}

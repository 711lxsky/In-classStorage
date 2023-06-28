package OMWork4.task1;

/* 异常测试类A*/
public class ExceptionTestA {
    public static void main(String[] args) {

        int [] nums = new int[4];
        try{
            nums[-1] = 0;
        }
        catch (ArrayIndexOutOfBoundsException exception){
            System.out.println("the index of array out!");
        }
        finally {
            System.out.println("this is the finally");
        }
        System.out.println("another sentence.");

        /* 编译运行可发现，当对数组下标进行越界访问时，try块 抛出了越界异常
        * 然后catch块 抓取到了异常
        * 最后进入finally块
        * 同时，程序因为异常处理，没有中断*/
    }
}

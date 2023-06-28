package OMWork4.task2;

/* 自定义异常测试类*/
public class InstanceExceptionTest {
    public static void main(String[] args) {
        /* 直接main中测试，查看异常处理效果*/
        try {
            Apple apple1 =  Apple.getInstance("Fuji",500);
            Apple apple2 = Apple.getInstance("LuoChuan",-200);
        }
        catch (Exception e){
            System.out.println("wrong");
        }

    }
}

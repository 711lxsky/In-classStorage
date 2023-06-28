package OMWork4.task2;

/* 自定义异常，抛出参数异常语句*/
public class InstanceException extends Exception{

    public InstanceException(String message) {
        /* 继承基类的构造函数*/
        super(message);
        System.out.println("Error,the parameter is invalid.");
        System.out.println(this.getMessage());
    }
}

package OMWork4.task1;

/* 异常测试类C */
public class ExceptionTestC {
    /* 加入一个类属性status,
       方便方法构建，进行异常测试*/
    int status;

    /* 构造函数*/
    public ExceptionTestC(int status) {
        this.status = status;
    }

    /* 测试方法，因为在main中无法返回值*/
    public int getExceptCode(){
        try {
             //return this.status - 1 ;
           int rep = 2/0;
        }
        catch (ArithmeticException exception){
            System.out.println("get in catch");
            return this.status;
        }
        finally {
            return this.status + 1;
        }
        //return 12;
    }

    public static void main(String[] args) {
        ExceptionTestC exceptionC = new ExceptionTestC(0);
        System.out.println(exceptionC.getExceptCode());
        /* 先实例化对象
        * 调用方法后可以发现，只要在finally改变了返回值，最后总是返回这个值
        * 倘若没有在finally块改变返回值，会返回上一级，即catch块中执行的返回值(前提是正常catch到了这个Exception)
        * 如果finally块和catch块都没有return语句，则返回try中的return*/
    }
}

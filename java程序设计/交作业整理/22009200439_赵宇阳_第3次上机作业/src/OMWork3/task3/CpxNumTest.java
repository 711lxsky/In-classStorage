package OMWork3.task3;

import java.util.Scanner;

/* 复数测试类*/
public class CpxNumTest {
    public static void main(String[] args) {
        /* 设计交互，读取实部、虚部，实例化复数对象*/
        Scanner myGet = new Scanner(System.in);
        System.out.println("now, please enter the real part and the virtual part of one complex number,");
        double CpxNum1Real = myGet.nextDouble();
        double CpxNum1Vir = myGet.nextDouble();
        ComplexNumber CpxNum1 = new ComplexNumber(CpxNum1Real,CpxNum1Vir);
        System.out.println("then, enter a real number");
        double realNum = myGet.nextDouble();
        System.out.println("So, I 'll get some operations for them:");
        /* 进行计算并打印结果*/
        System.out.println("the add result: "+ComplexNumber.getStrCpxNum(CpxNum1.addRealNum(realNum)));
        System.out.println("and the subtract result: "+ComplexNumber.getStrCpxNum(CpxNum1.subRealNum(realNum)));
        System.out.println("the multiply result: "+ComplexNumber.getStrCpxNum(CpxNum1.mulRealNum(realNum)));
        System.out.println("last, the divide result is: "+ComplexNumber.getStrCpxNum(CpxNum1.divRealNum(realNum)));
        System.out.println();

        /* 同理，实例化第二个复数对象*/
        System.out.println("Now, enter another one complex number:");
        double CpxNum2Real = myGet.nextDouble();
        double CpxNum2Vir = myGet.nextDouble();
        ComplexNumber CpxNum2 = new ComplexNumber(CpxNum2Real,CpxNum2Vir);
        /* 计算，打印*/
        System.out.println("the add : "+ComplexNumber.getStrCpxNum(CpxNum1.addCpxNum(CpxNum2)));
        System.out.println("the subtract: "+ComplexNumber.getStrCpxNum(CpxNum1.subCpxNum(CpxNum2)));
        System.out.println("the multiply: "+ComplexNumber.getStrCpxNum(CpxNum1.mulCpxNum(CpxNum2)));
        System.out.println("the divide: "+ComplexNumber.getStrCpxNum(CpxNum1.divCpxNum(CpxNum2)));

        System.out.println("that 's all.");

    }
}

package OMWork3.task3;

/* 复数实现类*/
public class ComplexNumber {
    /* 成员变量
    * 实部、虚部
    * 这里使用double作为通用类型，且设为私有，提高安全性*/
    private final double realPart;
    private final double virtualPart;

    /* 全参构造*/
    public ComplexNumber(double realPart, double virtualPart) {
        this.realPart = realPart;
        this.virtualPart = virtualPart;
    }

    /* 私有变量抓取*/
    public double getRealPart() {
        return realPart;
    }

    /* 同理，获取私有属性*/
    public double getVirtualPart() {
        return virtualPart;
    }

    /* 计算复数与实数相加方法*/
    public ComplexNumber addRealNum(double realNum){
        return new ComplexNumber(this.realPart+realNum,this.virtualPart);
    }

    /* 复数与复数相加*/
    public ComplexNumber addCpxNum(ComplexNumber CpxNum){
        return new ComplexNumber(this.realPart+CpxNum.getRealPart(),this.virtualPart+CpxNum.getVirtualPart());
    }

    /* 复数与实数相减*/
    public ComplexNumber subRealNum(double realNum){
        return new ComplexNumber(this.realPart-realNum,this.virtualPart);
    }

    /* 复数与复数相减*/
    public ComplexNumber subCpxNum(ComplexNumber CpxNum){
        return new ComplexNumber(this.realPart- CpxNum.getRealPart(),this.virtualPart-CpxNum.getVirtualPart());
    }

    /* 复数与实数乘法*/
    public ComplexNumber mulRealNum(double realNum){
        return new ComplexNumber(this.realPart*realNum,this.virtualPart*realNum);
    }

    /* 复数与复数乘法*/
    public ComplexNumber mulCpxNum(ComplexNumber CpxNum){
        double a = this.realPart*CpxNum.getRealPart() - this.virtualPart*CpxNum.getVirtualPart();
        double b = this.virtualPart*CpxNum.getRealPart() + this.realPart*CpxNum.getVirtualPart();
        return new ComplexNumber(a,b);
    }

    /* 复数与实数相除*/
    public ComplexNumber divRealNum(double realNum){
        double denominator = realNum * realNum;
        double numerator1 = this.realPart*realNum ;
        double numerator2 = this.virtualPart*realNum;
        return new ComplexNumber(numerator1/denominator,numerator2/denominator);
    }

    /* 复数与复数相除*/
    public ComplexNumber divCpxNum(ComplexNumber CpxNum){
        double denominator = CpxNum.getRealPart()*CpxNum.getRealPart()+CpxNum.getVirtualPart()*CpxNum.getVirtualPart();
        double numerator1 = this.realPart*CpxNum.getRealPart() + this.virtualPart*CpxNum.getVirtualPart();
        double numerator2 = this.virtualPart*CpxNum.getRealPart() - this.realPart*CpxNum.getVirtualPart();
        return new ComplexNumber(numerator1/denominator,numerator2/denominator);
    }

    /* 以上方法都是返回一个新的复数*/


    /* 返回复数的字符串形式*/
    public static String getStrCpxNum(ComplexNumber CpxNum){
        return CpxNum.getRealPart()+" + "+CpxNum.getVirtualPart()+"i";
    }
}

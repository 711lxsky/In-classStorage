package OMWork2.task3;

/* 数据操作类*/
public class DateOperator {
    /* 年，月，日*/
    int year;
    int month;
    int day;

    /* year构造函数*/
    public DateOperator(int year) {
        this.year = year;
    }

    /* 全参构造*/
    public DateOperator(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    /* 根据日期计算星期数*/
    public int getWeekNum(){
        /* 借助吉姆拉尔森公式*/
        int year;
        int month;
        int day;
        if(this.month == 1 || this.month == 2){
            month = this.month + 12;
            year = this.year - 1;
        }
        else {
            month = this.month;
            year = this.year;
        }
        day = this.day;
        return (day+2*month+3*(month+1)/5+year+year/4-year/100+year/400+1)%7;
    }

    /* 打印日历基本信息*/
    public void printBasicInfo(){
        System.out.print("\n\n "+this.year+"年"+this.month+"月\n");
        System.out.print("日\t一\t二\t三\t四\t五\t六\n");
    }

    /* 给定年份，判断是否为闰年*/
    public boolean judLeapYear(){
        return (this.year / 4 == 0 && this.year / 100 != 0) || this.year / 400 == 0;
    }

    /* 根据月份，返回该月天数*/
    public int getDayNum(){
        switch (this.month){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            case 2:
                /* 闰年2月29天*/
                if(this.judLeapYear()){
                    return 29;
                }
                else {
                    return 28;
                }
            default:
                return 0;
        }
    }

    /* 打印日历*/
    public void printCalender(){
        /* 循环打印月份日历*/
        for(int i = 0 ; i < 12 ; i ++){
            this.month = i + 1;
            this.day = 1 ;
            this.printBasicInfo();
            while (this.day <= this.getDayNum()){
                /* 抓取每月1号的星期数，以此为基准打印其余天数*/
                int weekNum = this.getWeekNum();
                if(this.day == 1){
                    for(int j = 0 ; j < weekNum ; j ++){
                        System.out.print("\t");
                    }
                    System.out.print(this.day+"\t");
                }
                else {
                    System.out.print(this.day+"\t");
                }
                if(weekNum == 6){
                    System.out.print("\n");
                }
                this.day++;
            }
        }
    }
}

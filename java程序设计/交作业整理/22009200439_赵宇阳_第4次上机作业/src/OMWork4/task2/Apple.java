package OMWork4.task2;

/* 功能苹果类类*/
public class Apple {
    /* 类属性kindName,weight设为私有*/
    private final String kindName;
    private final int weight;

    /* 私有构造方法*/
    private Apple(String kindName, int weight) {
        this.kindName = kindName;
        this.weight = weight;
    }

    /* getInstance方法，参数超过一定范围抛出异常*/
    public static Apple getInstance(String kindName, int weight) throws InstanceException{
        if(weight > 3000 || weight < 0){
            if (weight > 3000){
                throw new InstanceException(kindName+" apple too big.");
            }
            else {
                throw new InstanceException(kindName+" apple too small.");
            }
        }
        else {
            /* 符合规范则返回类对象*/
            return new Apple(kindName,weight);
        }
    }
}

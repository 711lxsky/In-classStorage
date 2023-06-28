package OMWork3.task2;

// 宠物饲养程序

public class PetRaise {
    public static void main(String[] args) {

        // 随机购买了10种食物，食物偏好索引为1,2

        int food[] = new int[10];

        for (int i = 0;i < 10;i ++)

            food[i] = (int)(Math.random()*2) + 1;

        // 补充程序：随机领养了两只宠物

        // 第一个宠物的名字：Tom；食物偏好1；饭量：3

        // 第二个宠物的名字：Pluto；食物偏好2；饭量：6
        Cat cat = new Cat("Tom",3,1);
        Dog dog= new Dog("Pluto",6,2);

        // 补充程序：给领养的两个宠物喂食，直到宠物吃饱或无合适食物
        for(int eatFood : food ){
            if (cat.isHungry()){
                cat.eat(eatFood);
            }
            if  (dog.isHungry()){
                dog.eat(eatFood);
            }
        }

        // 补充程序：如果有某个宠物未吃饱，则输出是哪种食物不足
        for (int i = 0;i < 2;i ++) {
            if(cat.isHungry() && i == cat.getFavoriteIndex() ){
                System.out.println("the food "+i+" for cat is too less.");
            }
            if(dog.isHungry() && i == dog.getFavoriteIndex()){
                System.out.print("the food "+i+" for dog is too less.");
            }
        }

        // 补充程序：使用增强for循环带每个宠物活动（doSomething）
        Pet[] pets = {cat,dog};
        for(Pet pet : pets){
            System.out.println(pet.doSomething());
        }
    }

}
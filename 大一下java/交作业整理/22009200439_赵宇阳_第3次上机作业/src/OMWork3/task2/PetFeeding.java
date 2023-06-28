package OMWork3.task2;

    // 所有宠物的父类

    class Pet {

        // 补充定义宠物属性，至少包括宠物的名字、宠物的食物偏好索引号、宠物的食
        // 量，三个成员变量。成员变量访问权限必须定义为私有权限
        private String Name;
        private int AmountNeedEat;
        private int FavoriteIndex;

        // 初始化默认的宠物实例对象
        public Pet() {
            Name = "MyPet";
            AmountNeedEat = 1;
            FavoriteIndex = 1;
        }

        // 补充定义根据输入参数，初始化宠物的实例对象

        public Pet(String Name, int FavoriteIndex, int AmountNeedEat) {
            this.Name = Name;
            this.FavoriteIndex = FavoriteIndex;
            this.AmountNeedEat = AmountNeedEat;
        }

        // 补充定义返回宠物偏好的食物索引号
        public int getFavoriteIndex() {
            return this.FavoriteIndex;
        }

        // 补充定义返回宠物的名字
        public String toString() {
            return this.Name;
        }

        // 补充定义宠物进食。投喂的食物符合偏好，就吃，且饱食度减一，返回已进食；
        // 投喂不符合偏好，或饱食度为零时，拒食，返回未进食
        public boolean eat(int foodindex) {
            if (this.AmountNeedEat == 0) {
                return false;
            }
            else {
                if (foodindex == this.FavoriteIndex) {
                    this.AmountNeedEat -= 1;
                    return true;
                }
                else {
                    return false;
                }
            }
        }

        // 补充定义宠物饥饿判断。饱食度为零返回不饿，否则返回饿
        public boolean isHungry(){
            return this.AmountNeedEat != 0;
        }

        // 宠物根据自己的状态可以干点什么了。
        public String doSomething() { return "doSomething";}
    }

// 宠物狗类

    class Dog extends Pet {
        // 补充定义需要的成员变量。成员变量的访问权限必须定义为私有权限
        private String Name;
        private int AmountNeedEat;
        private int FavoriteIndex;
        // 根据输入参数，初始化狗的实例对象

        public Dog(String Name, int AmountNeedEat, int FavoriteIndex) {
            this.Name = Name;
            this.AmountNeedEat = AmountNeedEat;
            this.FavoriteIndex = FavoriteIndex;
        }

        // 补充定义宠物狗的干事方法。如果没吃饱，返回still want to eat more food.

        // 如果吃饱了，返回Let’s go outside for a wallow.

        public String doSomething() {
            if(this.isHungry()){
                return this.Name+" still want to eat more food.";
            }
            else {
                return "Let's go outside for a wallow.";
            }
        }
    }

// 宠物猫类

    class Cat extends Pet {
        // 补充定义需要的成员变量。成员变量的访问权限必须定义为私有权限
        private String Name;
        private int AmountNeedEat;
        private int FavoriteIndex;

        // 补充定义根据输入参数，初始化猫的实例对象

        public Cat(String Name, int AmountNeedEat, int FavoriteIndex) {
            this.Name = Name;
            this.AmountNeedEat = AmountNeedEat;
            this.FavoriteIndex = FavoriteIndex;
        }

        // 补充定义宠物猫的干事方法。如果没吃饱，返回still want to eat more food.

        // 如果吃饱了，返回Let’s go to bed for a sleep.

        public String doSomething() {

            if(this.isHungry()){
                return this.Name+" still want to eat more food.";
            }
            else {
                return "Let's go to bed for a sleep.";
            }
        }
    }


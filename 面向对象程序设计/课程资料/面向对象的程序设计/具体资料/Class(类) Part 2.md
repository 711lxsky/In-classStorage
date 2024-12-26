```C++
//紧接part1的代码继续
class Date{
	/*...*/
	
	//如果创建对象时不添加任何参数，则会发生下面的情况
	Date(); //默认的构造函数，如果什么构造函数都没有则会自动生成
	//如果设计了其他的构造函数但是没有定义Date();则会发生编译错误
	
	 
};

int main(){
	Date* p = new Date;        //要用new来新建，因为它包含了malloc和construct
	delete p;     //要用delete来释放，因为包含了free和destruct
	
	Date p1;
	Date p2=p1;    //赋初值，没有任何问题
	Date p3;
	
	p3=p1;    //会导致p3指向p2，但是原来的p3的位置没有清除，也就是 内存泄漏
	
	Date d[2]={Date(11,11,2024),Date(26,11,2003)}; //数组初始化
	//如果没有默认构造函数必须这样写，不能缺省
	
	Date* ds = new Date[20]; //生成一组对象，这样在delete的时候就有特殊的写法
	delete [] ds; //正确释放的写法
}
```
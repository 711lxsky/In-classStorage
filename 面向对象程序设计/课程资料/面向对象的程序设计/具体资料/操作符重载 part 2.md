大数据传参会存在很大的**复制开销**，所以需要多使用**引用**来减少开销，函数的参数必须是引用，函数的**返回值**则可以是**引用/地址**，同时返回的被引用对象必须是**返回到调用点时仍然存活**的。
* 非成员函数、类的静态成员函数中，可以返回：
	* 某个**引用类型**（或指针类型）的参数；
	* 某个**全局对象**的引用（或地址）；
	* 类的**静态数据成员**的引用（或地址）；
	* 函数体内某个**局部静态对象**的引用（或地址）；
* 非静态成员函数，还可以返回对象自身（this，* this）或者数据成员的引用/地址
```C++
//大数据传参举例
class Matrix{
	double m[4][4];
public:
	Matrix();
	Matrix(const Matrix&); //拷贝构造
	friend Matrix& operator+ (const Matrix&, const Matrix&);
};

Matrix& operator+ (const Matrix& arg1, const Matrix& arg2){
	static Matrix sum;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			sum.m[i][j]=arg1.m[i][j]+arg2.m[i][j];
	return sum;
}
```

 隐式类型转换有时候会带来很严重的问题，所以我们可以禁止其发生转换
```C++
class String{
	//...
	explicit String(int n);  //利用explicit关键字禁止隐式，必须显式
	String(const char* p);
} 
```


### 写一半我不写了，下面应该不考，有兴趣可以看看
数组重载就是深井冰，**考的概率不大**，但是我也要提一下。要我总结，数组重载是伪重载，如下面的例子
```C++
//先是针对几个类的初始化
const int MAX_TABLE_SIZE=120;  //数组最大容量
struct Mark{
	string name;
	int stdentNO;
	double mark;
};
class MarkTable{
	Mark body[MAX_TABLE_SIZE]; //数组的本体
public:
	Mark& operator[](const int);
	Mark& operator[](const char*);
};

Mark& MarkTable::operator[](const int i){ //重载
	return body[i];
}

//下面是实际运行代码，来看看数组重载到底是什么
Mark s[MAX_TABLE_SIZE]; //这个是不能重载的写法，一般都是这么用的
s[0].name="Who";
s[0].mark=100;

MarkTable t; //可以进行重载的“数组”，是“类数组”对象，伪数组
//注意，下面的两种写法是不可以的
//t.body[0].name="Who";
//t.body[0].mark=100;

t[0].name="Who"; //上面的重载导致的结果，可以这样写
t["Who"].mark=100;
```

函数调用，**括号重载**

间接调用，**重载->**

自增自减，**重载++,--**

重载String类
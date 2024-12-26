```C++
int main(int argc,char *argv[]){
	//函数体
}
```
这种就是**命令行参数**的基本使用格式，argc储存命令行参数的数目，argv储存的是命令行参数的具体数值（字符串输入）

C++使用输入/输出的方式是和C大有不同的
```C++
#include <iostream> //标准I/O
#include <fstream>  //文件I/O
#include <sstream>  //字符串I/O

using namespace std; //利用namespace，基本上每个程序都要使用，C++的基准namespace

//<< 流提取运算符，从输入流中提取
//>> 流插入运算符，向输出流插入

//对象cin是键盘输入，对象cout是命令行输出，所以如果要输入输出数据就可以这样写
int id;
cin>>id;
cout<<id<<endl; //endl是换行符

//ifstream是文件输入流，ofstream是文件输出流，fstream是文件输入输出流
ofstream fout("test.txt");
fout<<id<<endl;
//fout.close()会自动调用
```

---
STL是指standard template library，存在**容器**，**迭代器**和**算法**

### 迭代器
```C++
//两种主要的定义方法
vector<int> v1;

vector<int>::iterator it; //定义迭代器it

it=v1.begin(); //it从v1的头开始
while(it!=v1.end()){ //it不到v1的尾的话一直循环
	cout<< *it <<endl; //需要*来输出it的值而非地址 
	++it; //取迭代器的下一个值
}

//还可以利用下面的代码做到完全一致的效果
for(auto it2=v1.begin();it2!=v1.end();it2++) //auto可以自动去适应后续的结构类型
{
	cout<< *it2 <<endl;
}
```

### 算法
```C++
//排序类算法
sort();
stable_sort();
is_sorted();

//查找类算法
find();
find_if();
find_if_not();

//等等等等，没啥用，过！
```

### 容器
向量vector，变长数组
```C++
#include <vector>
using namespace std;

vector<int> v1; //创建整形向量，初始为空
vector<int> v2(10); //创建初始化为10个0的向量v2

v1.size(); //元素个数
v2.capacity(); //容量，空间大小，可以自动增加

v1.push_back(1); //在v1末尾添加1
v2.pop_back(); //删除末尾的数据

//结合迭代器
for(auto it=v1.begin();it!=v1.end();it++)
{
	v1.insert(it); //插入 
	v1.erase(it); //删除
}
```

有序集合set，快速查找（元素不重复，但是multiset中的元素是可以重复的）
```C++
#include <set>
using namespace std;

set<int> myset;
set<int>::iterator it;

myset.insert(10); //集合中插入
myset.insert(20);

myset.erase(10); //集合中删除

//接下来的几个都和迭代器有关
it=myset.find(20); //返回迭代器
it=myset.upper_bound(5); //返回大于5的第一个元素的迭代器
it=myset.lower_bound(30); //返回小于30的第一个元素的迭代器
```

关联数组map，**键值对映射**
```C++
#include <map>
using namespace std;

map<string,int> m;

m["one"]=1; //可以添加新的内容
//下面两种也可以
m.insert(make_pair("three",3));
m.insert(pair<string,int>("four",4));

for(auto it=m.begin();it!=m.end();it++){
	cout<<"key:"<<it->first<<endl; //输出键
	cout<<"value:"<<it->second<<endl; //输出值
}

//关于删除和查找我们可以用下面的程序来辅助理解
string key;
while(cin>>key){
	map<string,int>::iterator it=m.find(key); //查找
	if(it==m.end()){
		cout<<"No such a key!"<<endl;
	}else{
		cout<<key<<"is"<<it->second<<endl;
		cout<<"Erased"<<m.erase(key)<<endl; //删除
	}
}
```

字符串string
```C++
#include <string>
using namespace std;

//初始化
string s1; //初始化空串
string s2(s1); //s2初始化为s1的副本
string s2=s1; //效果和上一句一致
string s3("value"); //s3初始化为”value“
string s4="value"; //同上
string s5(3,'A'); //将s5初始化为连续3个字符A组成的字符串

//基本操作
string s1;
string s2("a example");

cin>>s1;
getline(cin,s2); //读取一行的字符串

if(s1==s2){ //可以直接通过==,<=,>=,!=来逻辑判断两个字符串
	cout<<"Good job!"<<endl<<endl;
}

for(int i=0;i<s1.size();i++) //可以通过size()或者length()来获取字符串的长度
	cout<<s1[i]<<' '; //可以通过下标来访问字符串中的字符
```

栈stack
```C++
#include <stack>
using namespace std;

stack<int> mystack;
mystack.push(1); //压栈
for(int i=0;i<10;i++) mystack.push(i*10);

while(!mystack.empty()) //若栈不为空
{
	cout<<mystack.top()<<endl; //输出栈顶
	mystack.pop(); //弹栈
}
```

队列queue
```C++
#include <queue>
using namespace std;

queue<int> myqueue;
myqueue.push(1);
for(int i=0;i<10;i++) myqueue.push(i*10);

while(!myqueue.empty())
{
	cout<<myqueue.front()<<endl; //输出队列头元素
	myqueue.pop();
}
```
namespace是C++模块化的表现之一，其可以将接口声明和实现细节进行分离，即可以在.hpp(.h)文件中定义，在.cpp(.h)中实现，**实现格式**如下
```C++
namespace_name::member_name
```

调用namespace声明需要使用using关键字，来为作用域引入一个**局部同义词**
```C++
using Lexer::curr_tok;
//如果很多函数都需要使用这个参数/函数，则可以将using声明放到全局，而非局部
```

而调用namespace作为代码则不同，会引入namespace中的全部内容
```C++
using namespace anotherNS;
//将指定模块anotherNS中的所有name都引入当前的作用域中
```

using作为**声明**或**代码**是有区别的
相同点：
* 可出现在头文件、实体文件
* 为其出现的作用域引入同义词（其它namespace的成员），从而在该作用域内，无须加限定就可以使用。
不同点：
* 语法不同
* 一个using声明仅能引入一个同义词，但是using指令可以引入多个同义词

C/C++语言为了告诉程序员出错的信息，一般会给出**发现错误的地点**和**发现错误的类型**，从这点出发去找如何处理错误和在何处处理错误。而作为程序员，也可以手动设置**错误报错**的异常反馈，这边只做提及，不加赘述。

语法为try-catch，try语句块中的内容，如果错误则会跳转到catch进行**异常报错**，或者直接利用throw进行**直接报错**，相当于**jmp catch**的效果，例如下面的示例代码。
```C++
struct Range_error{
	int i;
	Range_error(int ii){ i=ii; }
}

char to_char(int i)
{
	//出现异常，报告之
	//强制调用者检测，否则立即终止运行
	if(i<CHAR_MIN || i>CHAR_MAX)
		throw Range_error(i);
	return i;
}

void g(int i){
	try{
		//在此期间若出现异常，
		//则从to_char跳到下面的catch处理
		char c = to_char(i);
		//...
	}
	//若try{}中throw了Range_error时，激活改处理
	catch(Range_error x){
		cerr<<"oops"<<x.i<<"\n";
	}
}
```
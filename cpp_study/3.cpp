#include <stdlib.h>
#include <iostream>
//结构体的大小-->最大的属性的大小的整数倍
//类的大小

using namespace std;
class A{
public:
	int a;
	int c;
	int d;

	void(*myprintf)() = myprintf;
};
void myprintf(){
	cout << "dayin" << endl;
}
class B{
public:
	int a;
	int c;
	int d;
};
//this 
//函数是共享的,必须要有能够标识当前对象是谁的方法
class Teacher {
private:
	char* name;
	int age;
public:
	Teacher(char* name, int age){
		this->name = name;
		this->age = age;
		cout << "有参构造函数" << endl;
	}
	~Teacher(){
		cout << "析构函数" << endl;
	}
	void setName(char* name){
		this->name = name;
	}
	char* getName(){
		return this->name;
	}
	void myprintf(){
		printf("%#x\n",this);
		cout << this->age<<this->name << endl;
	}
	//常函数,修饰的是this,既不能改变指针指向的内容,也不能改变指针的值
	void myprintf2() const{
		printf("%#x\n", this);
		//改变属性的值
		//this->name ="qweqssswewq"
		//改变this指针的值
		//this =(Teacher*)0x00009;

		cout << this->age << this->name << endl;
	}
};
void mainConst(){
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;

	//C/C++ 内存分区:栈,堆,全局 (静态,全局),常量区(字符串 char*),程序代码区
	//普通属性与结构体相同的内存布局
	Teacher t1("weweq",22);
	const Teacher t2("wewwweq", 21);

	//常函数,当前对象不能被修改,防止数据成员被非法访问
	printf("%#x\n", t1);
	t1.myprintf2();

	printf("%#x\n", t2);
	//常量对象只能调用常量函数,不能调用非常量函数
	t2.myprintf2();
	//t2.myprintf();
	system("pause");
}


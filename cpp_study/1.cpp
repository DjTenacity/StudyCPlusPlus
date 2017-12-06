#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <stdarg.h>

//标准命名空间(包含很多标准的定义)
// std:: ----> standard
using namespace std;
//命名空间类似于Java中的包

//自定义命名空间,里面可以有结构体
namespace NSP_A{
	int a = 19;
	//命名空间嵌套
	namespace NSP_C{
		int C = 88;
	}

	struct Teacheer{
		char name[22];
		int age;
	};
	struct Student{
		char name[22];
		int age;
	};
}
namespace NSP_B{
	int a = 29;

	struct Student{
		char name[22];
		int age;
	};
}
void main1(){
	//<<  运算符重载,符号本身没有任何意义
	//std::cout << "this is c plis plus" << std::endl;
	cout << "this is c plis plus" << endl;
	//使用命名空间 --->解决重名问题 既是Java的包的作用:归类
	//  :: 访问修饰符
	cout << NSP_A::a << endl;
	cout << NSP_B::a << endl;
	cout << NSP_A::NSP_C::C << endl;

	//使用命名空间中的结构体
	//using namespace NSP_A;
	//Teacheer t;
	//t.age = 10;
	//NSP_A::Teacheer t;
	//t.age = 10;

	using NSP_A::Student;
	Student ss;
	system("pause");
}
//后面不能有分号,是有的时候会无差别带入
#define PI 3.1415
//const double  PI =3.1415;
class MyCircle{
	//属性(公用权限访问修饰符)
private:
	double r;
	double r2;

public:
	double length;
	void setR(double r){
		this->r = r;
	}
	//获取面积
	double getS(){
		return  PI * r * r ;
	}

public:
	double length2;
};


//结构体 
struct MyTeacher2{
public:
	char name[20];
	int age;
public:
	void say(){
		cout << this->age << "岁" << endl;
	}
};
void main2(){
	MyTeacher2 t1;
	t1.age = 10;
	t1.say();
	system("pause");
}

void main3(){
	MyCircle c1;
	c1.setR(4);
	cout << "面积不是" << c1.getS() << endl;


	/*
	//布尔类型
	//bool isSingle = true;
	bool isSingle = 17;
	//false -17

	if (isSingle){
		cout << "单身" << endl;
		cout << sizeof(bool) << endl;
	}
	else{
		cout << "有对象" << endl;
	}
	int a = 10, b = 20;
	//int c=((a > b) ? a : b)
	((a > b) ? a : b) = 30;
	cout << b << endl;
	*/
	//=========================引用========================

	//变量名-门牌号(内存空间0x00001的别名，可不可以有多个名字？)
	int a = 10;
	//b就这个内存空间另外一个别名\
			//& C++中的引用
	int &b = a;
	cout << b << endl;

	system("pause");
}

//指针值交换
void swap_1(int *a, int *b){
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

//引用值交换
void swap_2(int &a, int &b){
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void main4(){
	int x = 10;
	int y = 20;

	printf("%d,%d\n", x, y);
	//swap_1(&x, &y);
	//a成了x的别名
	swap_2(x, y);
	printf("%d,%d\n", x, y);

	system("pause");
}

//引用的主要:作为函数的参数或返回值
struct Teacher{
	char* name;
	char name2[22];
	int age;
};
//引用
void myprint(Teacher &t){
	cout << t.name << "," << t.age << endl;
	t.age = 21;
}
//指针
void myprint2(Teacher *t){
	cout << t->name << "," << t->age << endl;
	t->age = 21;
	(*t).name = "qwqeqwe";
}

void main5(){
	Teacher t;
	t.name = "loveDJ";
	t.age = 20;
	myprint(t);
	myprint2(&t);
	system("pause");
}

void getTeacher(Teacher * *p){
	//开辟空间
	Teacher *tmp = (Teacher*)malloc(sizeof(Teacher));
	tmp->age = 21;
	strcpy(tmp->name2, "wwwww");
	*p = tmp;

	cout << tmp->name2 << "," << tmp->age << endl;
}
//指针的引用代替二级指针
// Teacher* &p=(Teacher * *p)
void getTeacher(Teacher* &p){
	//开辟空间
	p = (Teacher*)malloc(sizeof(Teacher));
	p->age = 21;
}
//==============指针保存的是地址,引用是变量的别名=============
void main6(){
	Teacher *t = NULL;
	getTeacher(&t);

	//=================指针常量与常量指针=============

	//指针常量,指针的常量,不改变地址的指针,但是可以修改它指向的内容
	int a = 2, b = 3;
	int *const p1 = &a;
	//p1 = &b;--->不行
	*p1 = 4;

	//常量指针,指向常量的指针,内容不能修改
	const int *p2 = &b;
	p2 = &a;
	//*p2 =9;  //不行
}

//单纯给变量取别名没有任何意义,作为函数参数传递,能保证参数传递过程中不产生副本
//引用可以直接操作变量,指针要通过取值(*p) ,间接操作变量,指针的可读性差

void main7(){
	//const int a;
	//引用必须要有值,不能为空
	//int &a=NULL;

	//常引用   类似于Java中的final
	int a = 10, b = 9;
	const int  &c = a;

	// c = b; 
	//字面量
	const int &d = 79;

	//引用是变量的别名,操作引用 相当于 操作变量,指针保存的是变量的地址
	Teacher t;
	Teacher &t1 = t;
	Teacher *p = &t;

	cout << "32-->变量长度" << sizeof(t) << endl;
	cout << "32-->引用长度" << sizeof(t1) << endl;
	cout << "4->指针变量长度,也是指针保存的变量的地址的长度" << sizeof(p) << endl;
	cout << "32-->指针指向的变量的长度" << sizeof(*p) << endl;
	Teacher *s = NULL;
	getTeacher(&s);
	//引用不需要非空判断(引用不能为空,没法传进去),而指针需要
	//引用-->高效,方便
	system("pause");
}

void myprintf(const int &a){
	cout << a << "const int &" << endl;
}
void myprintf(int *a){
	cout << *a << "*" << endl;
}
void myprintf2(int &a){
	cout << a << "&" << endl;
}
//函数默认参数
void myprint(int x = 10){
	cout << x << endl;
}
void myprint2(int x ,int y= 10,int z=30){
	cout << x << endl;
}
//重载
void myprint2(int x,bool z  ){
	cout << x << endl;
}
void main8(){
	myprint();
	myprint(30);
	myprint2(10);
}
//可变参数  -->Java:Task,Acytask
void func(int i,...){
	//可变参数指针
	va_list args_p;
	//开始读取可变参数,i是最后一个固定参数
	va_start(args_p,i);

	/*
	int a=va_arg(args_p,int);
	char b = va_arg(args_p, char);
	char c = va_arg(args_p, char);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;*/

	//必须是相同类型的
	int value;
	while (1){
		value = va_arg(args_p, int);
		if (value <= 0){
			break;
		}
		cout << value << endl;
	}

	//结束
	va_end(args_p);
}

//C++的类的普遍写法
#include "MyTeacher.h"

void main9(){
	MyTeacher t1;
	t1.name = "咯大";
	t1.age = 22;
	 cout << t1.getName() << endl;

	func(30 ,50, 30, 40);
	//func(30,'a','a',30,40);
	main7();
	main8();
}

//引用是变量的别名,主要用于函数的参数或者返回值
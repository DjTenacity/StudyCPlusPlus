#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>

using namespace std;
/*C与C++的关系

1.C++可以与C代码进行混编
2.C++面向对象的编程语言 , C面向过程的编程
3.C++对C的一个增强


malloc() free() 
new delete() 

//C/C++ 内存分区:栈,堆,全局 (静态,全局),常量区(字符串 char*),程序代码区
//普通属性与结构体相同的内存布局

//jvm Stack (基本数据类型,对象引用),Native Stack(本地方法栈) ,
//方法区

 */

/*
//友元函数
class A{
private:
	int i;
public:
	A(int i){
		this->i = i;
	}
	void myprint(){
		cout << i << endl;
	}
	//友元函数-->函数的声明而已
	friend void modify_i(A* p,int  a);
};

//友元函数的实现,在友元函数中可以访问私有的属性
void modify_i(A* p, int  a){
	p->i = a;
}

void main(){
	A* a = new A(10);
	a->myprint();

	modify_i(a,20);
	a->myprint();

	system("pause");
}
*/

//友元类
class A{
	//友元类
	//B这个可以友元类访问A 的任何成员
	friend class B;
private:
	int i;
public:
	A(int i){
		this->i = i;
	}
	void myprint(){
		cout << i << endl;
	}
};

class B{
public :
	void accessAny(){
		a.i = 30;
	}

private :A a;
};

//运算符重载
/*
class Point{
private:
	
public :
	int x;
	int y;
	Point(int x=0,int y=0){
		this->x = x;
		this -> y = y;
	}
	//成员函数,运算符重载
	Point operator*(  Point &p2){
		Point tmp(this->x * p2.x, this->y * p2.y);
		return tmp;
	}
	void myprint(){
		cout << x << "vvv" << y << endl;
	}
};
//重载加号
Point operator+(Point &p1, Point &p2){
	Point tmp(p1.x+p2.x,p1.y+p2.y);
	return tmp;
}
//重载 - 号
Point operator-(Point &p1, Point &p2){
	Point tmp(p1.x - p2.x, p1.y - p2.y);
	return tmp;
}

void main(){
	Point p1(10,19);
	Point p2(12, 19);
	//运算符的重载,本质还是函数的调用
	//p1.operator*(p2);
	Point p3 = p1 * p2;
	Point p4 = p1 + p2;
	p3.myprint();
}
*/


//当属性私有时,通过友元函数完成运算符重载
class Point{
	friend Point operator+(Point &p1, Point &p2);
private:
	int x;
	int y;
public:
	
	Point(int x = 0, int y = 0){
		this->x = x;
		this->y = y;
	}
	//成员函数,运算符重载
	Point operator*(Point &p2){
		Point tmp(this->x * p2.x, this->y * p2.y);
		return tmp;
	}
	void myprint(){
		cout << x << "vvv" << y << endl;
	}
};

//重载加号
Point operator+(Point &p1, Point &p2){
	Point tmp(p1.x + p2.x, p1.y + p2.y);
	return tmp;
}

/*  Java

Class cls = Class.forName("com.lovedj.Teacher");
cls.setAccessable(true);

String a1="aaa";
String a2 ="qweqwe";
String a3=a1+a2;

*/
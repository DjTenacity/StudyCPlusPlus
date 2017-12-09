#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>	

using namespace std;

//继承  代码的重用行
/*
class Hunman{
public :
	int size;
	Hunman(char* name, int age){
		this->name = name;
		this->age = age;
	}
	void say(){
		cout << "wqeqw" << endl;
	}
protected://子类可以
	char* name2;
	
private://只能在本类
	int age;
	char* name;
};

class Man :public Hunman{
public :
	//给父类构造函数穿参,同时给属性对象穿参
	Man(char *brother, char *name, int age, char *h_name, int h_age) :Hunman(name, age), h(h_name, h_age){
		this->brother = brother;
	}
	//泡妞
	void chasing(){
		cout << "sd泡妞asdsa" << endl;
	}
	void say(){ 
		cout << "真的假的哪有" << endl; 
	}
private:
	char* brother;
	Hunman h;
};
void work(Hunman &h){
	h.say();
}

void main(){
	//子类的构造方法调用之前会先调用父类的构造方法
	//如果父类没有无参的构造方法,那么就必须向父类的构造方法穿参

	Man m1("sdsds", "wewqeewq", 22, "w是是是wq", 11);
	//是覆盖并非多态
	m1.say();
	//调用父类的重名函数
	m1.Hunman::say();
	m1.Hunman::size = 11;

	//父类类型的引用或指针
	Hunman* h_p = &m1;
	Hunman &h1 = m1; 

	h_p->say();
	h1.say();

	//子类对象初始化父类类型的对象
	Hunman  h2 = m1;

	
	system("pause");
}
*/
//先有父类对象,再有子类对象(先调用父类构造函数,后调用子类对象)
//先死子类对象,再死父类对象(析构函数)

//重载是在一个类里面,子类父类只有重写

 
//多继承
//人
class Person{

};
//公民
class Citizen{

};
//学生,多继承向父类穿参会特别麻烦
class Student : public Person, public Citizen{

};

//继承的二义性,譬如   B1,B2都继承了A,C同时继承了B1,B2
//虚继承，不同路径继承来的同名成员只有一份拷贝，解决不明确的问题
/*
class A{
public:
	char* name;
};

class A1 : virtual public A{

};

class A2 : virtual public A{

};
//虚继承
class B : public A1, public A2{

};

void main(){
	B b;
	b.name = "jason";
	//指定父类  显示调用
	//b.A1::name = "advance";
	//b.A2::name = "不烦不烦";
	system("pause");
}
*/


//虚函数
//多态(程序的扩展性)
//动态多态：程序运行过程中，觉得哪一个函数被调用（重写）
//静态多态：重载

//发生动态的条件：
//1.继承
//2.父类的引用或者指针指向子类的对象
//3.函数的重写

#include "Plane.h"
#include "Jet.h"
//业务函数
void bizPlay(Plane& p){
	p.fly();
	p.land();
}
void mainccc(){
	Plane  p1;
	Jet p2;
	bizPlay(p1);
	bizPlay(p2);

	system("pause");
}

//纯虚函数(抽象类)
//1.当一个类具有一个纯虚函数，这个类就是抽象类
//2.抽象类不能实例化对象
//3.子类继承抽象类，必须要实现纯虚函数，如果没有，子类也是抽象类
//抽象类的作用：为了继承约束，根本不知道未来的实现
//形状
/* 
class Shape{
public:
	//纯虚函数
	virtual void sayArea() = 0;

	void print(){
		cout << "hi" << endl;
	}
};

//圆
class Circle : public Shape{
public:
	Circle(int r){
		this->r = r;
	}
	void sayArea(){
		cout << "圆的面积：" << (3.14 * r * r) << endl;
	}
private:
	int r;
};

void main(){
	//Shape s;
	Circle c(10);

	system("pause");
}

*/

//接口（只是逻辑上的划分，语法上跟抽象类的写法没有区别）
//可以当做一个接口
/*
class Drawble{
//虚函数与纯虚函数的区别就在  =0 这里
virtual void draw();
};
*/
 
//模板函数（泛型）
/*
void myswap(int& a,int& b){
int tmp = 0;
tmp = a;
a = b;
b = tmp;
}

void myswap(char& a, char& b){
char tmp = 0;
tmp = a;
a = b;
b = tmp;
}
*/

//发现：这两个函数业务逻辑一样，数据类型不一样
template <typename T>
void myswap(T& a, T& b){
	T tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void mainp(){
	//根据实际类型，自动推导
	int a = 10, b = 20;
	myswap<int>(a, b);
	cout << a << "," << b << endl;

	char x = 'v', y = 'w';
	myswap(x, y);
	cout << x << "," << y << endl;

	system("pause");
}

//如果一个源文件,既有函数的声明又有函数的实现,这个源文件的后缀名就会是  .hpp
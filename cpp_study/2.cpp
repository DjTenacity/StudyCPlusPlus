#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>

using namespace std;


//构造函数、析构函数、拷贝构造函数
/*
class Teacher{
private:
	char *name;
	int age;
public:
	//无参构造函数（写了，就会覆盖默认的无参构造函数）
	Teacher(){
		cout << "无参构造函数" << endl;
	}
	//有参构造函数会覆盖默认的构造函数
	Teacher(char *name, int age){
		this->name = name;
		this->age = age;
		cout << "有参构造函数" << endl;
	}
};


void main(){
	//Teacher t1;
	Teacher t2("yuehan", 20);

	//另外一种调用方式
	Teacher t3 = Teacher("jack", 21);

	system("pause");
}
*/

/*
//析构函数
class Teacher{
private:
	char *name;
	int age;
public:
	//无参构造函数赋默认值
	Teacher(){
		this->name = (char*)malloc(100);
		strcpy(name, "jack walson");
		age = 20;
		cout << "无参构造函数" << endl;
	}
	//析构函数
	//当对象要被系统释放时，析构函数被调用
	//作用：善后处理
	~Teacher(){
		cout << "析构" << endl;
		//释放内存
		free(this->name);
	}
};

void func(){
	Teacher t1;
}

void main(){
	func();

	system("pause");
}
*/

//拷贝构造函数
/*
class Teacher{
private:
	char *name;
	int age;
public:
	Teacher(char *name, int age){
		this->name = name;
		this->age = age;
		cout << "有参构造函数" << endl;
	}
	//拷贝构造函数（值拷贝）
	//默认拷贝构造函数，就是值拷贝
	Teacher(const Teacher &obj){
		this->name = obj.name;
		this->age = obj.age;
		cout << "拷贝构造函数" << endl;
	}
	void myprint(){
		cout << name << "," << age << endl;
	}
};

Teacher func1(Teacher t){
	t.myprint();
	return t;
}

void main(){
	Teacher t1("rose", 20);

	//拷贝构造函数被调用的场景
	//1.声明时赋值
	//Teacher t2 = t1;
	//t2.myprint();
	//2.作为参数传入，实参给形参赋值
	func1(t1);
	//3.作为函数返回值返回，给变量初始化赋值
	//Teacher t3 = func1(t1);

	//这里不会被调用
	//Teacher t1 ;
	//Teacher t2;
	//t1 = t2;

	system("pause");
}
*/

//浅拷贝（值拷贝）问题
/*
class Teacher{
private:
char *name;
int age;
public:
Teacher(char *name, int age){
this->name = (char*)malloc(100);
strcpy(this->name,name);
this->age = age;
cout << "有参构造函数" << endl;
}
~Teacher(){
cout << "析构" << endl;
//释放内存
free(this->name);
}
void myprint(){
cout << name << "," << age << endl;
}
};

void func(){
Teacher t1("rose", 20);

Teacher t2 = t1;
t2.myprint();
}

void main(){
func();

system("pause");
}
*/

//深拷贝
/*
class Teacher{
private:
	char *name;
	int age;
public:
	Teacher(char *name, int age){
		int len = strlen(name);
		this->name = (char*)malloc(len + 1);
		strcpy(this->name, name);
		this->age = age;
		cout << "有参构造函数" << endl;
	}
	~Teacher(){
		cout << "析构" << endl;
		//释放内存
		free(this->name);
	}
	//深拷贝
	Teacher(const Teacher &obj){
		//复制name属性
		int len = strlen(obj.name);
		this->name = (char*)malloc(len + 1);
		strcpy(this->name, obj.name);
		this->age = obj.age;
	}
	void myprint(){
		cout << name << "," << age << endl;
	}
};

void func(){
	Teacher t1("rose", 20);

	Teacher t2 = t1;
	t2.myprint();
}

void main(){
	func();

	system("pause");
}
*/
//指针的浅拷贝就是拷贝的地址,会出问题

//构造函数的属性初始化列表
/*
class Teacher{
private:
	char* name;
public :
	Teacher(char* name){
		this->name = name;
		cout <<"有参构造函数" << name << endl;
	}
	~Teacher(){
		cout << "析构函数" << name << endl;
	}
	char* getName(){
		return this->name;
	}

};

class Student{
private:
	int id;
	//属性对象
	//Teacher t = Teacher("miss");
	Teacher t1;
	Teacher t2;
public:
	Student(int id, char *t1_n, char *t2_n) :t1(t1_n), t2(t2_n) {
		this->id = id;
	}
	void myprint(){

		cout << id << "m名字" << t1.getName << "m名字22" << t2.getName << endl;
	}
	~Student(){
	}
};
//teacher 对象先创建,student先析构
void main(){
	Student s1(10,"miss","asdfasdas");
	s1.myprint();
	system("pause");
	}*/


//C++ 通过new(delete)动态内存分配
//C malloc(free)
/*
class Teacher {
private:
	char* name;
public:
	Teacher(char* name){
		   this->name = name;
		   cout << "有参构造函数" << endl;}
	~Teacher(){
		cout << "析构函数" << endl;
	}
	void setName(char* name){
		this->name = name;
	}
	char* getName(){
		return this->name;
	}
};
void func(){
	//C++
	//new 动态分配
	Teacher *t1 = new Teacher("jvava ee");
	cout << t1->getName() << endl;
	//释放
	delete t1;

	//C    --->不会调用构造方法和析构函数
	Teacher *t2 = (Teacher*)malloc(sizeof(Teacher));
	t2->setName("wewqeqw");
	free(t2);
}

void main(){
	func();

	//数组类型,,,,指针函数返回的是指针,,,函数指针保存的是函数的地址
	//    C
	//int *p1 = (int*)malloc(sizeof(int) *10);
	//p1[0] = 99;
	//free(p1);

	//C++
	int *p2 = new int[10];
	p2[0] = 12;
	//释放数组
	delete[] p2;

	system("pause");
	}
	*/

/*
class Teacher {
private:
	char* name;
	//static 静态属性和函数
public:
	//计数器
	static int total;
	Teacher(char* name){
		this->name = name;
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
	//静态方法不能访问非静态的属性
	static void count(){
		total++;
		cout << total << endl;
	}
};
//静态属性初始化赋值
int Teacher::total = 9;

void main(){
	//外部命名空间,内部命名空间,类名
	//B::A::Teacher::count();
	Teacher::count();
	Teacher::total++;

	Teacher t1("wqeqweqwda");
	t1.count();
	}
	*/
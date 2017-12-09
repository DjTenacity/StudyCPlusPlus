#include <iostream>	
using namespace std;

//C++ 类型转换
//static_cast 普遍情况
//const_cast  去常量
//dynamoc_cast  子类类型转为父类类型
//reinterpret_cast  函数指针转型,不具备移植性

//原始类型转换,所有情况都是一种写法,可读性不高.可能有潜在的风险
/*
void* func(int type){
	switch (type) {
	case 1: {
				int i = 0;
				return &i;
	}
	case 2: {
				int i = 'A';
				return &i;
	}
	default:{
				return NULL;
	}
	}
}
void* func2(char* c_p){
	cout << c_p << endl;
}

void main(){
	 
	//int i = 1;
	//自动转换``````````````
	//double x = i;
	//double x = 9.5;
	//int i=x;
	 

	int i = 8;
	double d = 9.5;
	i = static_cast<int>(d);

	//char* c_p = (char*)func(2);
	char* c_p = static_cast<char*> (func(2));

	//C++ 意图明显
	func2(static_cast<char*> (func(2)));
	//C
	func2((char*)func(2));


	cout << i << c_p << endl;
	system("pause");
}*/

/* 
void func(const char c[]){
	//c[1]='a'
	//通过指针间接赋值
	//	其他人并不知道,这次转型是为了 去常量
	//char* c_p = (char*)c;
	//c_p[1] = 'L';
	
	//提高了可读性
	char* c_p = const_cast<char*>(c);
	c_p[1] = 'S';
	cout << c << endl;
}
void main(){

	char c[] = "hello";
	func(c);
	system("pause");
}*/
/*  */
class Person{
public:
	virtual void print(){
		cout << "Person"<< endl;
	} 
};

class Man:public Person{
public:
	void print(){
		cout << "Man" << endl;
	}
	void chasing(){
		cout << "泡妞" << endl;
	}
};

class WoMan :public Person{
public:
	void print(){
		cout << "WoMan" << endl;
	}
	void carebaby(){
		cout << "生孩子" << endl;
	}
};
/*
void func(Person* obj){
	obj->print();

	//调用子类的特有的函数,转为实际类型
	 //传入的是女人,这样的转化并不会报错  ,并不知道转型失败
	//Man *m = (Man*)obj;
	//m->chasing();

	//如果转型失败,就会返回空,报错
	Man* m = dynamic_cast<Man*>(obj);
	if (m!=NULL){
		m->chasing();
	}
}

void main(){ 
	WoMan m;
 	Person *p = &m;
	func(p  );

	WoMan *w_p = &m;

	system("pause");
	} 
	*/
void func1(){
	cout << "func1" << endl;
}

char* func2(){
	cout << "func2" << endl;
	return "abc";
}

typedef void(*f_p)();

void mainCC(){
	//函数指针数组
	f_p f_array[6];
	//赋值
	f_array[0] = func1;

	//C方式
	//f_array[1] = (f_p)(func2);
	//C++方式
	f_array[1] = reinterpret_cast<f_p>(func2);

	f_array[1]();

	system("pause");
}

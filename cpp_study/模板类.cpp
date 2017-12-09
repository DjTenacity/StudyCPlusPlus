#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>	
using namespace std;
//模板类
template<class T>
class A{
public:
	A(T a){
		this->a = a;
	}
protected:
	T a;
};


//普通类继承模板类
class B :public A<int> {
public :
	B(int a,int b):A<int>(a){
		this-> b = b  ;
	}
private :
	int b;
};

//模板类继承模板类
template<class T>
class C:public A<T>{

public:
	C(T c,T a) :A<T>(a){
		
	}
protected:
	T c;
};

void CC(){
	//实例化模板类对象
	A	<int> a(6);
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>	
using namespace std;
//ģ����
template<class T>
class A{
public:
	A(T a){
		this->a = a;
	}
protected:
	T a;
};


//��ͨ��̳�ģ����
class B :public A<int> {
public :
	B(int a,int b):A<int>(a){
		this-> b = b  ;
	}
private :
	int b;
};

//ģ����̳�ģ����
template<class T>
class C:public A<T>{

public:
	C(T c,T a) :A<T>(a){
		
	}
protected:
	T c;
};

void CC(){
	//ʵ����ģ�������
	A	<int> a(6);
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>	
using namespace std;

#include <stdexcept>

/*
void mydiv(int a, int b){
	if (b == 0){
		throw"除数为零";
	}
}

void func(){
	try {
		mydiv(8, 0);
	}
	catch (char* a){
		throw a;
	}

}
//C++  异常处理, 根据抛出的异常数据类型,进入到相应的catch块中


void main(){
	try{
		int age = 300;
		if (age > 200){
			throw age;
			throw "发生异常";
		}
	}
	catch (int a ){
		cout << "int 异常" << endl;
	}
	catch (char* a){
		cout << a << endl;
	}
	catch (...){
		cout << "未知异常" << endl;
	}
	//=====================================
	try {
		mydiv(8,0);
	}
	catch (char* a){
		cout << a << endl;
	}

	//=====================================

	try { 
		func();
	}
	catch (char* a){
		cout << a << endl;
	}

	system("pause");
}
*/

/*
//抛出异常对象
class MyException{
 
};
void mydiv(int a, int b){
	if (b == 0){ 
		// 	throw new MyException(); //不要去抛指针,因为  动态内存,所以需要手动释放内存-->delete()
		throw MyException();  //局部对象
	}
}
void main(){
	try{
		mydiv(8,0);
	}
	//catch (MyException e0){ cout << "sdsds" << endl; } 
	catch (MyException  &e2){
		cout << "sdsd引用" << endl;
	}
	//会产生对象的副本
	catch (MyException* e1){
		cout << "sdsd指针s" << endl;
		delete(e1);
	}
	
	system("pause");
}
*/
/*
void mydiv(int a, int b)throw(char*){
	if (b == 0){
		// 	throw new MyException(); //不要去抛指针,因为  动态内存,所以需要手动释放内存-->delete()
		throw "throw  声明函数会抛出的异常类型  ";   
	}
}*/
/*
//标准异常  类似于Java 空指针异常
class NullPointerException : public exception{
public:
	NullPointerException(char* msg) : exception(msg){

	}
};
void mydiv(int a, int b)throw(char*){
	if (b > 10){
		// 	throw new MyException(); //不要去抛指针,因为  动态内存,所以需要手动释放内存-->delete()
		throw  out_of_range("超出范围");
	}
	else if (b == 0){
		throw  invalid_argument("参数不合法");
	}
	else if (b == NULL){
		throw  NullPointerException("为空");
	}
}
void main(){
	try{
		mydiv(8, NULL);
	}
	catch (out_of_range e1){
		cout << e1.what() << endl;
	}
	catch (NullPointerException& e2){
		cout << e2.what() << endl;
	}
	catch (...){

	}

	system("pause");
}*/

/*
//外部类异常
class Err{
public:
	class MyException{
	public:MyException(){

	}
	};
};

void mydiv(int a, int b){
	if (b > 10){
		throw Err::MyException();
	}

}*/

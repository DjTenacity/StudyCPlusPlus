#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>	
using namespace std;

#include <stdexcept>

/*
void mydiv(int a, int b){
	if (b == 0){
		throw"����Ϊ��";
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
//C++  �쳣����, �����׳����쳣��������,���뵽��Ӧ��catch����


void main(){
	try{
		int age = 300;
		if (age > 200){
			throw age;
			throw "�����쳣";
		}
	}
	catch (int a ){
		cout << "int �쳣" << endl;
	}
	catch (char* a){
		cout << a << endl;
	}
	catch (...){
		cout << "δ֪�쳣" << endl;
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
//�׳��쳣����
class MyException{
 
};
void mydiv(int a, int b){
	if (b == 0){ 
		// 	throw new MyException(); //��Ҫȥ��ָ��,��Ϊ  ��̬�ڴ�,������Ҫ�ֶ��ͷ��ڴ�-->delete()
		throw MyException();  //�ֲ�����
	}
}
void main(){
	try{
		mydiv(8,0);
	}
	//catch (MyException e0){ cout << "sdsds" << endl; } 
	catch (MyException  &e2){
		cout << "sdsd����" << endl;
	}
	//���������ĸ���
	catch (MyException* e1){
		cout << "sdsdָ��s" << endl;
		delete(e1);
	}
	
	system("pause");
}
*/
/*
void mydiv(int a, int b)throw(char*){
	if (b == 0){
		// 	throw new MyException(); //��Ҫȥ��ָ��,��Ϊ  ��̬�ڴ�,������Ҫ�ֶ��ͷ��ڴ�-->delete()
		throw "throw  �����������׳����쳣����  ";   
	}
}*/
/*
//��׼�쳣  ������Java ��ָ���쳣
class NullPointerException : public exception{
public:
	NullPointerException(char* msg) : exception(msg){

	}
};
void mydiv(int a, int b)throw(char*){
	if (b > 10){
		// 	throw new MyException(); //��Ҫȥ��ָ��,��Ϊ  ��̬�ڴ�,������Ҫ�ֶ��ͷ��ڴ�-->delete()
		throw  out_of_range("������Χ");
	}
	else if (b == 0){
		throw  invalid_argument("�������Ϸ�");
	}
	else if (b == NULL){
		throw  NullPointerException("Ϊ��");
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
//�ⲿ���쳣
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

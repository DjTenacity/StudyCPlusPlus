#include <iostream>	
using namespace std;

//C++ ����ת��
//static_cast �ձ����
//const_cast  ȥ����
//dynamoc_cast  ��������תΪ��������
//reinterpret_cast  ����ָ��ת��,���߱���ֲ��

//ԭʼ����ת��,�����������һ��д��,�ɶ��Բ���.������Ǳ�ڵķ���
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
	//�Զ�ת��``````````````
	//double x = i;
	//double x = 9.5;
	//int i=x;
	 

	int i = 8;
	double d = 9.5;
	i = static_cast<int>(d);

	//char* c_p = (char*)func(2);
	char* c_p = static_cast<char*> (func(2));

	//C++ ��ͼ����
	func2(static_cast<char*> (func(2)));
	//C
	func2((char*)func(2));


	cout << i << c_p << endl;
	system("pause");
}*/

/* 
void func(const char c[]){
	//c[1]='a'
	//ͨ��ָ���Ӹ�ֵ
	//	�����˲���֪��,���ת����Ϊ�� ȥ����
	//char* c_p = (char*)c;
	//c_p[1] = 'L';
	
	//����˿ɶ���
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
		cout << "���" << endl;
	}
};

class WoMan :public Person{
public:
	void print(){
		cout << "WoMan" << endl;
	}
	void carebaby(){
		cout << "������" << endl;
	}
};
/*
void func(Person* obj){
	obj->print();

	//������������еĺ���,תΪʵ������
	 //�������Ů��,������ת�������ᱨ��  ,����֪��ת��ʧ��
	//Man *m = (Man*)obj;
	//m->chasing();

	//���ת��ʧ��,�ͻ᷵�ؿ�,����
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
	//����ָ������
	f_p f_array[6];
	//��ֵ
	f_array[0] = func1;

	//C��ʽ
	//f_array[1] = (f_p)(func2);
	//C++��ʽ
	f_array[1] = reinterpret_cast<f_p>(func2);

	f_array[1]();

	system("pause");
}

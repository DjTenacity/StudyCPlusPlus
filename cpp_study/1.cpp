#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <stdarg.h>

//��׼�����ռ�(�����ܶ��׼�Ķ���)
// std:: ----> standard
using namespace std;
//�����ռ�������Java�еİ�

//�Զ��������ռ�,��������нṹ��
namespace NSP_A{
	int a = 19;
	//�����ռ�Ƕ��
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
	//<<  ���������,���ű���û���κ�����
	//std::cout << "this is c plis plus" << std::endl;
	cout << "this is c plis plus" << endl;
	//ʹ�������ռ� --->����������� ����Java�İ�������:����
	//  :: �������η�
	cout << NSP_A::a << endl;
	cout << NSP_B::a << endl;
	cout << NSP_A::NSP_C::C << endl;

	//ʹ�������ռ��еĽṹ��
	//using namespace NSP_A;
	//Teacheer t;
	//t.age = 10;
	//NSP_A::Teacheer t;
	//t.age = 10;

	using NSP_A::Student;
	Student ss;
	system("pause");
}
//���治���зֺ�,���е�ʱ����޲�����
#define PI 3.1415
//const double  PI =3.1415;
class MyCircle{
	//����(����Ȩ�޷������η�)
private:
	double r;
	double r2;

public:
	double length;
	void setR(double r){
		this->r = r;
	}
	//��ȡ���
	double getS(){
		return  PI * r * r ;
	}

public:
	double length2;
};


//�ṹ�� 
struct MyTeacher2{
public:
	char name[20];
	int age;
public:
	void say(){
		cout << this->age << "��" << endl;
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
	cout << "�������" << c1.getS() << endl;


	/*
	//��������
	//bool isSingle = true;
	bool isSingle = 17;
	//false -17

	if (isSingle){
		cout << "����" << endl;
		cout << sizeof(bool) << endl;
	}
	else{
		cout << "�ж���" << endl;
	}
	int a = 10, b = 20;
	//int c=((a > b) ? a : b)
	((a > b) ? a : b) = 30;
	cout << b << endl;
	*/
	//=========================����========================

	//������-���ƺ�(�ڴ�ռ�0x00001�ı������ɲ������ж�����֣�)
	int a = 10;
	//b������ڴ�ռ�����һ������\
			//& C++�е�����
	int &b = a;
	cout << b << endl;

	system("pause");
}

//ָ��ֵ����
void swap_1(int *a, int *b){
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

//����ֵ����
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
	//a����x�ı���
	swap_2(x, y);
	printf("%d,%d\n", x, y);

	system("pause");
}

//���õ���Ҫ:��Ϊ�����Ĳ����򷵻�ֵ
struct Teacher{
	char* name;
	char name2[22];
	int age;
};
//����
void myprint(Teacher &t){
	cout << t.name << "," << t.age << endl;
	t.age = 21;
}
//ָ��
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
	//���ٿռ�
	Teacher *tmp = (Teacher*)malloc(sizeof(Teacher));
	tmp->age = 21;
	strcpy(tmp->name2, "wwwww");
	*p = tmp;

	cout << tmp->name2 << "," << tmp->age << endl;
}
//ָ������ô������ָ��
// Teacher* &p=(Teacher * *p)
void getTeacher(Teacher* &p){
	//���ٿռ�
	p = (Teacher*)malloc(sizeof(Teacher));
	p->age = 21;
}
//==============ָ�뱣����ǵ�ַ,�����Ǳ����ı���=============
void main6(){
	Teacher *t = NULL;
	getTeacher(&t);

	//=================ָ�볣���볣��ָ��=============

	//ָ�볣��,ָ��ĳ���,���ı��ַ��ָ��,���ǿ����޸���ָ�������
	int a = 2, b = 3;
	int *const p1 = &a;
	//p1 = &b;--->����
	*p1 = 4;

	//����ָ��,ָ������ָ��,���ݲ����޸�
	const int *p2 = &b;
	p2 = &a;
	//*p2 =9;  //����
}

//����������ȡ����û���κ�����,��Ϊ������������,�ܱ�֤�������ݹ����в���������
//���ÿ���ֱ�Ӳ�������,ָ��Ҫͨ��ȡֵ(*p) ,��Ӳ�������,ָ��Ŀɶ��Բ�

void main7(){
	//const int a;
	//���ñ���Ҫ��ֵ,����Ϊ��
	//int &a=NULL;

	//������   ������Java�е�final
	int a = 10, b = 9;
	const int  &c = a;

	// c = b; 
	//������
	const int &d = 79;

	//�����Ǳ����ı���,�������� �൱�� ��������,ָ�뱣����Ǳ����ĵ�ַ
	Teacher t;
	Teacher &t1 = t;
	Teacher *p = &t;

	cout << "32-->��������" << sizeof(t) << endl;
	cout << "32-->���ó���" << sizeof(t1) << endl;
	cout << "4->ָ���������,Ҳ��ָ�뱣��ı����ĵ�ַ�ĳ���" << sizeof(p) << endl;
	cout << "32-->ָ��ָ��ı����ĳ���" << sizeof(*p) << endl;
	Teacher *s = NULL;
	getTeacher(&s);
	//���ò���Ҫ�ǿ��ж�(���ò���Ϊ��,û������ȥ),��ָ����Ҫ
	//����-->��Ч,����
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
//����Ĭ�ϲ���
void myprint(int x = 10){
	cout << x << endl;
}
void myprint2(int x ,int y= 10,int z=30){
	cout << x << endl;
}
//����
void myprint2(int x,bool z  ){
	cout << x << endl;
}
void main8(){
	myprint();
	myprint(30);
	myprint2(10);
}
//�ɱ����  -->Java:Task,Acytask
void func(int i,...){
	//�ɱ����ָ��
	va_list args_p;
	//��ʼ��ȡ�ɱ����,i�����һ���̶�����
	va_start(args_p,i);

	/*
	int a=va_arg(args_p,int);
	char b = va_arg(args_p, char);
	char c = va_arg(args_p, char);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;*/

	//��������ͬ���͵�
	int value;
	while (1){
		value = va_arg(args_p, int);
		if (value <= 0){
			break;
		}
		cout << value << endl;
	}

	//����
	va_end(args_p);
}

//C++������ձ�д��
#include "MyTeacher.h"

void main9(){
	MyTeacher t1;
	t1.name = "����";
	t1.age = 22;
	 cout << t1.getName() << endl;

	func(30 ,50, 30, 40);
	//func(30,'a','a',30,40);
	main7();
	main8();
}

//�����Ǳ����ı���,��Ҫ���ں����Ĳ������߷���ֵ
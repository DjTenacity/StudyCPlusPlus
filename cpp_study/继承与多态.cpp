#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>	

using namespace std;

//�̳�  �����������
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
protected://�������
	char* name2;
	
private://ֻ���ڱ���
	int age;
	char* name;
};

class Man :public Hunman{
public :
	//�����๹�캯������,ͬʱ�����Զ��󴩲�
	Man(char *brother, char *name, int age, char *h_name, int h_age) :Hunman(name, age), h(h_name, h_age){
		this->brother = brother;
	}
	//���
	void chasing(){
		cout << "sd���asdsa" << endl;
	}
	void say(){ 
		cout << "��ļٵ�����" << endl; 
	}
private:
	char* brother;
	Hunman h;
};
void work(Hunman &h){
	h.say();
}

void main(){
	//����Ĺ��췽������֮ǰ���ȵ��ø���Ĺ��췽��
	//�������û���޲εĹ��췽��,��ô�ͱ�������Ĺ��췽������

	Man m1("sdsds", "wewqeewq", 22, "w������wq", 11);
	//�Ǹ��ǲ��Ƕ�̬
	m1.say();
	//���ø������������
	m1.Hunman::say();
	m1.Hunman::size = 11;

	//�������͵����û�ָ��
	Hunman* h_p = &m1;
	Hunman &h1 = m1; 

	h_p->say();
	h1.say();

	//��������ʼ���������͵Ķ���
	Hunman  h2 = m1;

	
	system("pause");
}
*/
//���и������,�����������(�ȵ��ø��๹�캯��,������������)
//�����������,�����������(��������)

//��������һ��������,���ุ��ֻ����д

 
//��̳�
//��
class Person{

};
//����
class Citizen{

};
//ѧ��,��̳����ഩ�λ��ر��鷳
class Student : public Person, public Citizen{

};

//�̳еĶ�����,Ʃ��   B1,B2���̳���A,Cͬʱ�̳���B1,B2
//��̳У���ͬ·���̳�����ͬ����Աֻ��һ�ݿ������������ȷ������
/*
class A{
public:
	char* name;
};

class A1 : virtual public A{

};

class A2 : virtual public A{

};
//��̳�
class B : public A1, public A2{

};

void main(){
	B b;
	b.name = "jason";
	//ָ������  ��ʾ����
	//b.A1::name = "advance";
	//b.A2::name = "��������";
	system("pause");
}
*/


//�麯��
//��̬(�������չ��)
//��̬��̬���������й����У�������һ�����������ã���д��
//��̬��̬������

//������̬��������
//1.�̳�
//2.��������û���ָ��ָ������Ķ���
//3.��������д

#include "Plane.h"
#include "Jet.h"
//ҵ����
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

//���麯��(������)
//1.��һ�������һ�����麯�����������ǳ�����
//2.�����಻��ʵ��������
//3.����̳г����࣬����Ҫʵ�ִ��麯�������û�У�����Ҳ�ǳ�����
//����������ã�Ϊ�˼̳�Լ����������֪��δ����ʵ��
//��״
/* 
class Shape{
public:
	//���麯��
	virtual void sayArea() = 0;

	void print(){
		cout << "hi" << endl;
	}
};

//Բ
class Circle : public Shape{
public:
	Circle(int r){
		this->r = r;
	}
	void sayArea(){
		cout << "Բ�������" << (3.14 * r * r) << endl;
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

//�ӿڣ�ֻ���߼��ϵĻ��֣��﷨�ϸ��������д��û������
//���Ե���һ���ӿ�
/*
class Drawble{
//�麯���봿�麯�����������  =0 ����
virtual void draw();
};
*/
 
//ģ�庯�������ͣ�
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

//���֣�����������ҵ���߼�һ�����������Ͳ�һ��
template <typename T>
void myswap(T& a, T& b){
	T tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void mainp(){
	//����ʵ�����ͣ��Զ��Ƶ�
	int a = 10, b = 20;
	myswap<int>(a, b);
	cout << a << "," << b << endl;

	char x = 'v', y = 'w';
	myswap(x, y);
	cout << x << "," << y << endl;

	system("pause");
}

//���һ��Դ�ļ�,���к������������к�����ʵ��,���Դ�ļ��ĺ�׺���ͻ���  .hpp
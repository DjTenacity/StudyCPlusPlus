#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>

using namespace std;
/*C��C++�Ĺ�ϵ

1.C++������C������л��
2.C++�������ı������ , C������̵ı��
3.C++��C��һ����ǿ


malloc() free() 
new delete() 

//C/C++ �ڴ����:ջ,��,ȫ�� (��̬,ȫ��),������(�ַ��� char*),���������
//��ͨ������ṹ����ͬ���ڴ沼��

//jvm Stack (������������,��������),Native Stack(���ط���ջ) ,
//������

 */

/*
//��Ԫ����
class A{
private:
	int i;
public:
	A(int i){
		this->i = i;
	}
	void myprint(){
		cout << i << endl;
	}
	//��Ԫ����-->��������������
	friend void modify_i(A* p,int  a);
};

//��Ԫ������ʵ��,����Ԫ�����п��Է���˽�е�����
void modify_i(A* p, int  a){
	p->i = a;
}

void main(){
	A* a = new A(10);
	a->myprint();

	modify_i(a,20);
	a->myprint();

	system("pause");
}
*/

//��Ԫ��
class A{
	//��Ԫ��
	//B���������Ԫ�����A ���κγ�Ա
	friend class B;
private:
	int i;
public:
	A(int i){
		this->i = i;
	}
	void myprint(){
		cout << i << endl;
	}
};

class B{
public :
	void accessAny(){
		a.i = 30;
	}

private :A a;
};

//���������
/*
class Point{
private:
	
public :
	int x;
	int y;
	Point(int x=0,int y=0){
		this->x = x;
		this -> y = y;
	}
	//��Ա����,���������
	Point operator*(  Point &p2){
		Point tmp(this->x * p2.x, this->y * p2.y);
		return tmp;
	}
	void myprint(){
		cout << x << "vvv" << y << endl;
	}
};
//���ؼӺ�
Point operator+(Point &p1, Point &p2){
	Point tmp(p1.x+p2.x,p1.y+p2.y);
	return tmp;
}
//���� - ��
Point operator-(Point &p1, Point &p2){
	Point tmp(p1.x - p2.x, p1.y - p2.y);
	return tmp;
}

void main(){
	Point p1(10,19);
	Point p2(12, 19);
	//�����������,���ʻ��Ǻ����ĵ���
	//p1.operator*(p2);
	Point p3 = p1 * p2;
	Point p4 = p1 + p2;
	p3.myprint();
}
*/


//������˽��ʱ,ͨ����Ԫ����������������
class Point{
	friend Point operator+(Point &p1, Point &p2);
private:
	int x;
	int y;
public:
	
	Point(int x = 0, int y = 0){
		this->x = x;
		this->y = y;
	}
	//��Ա����,���������
	Point operator*(Point &p2){
		Point tmp(this->x * p2.x, this->y * p2.y);
		return tmp;
	}
	void myprint(){
		cout << x << "vvv" << y << endl;
	}
};

//���ؼӺ�
Point operator+(Point &p1, Point &p2){
	Point tmp(p1.x + p2.x, p1.y + p2.y);
	return tmp;
}

/*  Java

Class cls = Class.forName("com.lovedj.Teacher");
cls.setAccessable(true);

String a1="aaa";
String a2 ="qweqwe";
String a3=a1+a2;

*/
#include <stdlib.h>
#include <iostream>
//�ṹ��Ĵ�С-->�������ԵĴ�С��������
//��Ĵ�С

using namespace std;
class A{
public:
	int a;
	int c;
	int d;

	void(*myprintf)() = myprintf;
};
void myprintf(){
	cout << "dayin" << endl;
}
class B{
public:
	int a;
	int c;
	int d;
};
//this 
//�����ǹ����,����Ҫ���ܹ���ʶ��ǰ������˭�ķ���
class Teacher {
private:
	char* name;
	int age;
public:
	Teacher(char* name, int age){
		this->name = name;
		this->age = age;
		cout << "�вι��캯��" << endl;
	}
	~Teacher(){
		cout << "��������" << endl;
	}
	void setName(char* name){
		this->name = name;
	}
	char* getName(){
		return this->name;
	}
	void myprintf(){
		printf("%#x\n",this);
		cout << this->age<<this->name << endl;
	}
	//������,���ε���this,�Ȳ��ܸı�ָ��ָ�������,Ҳ���ܸı�ָ���ֵ
	void myprintf2() const{
		printf("%#x\n", this);
		//�ı����Ե�ֵ
		//this->name ="qweqssswewq"
		//�ı�thisָ���ֵ
		//this =(Teacher*)0x00009;

		cout << this->age << this->name << endl;
	}
};
void mainConst(){
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;

	//C/C++ �ڴ����:ջ,��,ȫ�� (��̬,ȫ��),������(�ַ��� char*),���������
	//��ͨ������ṹ����ͬ���ڴ沼��
	Teacher t1("weweq",22);
	const Teacher t2("wewwweq", 21);

	//������,��ǰ�����ܱ��޸�,��ֹ���ݳ�Ա���Ƿ�����
	printf("%#x\n", t1);
	t1.myprintf2();

	printf("%#x\n", t2);
	//��������ֻ�ܵ��ó�������,���ܵ��÷ǳ�������
	t2.myprintf2();
	//t2.myprintf();
	system("pause");
}


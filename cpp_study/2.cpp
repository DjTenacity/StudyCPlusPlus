#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>

using namespace std;


//���캯���������������������캯��
/*
class Teacher{
private:
	char *name;
	int age;
public:
	//�޲ι��캯����д�ˣ��ͻḲ��Ĭ�ϵ��޲ι��캯����
	Teacher(){
		cout << "�޲ι��캯��" << endl;
	}
	//�вι��캯���Ḳ��Ĭ�ϵĹ��캯��
	Teacher(char *name, int age){
		this->name = name;
		this->age = age;
		cout << "�вι��캯��" << endl;
	}
};


void main(){
	//Teacher t1;
	Teacher t2("yuehan", 20);

	//����һ�ֵ��÷�ʽ
	Teacher t3 = Teacher("jack", 21);

	system("pause");
}
*/

/*
//��������
class Teacher{
private:
	char *name;
	int age;
public:
	//�޲ι��캯����Ĭ��ֵ
	Teacher(){
		this->name = (char*)malloc(100);
		strcpy(name, "jack walson");
		age = 20;
		cout << "�޲ι��캯��" << endl;
	}
	//��������
	//������Ҫ��ϵͳ�ͷ�ʱ����������������
	//���ã��ƺ���
	~Teacher(){
		cout << "����" << endl;
		//�ͷ��ڴ�
		free(this->name);
	}
};

void func(){
	Teacher t1;
}

void main(){
	func();

	system("pause");
}
*/

//�������캯��
/*
class Teacher{
private:
	char *name;
	int age;
public:
	Teacher(char *name, int age){
		this->name = name;
		this->age = age;
		cout << "�вι��캯��" << endl;
	}
	//�������캯����ֵ������
	//Ĭ�Ͽ������캯��������ֵ����
	Teacher(const Teacher &obj){
		this->name = obj.name;
		this->age = obj.age;
		cout << "�������캯��" << endl;
	}
	void myprint(){
		cout << name << "," << age << endl;
	}
};

Teacher func1(Teacher t){
	t.myprint();
	return t;
}

void main(){
	Teacher t1("rose", 20);

	//�������캯�������õĳ���
	//1.����ʱ��ֵ
	//Teacher t2 = t1;
	//t2.myprint();
	//2.��Ϊ�������룬ʵ�θ��βθ�ֵ
	func1(t1);
	//3.��Ϊ��������ֵ���أ���������ʼ����ֵ
	//Teacher t3 = func1(t1);

	//���ﲻ�ᱻ����
	//Teacher t1 ;
	//Teacher t2;
	//t1 = t2;

	system("pause");
}
*/

//ǳ������ֵ����������
/*
class Teacher{
private:
char *name;
int age;
public:
Teacher(char *name, int age){
this->name = (char*)malloc(100);
strcpy(this->name,name);
this->age = age;
cout << "�вι��캯��" << endl;
}
~Teacher(){
cout << "����" << endl;
//�ͷ��ڴ�
free(this->name);
}
void myprint(){
cout << name << "," << age << endl;
}
};

void func(){
Teacher t1("rose", 20);

Teacher t2 = t1;
t2.myprint();
}

void main(){
func();

system("pause");
}
*/

//���
/*
class Teacher{
private:
	char *name;
	int age;
public:
	Teacher(char *name, int age){
		int len = strlen(name);
		this->name = (char*)malloc(len + 1);
		strcpy(this->name, name);
		this->age = age;
		cout << "�вι��캯��" << endl;
	}
	~Teacher(){
		cout << "����" << endl;
		//�ͷ��ڴ�
		free(this->name);
	}
	//���
	Teacher(const Teacher &obj){
		//����name����
		int len = strlen(obj.name);
		this->name = (char*)malloc(len + 1);
		strcpy(this->name, obj.name);
		this->age = obj.age;
	}
	void myprint(){
		cout << name << "," << age << endl;
	}
};

void func(){
	Teacher t1("rose", 20);

	Teacher t2 = t1;
	t2.myprint();
}

void main(){
	func();

	system("pause");
}
*/
//ָ���ǳ�������ǿ����ĵ�ַ,�������

//���캯�������Գ�ʼ���б�
/*
class Teacher{
private:
	char* name;
public :
	Teacher(char* name){
		this->name = name;
		cout <<"�вι��캯��" << name << endl;
	}
	~Teacher(){
		cout << "��������" << name << endl;
	}
	char* getName(){
		return this->name;
	}

};

class Student{
private:
	int id;
	//���Զ���
	//Teacher t = Teacher("miss");
	Teacher t1;
	Teacher t2;
public:
	Student(int id, char *t1_n, char *t2_n) :t1(t1_n), t2(t2_n) {
		this->id = id;
	}
	void myprint(){

		cout << id << "m����" << t1.getName << "m����22" << t2.getName << endl;
	}
	~Student(){
	}
};
//teacher �����ȴ���,student������
void main(){
	Student s1(10,"miss","asdfasdas");
	s1.myprint();
	system("pause");
	}*/


//C++ ͨ��new(delete)��̬�ڴ����
//C malloc(free)
/*
class Teacher {
private:
	char* name;
public:
	Teacher(char* name){
		   this->name = name;
		   cout << "�вι��캯��" << endl;}
	~Teacher(){
		cout << "��������" << endl;
	}
	void setName(char* name){
		this->name = name;
	}
	char* getName(){
		return this->name;
	}
};
void func(){
	//C++
	//new ��̬����
	Teacher *t1 = new Teacher("jvava ee");
	cout << t1->getName() << endl;
	//�ͷ�
	delete t1;

	//C    --->������ù��췽������������
	Teacher *t2 = (Teacher*)malloc(sizeof(Teacher));
	t2->setName("wewqeqw");
	free(t2);
}

void main(){
	func();

	//��������,,,,ָ�뺯�����ص���ָ��,,,����ָ�뱣����Ǻ����ĵ�ַ
	//    C
	//int *p1 = (int*)malloc(sizeof(int) *10);
	//p1[0] = 99;
	//free(p1);

	//C++
	int *p2 = new int[10];
	p2[0] = 12;
	//�ͷ�����
	delete[] p2;

	system("pause");
	}
	*/

/*
class Teacher {
private:
	char* name;
	//static ��̬���Ժͺ���
public:
	//������
	static int total;
	Teacher(char* name){
		this->name = name;
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
	//��̬�������ܷ��ʷǾ�̬������
	static void count(){
		total++;
		cout << total << endl;
	}
};
//��̬���Գ�ʼ����ֵ
int Teacher::total = 9;

void main(){
	//�ⲿ�����ռ�,�ڲ������ռ�,����
	//B::A::Teacher::count();
	Teacher::count();
	Teacher::total++;

	Teacher t1("wqeqweqwda");
	t1.count();
	}
	*/
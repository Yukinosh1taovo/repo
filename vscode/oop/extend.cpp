#include<iostream>
using namespace std;


class B {
public:
	B(); // 构造函数（空参构造）
	B(int i); // 构造函数（带参）
	~B(); // 析构函数
	void print() const; // 常成员函数
	virtual void display() const; // 虚函数 
private:
	int b; // 成员变量
};



B::B() {
	b=0;
	cout << "B's default constructor called." << endl;
}
B::B(int i) {
	b=i;
	cout << "B's constructor called." << endl;
}
B::~B() {
	cout << "B's destructor called." << endl;
}
void B::print() const {
	cout << b << endl;
}



class C: public B // 公有继承
{
public:
	C();
	C(int i, int j); // 先给定基类的构造参数 再给派生类的构造参数
	~C();
	void print() const;
private:
	int c;
};



C::C() {
	c = 0;
	cout << "C's default constructor called." << endl;
}
C::C(int i,int j): B(i), c(j){
	cout << "C's constructor called." << endl;
}
C::~C() {
	cout << "C's destructor called." << endl;
}
void C::print() const {
	B::print();
	cout << c << endl;
}




int main() {
	C obj(5, 6);
	obj.print();
	return 0;
}

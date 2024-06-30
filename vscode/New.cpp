#include<iostream>
using namespace std;

class A{
public:
    A();
    A(int, int);
    ~A();
    void fun();

private:
    int val1, val2;

};

A::A(){val1 = 0;val2 = 0;}
A::A(int v1, int v2):val1(v1), val2(v2){};
A::~A(){}
void A::fun(){cout << "hello world";}


class B : public A{
public:
    B(){}
    B(int val_):val(val_){}
    ~B(){}
    void fun();

private:
    int val;

};

void B::fun(){cout << "coding";}


int main()
{
    B b;
    b.A::fun();
    system("pause");
    return 0;

}
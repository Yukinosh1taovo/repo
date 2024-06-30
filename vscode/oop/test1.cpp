#include<iostream>
using namespace std;

class A{
    public:
    A(){cout<<"a";}
    ~A(){cout<<"b";}
};

class B :public A{
    A obj;
public:
    B(){cout << "c";}
    ~B(){cout<<"d";}
};

int main()
{
    B b; // aacdbb
    system("pause");
    return 0;
}
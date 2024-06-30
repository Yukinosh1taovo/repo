#include<iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;
public:
    Complex();
    Complex(double);
    Complex(double, double);
    friend Complex operator+(Complex&, Complex&); // 友元运算符重载
    void display();
};

Complex::Complex(): real(0), imag(0){}
Complex::Complex(double r) : real(r){}
Complex::Complex(double r, double i) : real(r), imag(i){}


Complex operator+(Complex& c1, Complex& c2){
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}



void Complex::display()
{
    cout << real << " " << imag;
}



int main()
{
    Complex c1(5, 7);
    Complex c2(3, -8);
    Complex c = c1 + c2;
    c.display();

    system("pause");

}

#include<iostream>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
};

double total(Shape *s[], int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += s[i] -> area();
    return sum;
}

class Circle : public Shape{
public:
    Circle();
    Circle(double);
    void setRadius(double r);
    double getRadius();
    double area();


private:
    double radius;

};

class Squre : public Shape{
public:
    Squre();
    Squre(double);
    void setedge(double l);
    double getedge();
    double area();

private:
    double edge;


};


Circle::Circle():radius(0){}
Circle::Circle(double r):radius(r){}
double Circle::getRadius(){return radius;}
void Circle::setRadius(double r){radius = r;}
double Circle::area(){return 3.14159 * radius * radius;}

Squre::Squre(){edge = 0;}
Squre::Squre(double l):edge(l){}
double Squre::getedge(){return edge;}
void Squre::setedge(double l ){edge = l;}
double Squre::area(){return edge * edge;}


int main()
{
    Circle c(5.5);
    Squre s(9.9);
    Shape *ptr[] = {&c, &s};
    cout << total(ptr, 2) << endl;
    system("pause");
    return 0;
    



}
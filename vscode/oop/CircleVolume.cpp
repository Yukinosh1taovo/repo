class Circle{
public:
    Circle(double r){radius = r;}
    double getvalue(){return radius;}
    double volume(){return 4.0/3 * 3.14159 * radius * radius * radius;}
private:
    double radius;
};




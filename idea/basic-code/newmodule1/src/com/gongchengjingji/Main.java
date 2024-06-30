package com.gongchengjingji;

class Circle {
    final float PI = 3.14159f;
    private double radius;

    Circle(double r)
    {
        this.radius = r;
    }

    double getRadius()
    {
        return this.radius;
    }

    double getArea(){
        return PI * radius * radius;
    }

}


class Cylinder extends Circle{
    double length;
    Cylinder(double r, double l){
        super(r);
        length = l;
    }

    double getVolume()
    {
        return getArea() * length;
    }

    public String toString()
    {
        return getRadius() + " " + length + " " + getVolume();
    }
}


public class Main {
    public static void main(String[] args) {
        Cylinder c = new Cylinder(1, 5);
        System.out.println(c.toString());
    }
}


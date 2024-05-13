import java.util.Scanner;

interface Calculate
{
    double calculateArea();
    double calculatePerimeter();

}

class Circle implements Calculate {
    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    public double calculateArea() {
        return Math.PI * radius * radius;
    }

    public double calculatePerimeter() {
        return 2 * Math.PI * radius;
    }
}

class Rectangle implements Calculate
{
    double length;
    double width;
    public Rectangle(double length, double width)
    {
        this.length = length;
        this.width = width;
    }

    public double calculateArea()
    {
        return length * width;
    }

    public double calculatePerimeter()
    {
        return 2 * (length + width);

    }
}



public class CalculateArea {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String shape = sc.next();
        double param1 = sc.nextDouble();
        double param2 = 0;

        if (shape.equals("R"))
        {
            param2 = sc.nextDouble();
        }

        if (shape.equals("C"))
        {
            Circle circle = new Circle(param1);
            System.out.printf("周长为: %.2f\n", circle.calculatePerimeter());
            System.out.printf("面积为: %.2f\n", circle.calculateArea());
        }
        else
        {
            Rectangle rectangle = new Rectangle(param1, param2);
            System.out.printf("周长为: %.2f\n", rectangle.calculatePerimeter());
            System.out.printf("面积为: %.2f\n", rectangle.calculateArea());
        }

        sc.close();
    }
}

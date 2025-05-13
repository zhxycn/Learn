import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner;
        scanner = new Scanner(System.in);

        System.out.println("请输入三角形边长:");
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double c = scanner.nextDouble();

        System.out.println("请输入矩形边长:");
        double width = scanner.nextDouble();
        double height = scanner.nextDouble();

        System.out.println("请输入圆半径:");
        double radius = scanner.nextDouble();

        Shape triangle = new Triangle(a, b, c);
        Shape rectangle = new Rectangle(width, height);
        Shape circle = new Circle(radius);

        System.out.println(triangle);
        System.out.println(rectangle);
        System.out.println(circle);

        Shape[] shapes = {triangle, rectangle, circle};
        String[] names = {"三角形", "矩形", "圆"};
        for (int i = 0; i < shapes.length; i++) {
            for (int j = i + 1; j < shapes.length; j++) {
                int perimeterResult = shapes[i].comparePerimeter(shapes[j]);
                String perimeterCompare = perimeterResult == 0 ? "等于" :
                        (perimeterResult > 0 ? "大于" : "小于");
                System.out.println(names[i] + "的周长" + perimeterCompare + names[j] + "的周长");

                int areaResult = shapes[i].compareArea(shapes[j]);
                String areaCompare = areaResult == 0 ? "等于" :
                        (areaResult > 0 ? "大于" : "小于");
                System.out.println(names[i] + "的面积" + areaCompare + names[j] + "的面积");
            }
        }
    }
}

abstract class Shape {
    public abstract double getPerimeter();

    public abstract double getArea();

    @Override
    public String toString() {
        return super.toString();
    }

    public int comparePerimeter(Shape shape) {
        double diff = this.getPerimeter() - shape.getPerimeter();
        if (Math.abs(diff) < 1e-10) return 0;
        return diff > 0 ? 1 : -1;
    }

    public int compareArea(Shape shape) {
        double diff = this.getArea() - shape.getArea();
        if (Math.abs(diff) < 1e-10) return 0;
        return diff > 0 ? 1 : -1;
    }
}

class Triangle extends Shape {
    private double a, b, c;

    public Triangle(double a, double b, double c) {
        setA(a);
        setB(b);
        setC(c);
    }

    public double getA() {
        return a;
    }

    public void setA(double a) {
        this.a = a;
    }

    public double getB() {
        return b;
    }

    public void setB(double b) {
        this.b = b;
    }

    public double getC() {
        return c;
    }

    public void setC(double c) {
        this.c = c;
    }

    @Override
    public double getPerimeter() {
        return getA() + getB() + getC();
    }

    @Override
    public double getArea() {
        double s = (getA() + getB() + getC()) / 2;
        return Math.sqrt(s * (s - getA()) * (s - getB()) * (s - getC()));
    }

    @Override
    public String toString() {
        return "三角形面积: " + getArea() + "周长: " + getPerimeter();
    }
}

class Rectangle extends Shape {
    private double width, height;

    public Rectangle(double width, double height) {
        setWidth(width);
        setHeight(height);
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    @Override
    public double getPerimeter() {
        return 2 * (getWidth() + getHeight());
    }

    @Override
    public double getArea() {
        return getWidth() * getHeight();
    }

    @Override
    public String toString() {
        return "矩形面积: " + getArea() + "周长: " + getPerimeter();
    }
}

class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        setRadius(radius);
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public double getPerimeter() {
        return 2 * Math.PI * getRadius();
    }

    @Override
    public double getArea() {
        return Math.PI * getRadius() * getRadius();
    }

    @Override
    public String toString() {
        return "圆面积: " + getArea() + "周长: " + getPerimeter();
    }
}
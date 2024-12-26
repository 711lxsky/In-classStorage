#include <iostream>
#include <cmath>

// 抽象基类 Shape
class Shape {
public:
    [[nodiscard]] virtual double area() const = 0;  // 纯虚函数，计算面积
    virtual void display() const = 0; // 纯虚函数，显示信息
    virtual ~Shape() = default;               // 虚析构函数
};

// 派生类 Circle
class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    [[nodiscard]] double area() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        std::cout << "Circle - Radius: " << radius << ", Area: " << area() << std::endl;
    }
};

// 派生类 Square
class Square : public Shape {
private:
    double side;

public:
    explicit Square(double s) : side(s) {}

    [[nodiscard]] double area() const override {
        return side * side;
    }

    void display() const override {
        std::cout << "Square - Side: " << side << ", Area: " << area() << std::endl;
    }
};

// 派生类 Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    [[nodiscard]] double area() const override {
        return width * height;
    }

    void display() const override {
        std::cout << "Rectangle - Width: " << width << ", Height: " << height << ", Area: " << area() << std::endl;
    }
};

// 派生类 Trapezoid
class Trapezoid : public Shape {
private:
    double base1;
    double base2;
    double height;

public:
    Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}

    [[nodiscard]] double area() const override {
        return (base1 + base2) * height / 2.0;
    }

    void display() const override {
        std::cout << "Trapezoid - Base1: " << base1 << ", Base2: " << base2 << ", Height: " << height << ", Area: " << area() << std::endl;
    }
};

// 派生类 Triangle
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    [[nodiscard]] double area() const override {
        return base * height / 2.0;
    }

    void display() const override {
        std::cout << "Triangle - Base: " << base << ", Height: " << height << ", Area: " << area() << std::endl;
    }
};

int main() {
    // 创建不同形状的对象
    Shape* shapes[5];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Square(4.0);
    shapes[2] = new Rectangle(3.0, 6.0);
    shapes[3] = new Trapezoid(4.0, 6.0, 3.0);
    shapes[4] = new Triangle(5.0, 4.0);

    double totalArea = 0.0;

    // 显示每个形状的详细信息并计算总面积
    for (auto & shape : shapes) {
        shape->display();
        totalArea += shape->area();
    }

    // 输出总面积
    std::cout << "Total Area of all shapes: " << totalArea << std::endl;

    // 释放内存
    for (auto & shape : shapes) {
        delete shape;
    }

    return 0;
}

#include <iostream>

const double PI  =3.141592653589793238463;

using namespace std;

class Shape {
public :
    virtual double calcArea() const =0;
};

class Parallelogram : public Shape {
protected:
    double side_a;
    double side_b;
    double alpha_deg; //угол в градусах, не люблю радианы.
public:
    Parallelogram() : side_a(0), side_b(0), alpha_deg(0) {}
    Parallelogram(double a, double b, double c) : side_a(a), side_b(b), alpha_deg(c) {}
    void setParam(double a, double b, double c) {
        side_a=a;
        side_b=b;
        alpha_deg=c; 
    }
    double calcArea() const override  {
        return side_a*side_b*sin(alpha_deg/180.0*PI);
    }
};

class Circle : public Shape {
protected:
    double radius;
public:
    Circle() : radius(0) {}
    Circle(double r) : radius(r) {}
    void setParam(double r) { radius=r; }
    double calcArea() const override {
        return PI*radius*radius;
    }
};

//Так как мы наследуем от параллелограмма излишние геометрические параметры, а функция вычисления площади обощает все частные случаи
//То мы не будет переопределять функцию, а просто зафиксируем лишние параметры на уровне сетеров и конструкторов.

class Rectangle : public Parallelogram {
public:
    Rectangle() : Parallelogram(0, 0, 90) {}
    Rectangle(double a, double b) : Parallelogram(a, b, 90) {}
    void setParam(double a, double b) {
        side_a=a;
        side_b=b;
    }
};

class Square : public Parallelogram {
public:
    Square() : Parallelogram(0, 0 , 90) {}
    Square(double a) : Parallelogram(a, a, 90) {}
    void setParam(double a) {
        side_a = a;
        side_b = a;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus() : Parallelogram() {}
    Rhombus(double a, double c) : Parallelogram(a, a, c) {}
    void setParam(double a, double c) {
        side_a = a;
        side_b = a;
        alpha_deg = c;
    }
};




int main()
{
    // Проверим написанные классы. Вызывать  будем через указатель на абстрактный класс.

    Shape* someParall= new Parallelogram(3, 2, 30);
    cout << someParall->calcArea() <<endl;

    Shape* someRectangle = new Rectangle(2, 4);
    cout <<someRectangle->calcArea() << endl;

    Shape* someCircle = new Circle(1);
    cout << someCircle->calcArea() << endl;

    Shape* someSquare = new Square(2);
    cout << someSquare->calcArea() << endl;

    Shape* someRhomb = new Rhombus(4,150);
    cout << someRhomb->calcArea() << endl;





}

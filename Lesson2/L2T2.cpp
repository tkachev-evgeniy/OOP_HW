#include <iostream>

using namespace std;

class Fruit {
protected:
    string name;
    string color;
public:
    Fruit() : name("NoName"), color("NoColor") {}
    Fruit(string n, string c) : name (n), color(c) {}
    void setName(string n) {name = n;}
    void setColor(string c) {color = c;}
    string getName() {return name;}
    string getColor() {return color;}
};

class Banana : public Fruit {
protected:
    double banananess ; // должно  же у дочернего класса быть какое-то новое свойство. Пусть будет банановость.
public:
    Banana() : banananess(1.0), Fruit("banana", "yellow") {}
    double getBanananess() const {return banananess;}
    void setBanananess(double b) {banananess = b;}
};

class Apple : public Fruit {
protected:
    double appleness;
public:
    Apple() : appleness(1.0), Fruit ("apple", "green with red stripes") {}
    Apple(string c) : appleness(1.0), Fruit("apple", c) {}
    Apple(string n, string c) : appleness(1.0), Fruit(n, c) {}
    void setAppleness(double a)  {appleness = a;}
    double getAppleness() const {return appleness;}
};

class GrannySmith : public Apple {
    //надоело придумывать новые поля, раз в задании напрямую это не требуется.
public:
    GrannySmith() : Apple("Granny Smith apple", "green") {}

};

int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}

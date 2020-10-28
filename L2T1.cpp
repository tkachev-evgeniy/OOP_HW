#include <iostream>

using namespace std;

class Person {
protected:
    string name;
    int age;
    double weight;
public:
    Person() {
        name = "Default Name";
        age = 0;
        weight =0;
    }
    Person (string n, int a, double w) {
        name = n;
        age = a;
        weight = w;
    }
    void setName(string n) {
        name = n;
    }
    void setAge(int a) {
        age = a;
    }
    void setWeight(double w) {
        weight = w;
    }
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    double getWeight() const {
        return weight;
    }

};

class Student : public Person {
private:
    int year;
    static int stdcount;
public:
    Student() {
       // Person();
        year = 1;
        stdcount++;
    }
    Student(string n, int a, double w, int y) : year(y), Person (n, a, w) {
        stdcount ++;
    }
    ~Student() {
        stdcount--;
    }
    void setYear(int y) {
        year = y;
    }
    void proceed() {
        year++;
    }
    void print() const {
       cout << "Name: " << name << ", Age: " << age << ", Weight: " << weight << ", Year: " << year << endl;
    }
    void showcount() const {
        cout << stdcount << " students" << endl;
    }
};

    int Student::stdcount = 0;

int main()
{

    Student Ivanov("Ivanov", 18, 80, 1);
    Student Petrov;
    Petrov.setName("Petrov");
    Petrov.setAge(19);
    Petrov.setWeight(70.5);
    Petrov.setYear(2);
    Student Sidorov("Sidorov", 22, 120.9, 5);

    //Проверим правильно ли заполнились поля.
    Ivanov.print();
    Petrov.print();
    Sidorov.print();

    //Проверим счетик. Выведем его для двух разных объектов и убедимся что он одинаковый.
    Sidorov.showcount();
    Petrov.showcount();


}

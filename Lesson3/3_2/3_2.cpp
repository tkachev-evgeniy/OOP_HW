#include <iostream>

using namespace std;

class Car {
protected :
    string company;
    string model;
public:
    Car(string c, string m ) : company (c), model(m) {cout << "Car" << endl;}
    Car() : Car("NoCompany", "NoModel") {}
    ~Car() {cout << "~Car" << endl;}
    void showCar() const {cout << "Company: " << company << " Model: " << model << endl;}
};

class PassengerCar : virtual public Car {
protected:
    int seats;
public:
    PassengerCar(int s, string c, string m) : seats(s), Car(c,m) {cout << "PassengerCar" <<endl;}
    PassengerCar() : PassengerCar(0,"NoCompany","NoModel") {}
    ~PassengerCar() {cout << "~PassengerCar" << endl;}
    void showSeats() const { cout << "Seats: " << seats << " ";}
    void showPassCar() const {
        showSeats();
        showCar();
    }
};

class Bus : virtual public Car {
protected:
    int doors;
public:
    Bus(int d, string c, string m) : doors(d), Car(c,m) {cout << "Bus" << endl;}
    Bus() : Bus(0,"NoCompany","NoModel") {}
    ~Bus() {cout << "~Bus" << endl;}
    void showDoors() const {cout << "Doors: " << doors << " ";}
    void showBus() const  {
        showDoors();
        showCar();
    }
};

class Minivan : public PassengerCar, public Bus {
protected:
    int whatever;
public:
    // не очень понятно как тут оптимально написать конструктор.
    Minivan(int w, int d, int s, string c, string m) : Car(c,m), whatever(w) {
        seats = s;
        doors = d;
        cout << "Minivan" << endl;}

    Minivan() : Minivan(0, 0, 0, "NoCompany", "NoModel") {}
    ~Minivan() { cout << "~Minivan" << endl;}
    void showWhatever() const  { cout << "Whatever: " << whatever << " "; }
    void showMinivan() const {
        showWhatever();
        showSeats();
        showDoors();
        showCar();
    }


};

int main()
{
    // Проверим порядок  вызова конструкторов и деструкторов, и сколько раз вызовется конструктор и деструктор базового класса.
    // Чтобы не запутаться в стеке, и не думать где вызов пошел от какого класса разделим создание каждого экземпляра на неименованные блоки.

    {
        cout << "___________________________________" << endl;
        Car Zhigul("Lada", "Shakha");
        Zhigul.showCar();

    }

    {
        cout << "___________________________________" << endl;
        PassengerCar Matryoshka(4, "Mazda", "3");
        Matryoshka.showPassCar();
    }

    {
        cout << "___________________________________" << endl;
        Bus Pazik(3, "PAZ" , "3205");
        Pazik.showBus();
    }


    {
        cout << "___________________________________" << endl;
        Minivan Caravan(1, 4, 8, "Dodge", "Caravan");
        Caravan.showMinivan();
    }



}

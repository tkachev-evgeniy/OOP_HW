#include <iostream>
#include <cmath>

using namespace std;

class Power {

private:
    double number;
    double power;

public:
    Power() : number(1), power(1) {
    }
    Power(double a, double b) {
        number=a;
        power=b;
    }

    void set (double a , double b) {
        number = a;
        power = b;
    }
    double calculate (){
        return pow(number, power);
    }
};

int main()
{

    double a, b;
    cin >> a >> b;

    Power somepower;
    somepower.set(a,b);
    cout << somepower.calculate() << endl;
    return 0;
}

#include <iostream>

using namespace std;

class Ex {
private:
    double x;
public:
    Ex(double x) : x(x) {}
    double getX() const {return x;}
};

class Bar {
private:
    double y;
public:
    Bar() : y(0) {}
    void setY(double a) {
        if ((y+a)>100) throw Ex(a*y);
        y=a; }
};


int main()
{
    Bar aBar;
    int n =1;
    try {
        while (n) {
            cin>>n;
            aBar.setY(n);
        }
    }
    catch(Ex& ex) {
        cout << "Ex type exception caught with x = " << ex.getX() << endl;
    }


}

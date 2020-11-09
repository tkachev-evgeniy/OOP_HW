#include <iostream>

using namespace std;

template <class T>
class Pair1 {
private:
    T First;
    T Second;
public:
    Pair1(T First, T Second) {
        this->First = First;
        this->Second = Second;
    }
    T first() const {return First;}
    T second() const {return Second;}
};

template <class T, class U>
class Pair {
private:
    T First;
    U Second;
public:
    Pair (T First, U Second) {
        this->First = First;
        this->Second = Second;
    }
    T first() const {return First;}
    U second() const {return Second;}
};

template <class U>
class StringValuePair : public Pair<string, U> {
public:
    StringValuePair (string First, U Second) : Pair(First, Second) {}

};

int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;

    return 0;
}

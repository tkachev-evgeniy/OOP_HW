#include <iostream>
#include <exception>



template <typename T>
T diiv(const T& t1, const T& t2) {
    if (t2==0) throw "Division by zero!";
    return t1/t2;
}

int main()
{
    try {
        int a = 5;
        int b = 0;
        int c = diiv(a,b);
        std::cout << c << std::endl;
    }
    catch(const char* exc) {
        std::cout <<"Exception caught: " << exc << std::endl;
    }
}

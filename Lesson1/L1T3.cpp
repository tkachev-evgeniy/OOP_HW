#include <iostream>

using namespace std;
 const int SIZE = 10;

class Stack {
private:
    int a[SIZE];
    int n;
public:
    Stack() {
        for (int i = 0; i<SIZE; i++) {
            a[i]=0;
        }
        n =0;
    }

    void reset () {
        for (int i = 0; i<SIZE; i++) {
            a[i]=0;
        }
        n=0;
    }

    bool push (int b) {
        if (n>SIZE-1) {
            cout << "Sorry, I'm stuffed!" << endl;
            return false;
        }
        else {
            a[n]=b;
            n=n+1;
            cout << "Gulp!" << endl;
            return true;
        }
    }

    bool pop() {
        if (n>0) {
            a[n-1]=0;
            n=n-1;
            cout <<"Vurp!" << endl;
            return true;
        }
        else {
            cout << "Sorry, I'm empty!"<< endl;
            return false;
        }

    }

    void print() {
        cout << "( ";
        for (int i=0;i<n;i++) {
            cout << a[i] <<" ";
        }
        cout << ")" << endl;
    }
};


int main()
{
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    //Check overflow and underflow
    stack.reset();
    stack.pop();
    stack.reset();
    for (int i=0; i<SIZE+1; i++) {
       stack.push(i);
    }


    return 0;
}



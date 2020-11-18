#include <iostream>
#include <string>

using namespace std;

class myendll {
    //как я понял в класс можно ничего не писать.
    //Попробовал через друженственную функцию, тоже работает.
    //Но какой смысл, если нам не нужен доступ к каким то полям.
};

ostream& operator << (ostream& out, const myendll& e) {
    out <<"\n" <<"\n";
    return out;
}

//Или можно так.
class myendll2 {

private:
    string manip;
public:
    myendll2() : manip("\n\n") {}
    friend ostream& operator << (ostream& out, const myendll2& e);
};

ostream& operator << (ostream& out, const myendll2& e) {
    out << e.manip;
    return out;
}
//Наверняка можно как-то еще, например можно прикрутить параметр. 

myendll endll;
myendll2 endll2;

int main()
{

cout<<"A"<<endll<<"B"<<endll2<<"C"<<endl;



cout << "Enter integer" << endl;

int output = 0;
int flag=1;

while (flag) {
    flag=0;
    string input;

    getline(cin,input);

    for (int i = 0; i < input.size(); ++i) {
        flag+=input.empty();
        flag+=!(isdigit(input[i]));
    }
    if (flag) cout<<"Input is invalid, please try again"<<endl;
    else output = stoi(input);
}

cout << endl;
cout << " You have entered " << output;


    return 0;
}


#include <iostream>
#include <string>

using namespace std;

class myRobotException {
protected:
    int X;
    int Y;
    char Key;
public:
    myRobotException(int x, int y, char key) : X(x), Y(y), Key(key) {}
    void preprint() const { cout << "Robot exception thrown @ X: " <<X <<" Y: " << Y <<", subtype: "; }
    virtual void print() const =0;
};

class IllegalCommand : public myRobotException {
public:
    IllegalCommand(int x, int y, char key) : myRobotException(x,y,key) {}
    virtual void print() const {
        preprint();
        cout << "IllegalCommand. " << '"' << Key << '"' << " is not a valid key " << endl;
    }
};

class OffTheField : public myRobotException {
private:
    string Direction;
public:
    OffTheField(int x, int y, char key, string direction) : myRobotException(x,y,key), Direction(direction) {}
    virtual void print() const {
        preprint();
        cout << "OffTheField, while trying to move " << Direction << ". Movement intialized with " << '"' << Key << '"' << " key." << endl;
    }
};

class Robot {
private:
    int X;
    int Y;
public:
    Robot() : X(0), Y(0) {}

    void print() const { cout << "X = " << X << " Y = " << Y << endl; }

    bool move(const char &key) {
        bool ans = 1;
        switch (key) {
        case 'W':
        case 'w':
            if (Y+1>9) throw OffTheField(X,Y,key,"up");
            ++Y;
            break;
        case 'A':
        case 'a':
            if (X-1<0) throw OffTheField(X,Y,key,"left");
            --X;
            break;
        case 'S':
        case 's':
            if (Y-1<0) throw OffTheField(X,Y,key,"down");
            --Y;
            break;
        case 'D':
        case 'd':
            if (X+1>9) throw OffTheField(X,Y,key,"right");
            ++X;
            break;
        case 'X':
        case 'x':
            ans = 0;
            break;
        default:
            throw IllegalCommand(X,Y, key);
            break;
        }
        return ans;
    }
};

int main()
{
    Robot aRobot;
    bool flag = 1;
    cout << "You have a robot, and a 10x10 field. You can move your robot up, down, left or rigth with \"WASD\" keys. Press \"X\" to stop." << endl;
    while (flag) {
        aRobot.print();
        char input;
        cin>>input;
        try {
            flag = aRobot.move(input);
        }
        catch(myRobotException &ex) {
            ex.print();
        }
    }
}

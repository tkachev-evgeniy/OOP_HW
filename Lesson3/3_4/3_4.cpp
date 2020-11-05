#include <iostream>

using namespace std;

enum suits{ CLUBS, SPADES, HEARTS, DIAMONDS};
enum ranks{ ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN , KING};

class Card {
protected:

    ranks rank;
    suits suit;
    bool facedown;
public:
    void flip() {facedown=!facedown;}
    int getRank() const {return rank;}
    int getValue() const {return rank<10?rank+1:10;}
    Card(ranks rank, suits suit) {
        this->rank = rank;
        this->suit = suit;
        facedown=false;
    }


};

int main()
{
    Card A(KING, DIAMONDS);
    cout<< A.getRank() << endl;
    cout << A.getValue() <<endl;
}

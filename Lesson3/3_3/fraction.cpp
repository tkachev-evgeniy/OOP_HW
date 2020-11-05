#include <iostream>
#include <numeric>
#include "fraction.h"


void Fraction::print() const {
    std::cout << numerator << "/" << denominator << std::endl;
}

void Fraction::reduce() {
   int g = std::gcd(numerator,denominator);
    if (g>1) {
        numerator/=g;
        denominator/=g;
    }

    if (denominator<0) {
        numerator*=-1;
        denominator*=-1;
    }

}

void Fraction::setND(int numerator, int denominator) {
        if (denominator==0) {
            std::cout << "Denominator can't be zero. Denominator set to 1 instead" << std::endl;
            denominator = 1;
        }
        this->numerator = numerator;
        this->denominator = denominator;
}

Fraction::Fraction() {
    setND(1,1);
    reduce();
}

Fraction::Fraction(int numerator, int denominator) {
    setND(numerator, denominator);
    reduce();
}

 const Fraction  Fraction::operator - () const {
    return Fraction(this->numerator*-1,this->denominator);
}


const Fraction operator + (const Fraction &a, const Fraction &b) { return Fraction(a.numerator*b.denominator+b.numerator*a.denominator, a.denominator*b.denominator);
}
// Будем рисовать операторы максимально используя уже созданные операторы. Интересно насколько такой подход замедляет программу?
// Наверное если в классе происходит динамическое выделение памяти лучше этим не злоупотреблять.

const Fraction operator + (int a, const Fraction &b) { return (Fraction(a,1)+b); }
const Fraction operator + (const Fraction &a, int b) { return (a+Fraction(b,1)); }

const Fraction operator - (const Fraction &a, const Fraction &b) { return (-b+a); }
const Fraction operator - (const Fraction& a, int b) { return a-Fraction(b,1);}
const Fraction operator - (int a, const Fraction& b) { return Fraction(a,1)-b;}

const Fraction operator * (const Fraction& a, const Fraction& b) { return Fraction(a.numerator*b.numerator,a.denominator*b.denominator);}
const Fraction operator * (const Fraction& a, int b) {return a*Fraction(b,1);}
const Fraction operator * (int a , const Fraction& b) {return Fraction(a,1)*b;}

const Fraction operator / (const Fraction& a, const Fraction& b) {return Fraction(a.numerator*b.denominator,a.denominator*b.numerator);}
const Fraction operator / (const Fraction& a, int b) {return a/Fraction(b,1);}
const Fraction operator / (int a, const Fraction& b) {return Fraction(a,1)/b;}

bool operator == (const Fraction &a, const Fraction &b) {return a.numerator*b.denominator==b.numerator*a.denominator;}
bool operator == (const Fraction& a, int b) {return a==Fraction(b,1);}
bool operator ==(int a, const Fraction& b) {return Fraction(a,1)==b;}

bool operator !=(const Fraction& a, const Fraction& b) {return !(a==b);}
bool operator !=(const Fraction& a, int b) {return !(a==b);}
bool operator !=(int a, const Fraction& b) {return !(a==b);}

bool operator < (const Fraction& a, const Fraction& b) {return a.numerator*b.denominator<b.numerator*a.denominator;}
bool operator < (const Fraction& a, int b) {return a<Fraction(b,1);}
bool operator < (int a, const Fraction& b) {return Fraction(a,1)<b;}

bool operator <= (const Fraction& a, const Fraction& b) {return a.numerator*b.denominator<=b.numerator*a.denominator;}
bool operator <= (const Fraction& a, int b) {return a<=Fraction(b,1);}
bool operator <= (int a, const Fraction& b) { return Fraction(a,1)<=b;}

bool operator > (const Fraction& a, const Fraction& b) {return !(a<=b);}
bool operator > (const Fraction& a, int b) {return !(a<=b);}
bool operator > (int a, const Fraction& b) {return !(a<=b);}

bool operator >= (const Fraction& a,const Fraction& b) {return !(a<b);}
bool operator >= (const Fraction& a, int b) {return !(a<b);}
bool operator >= (int a, const Fraction b) {return !(a<b);}


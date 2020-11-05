#ifndef FRACTION_H
#define FRACTION_H


class Fraction {
private:
    int numerator;
    int denominator;
public:
    void setND(int numerator, int denominator);
    Fraction();
    Fraction(int numerator, int denominator);
    void reduce();
    void print() const;

   const Fraction operator -() const;

    //Решив делать бинарные операторы через дружественные функции я добавил много строчек.
    // Зато пользователю сразу видно какие функции предусмотренны классом и не надо лезть.
    friend const Fraction operator + (const Fraction &a, int b);
    friend const Fraction operator + (const Fraction &a, const Fraction &b);
    friend const Fraction operator + (int a, const Fraction &b);

    friend const Fraction operator - (const Fraction &a, int b);
    friend const Fraction operator - (const Fraction &a, const Fraction &c);
    friend const Fraction operator - (int a, const Fraction &b);

    friend const Fraction operator * (const Fraction &a, int b);
    friend const Fraction operator * (const Fraction &a, const Fraction &c);
    friend const Fraction operator * (int a, const Fraction &b);

    friend const Fraction operator / (const Fraction &a, int b);
    friend const Fraction operator / (const Fraction &a, const Fraction &c);
    friend const Fraction operator / (int a, const Fraction &b);

    friend bool operator < (const Fraction &a, int b);
    friend bool operator < (const Fraction &a, const Fraction &c);
    friend bool operator < (int a, const Fraction &b);

    friend bool operator <= (const Fraction &a, int b);
    friend bool operator <= (const Fraction &a, const Fraction &c);
    friend bool operator <= (int a, const Fraction &b);


    friend bool operator == (const Fraction &a, int b);
    friend bool operator == (const Fraction &a, const Fraction &c);
    friend bool operator == (int a, const Fraction &b);

    friend bool operator >= (const Fraction &a, int b);
    friend bool operator >= (const Fraction &a, const Fraction &c);
    friend bool operator >= (int a, const Fraction &b);

    friend bool operator > (const Fraction &a, int b);
    friend bool operator > (const Fraction &a, const Fraction &c);
    friend bool operator > (int a, const Fraction &b);

    friend bool operator != (const Fraction &a, int b);
    friend bool operator != (const Fraction &a, const Fraction &c);
    friend bool operator != (int a, const Fraction &b);
};

#endif // FRACTION_H

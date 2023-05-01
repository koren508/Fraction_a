#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
using namespace std;
namespace ariel{}


class Fraction{

    private:
    int up;
    int down;

    public:
    Fraction(int a , int b);
    Fraction();
    Fraction(float number);
    Fraction operator +(const Fraction& f) const;
    Fraction operator +(double d) const;
    Fraction operator -(const Fraction& f) const;
    Fraction operator -(int num) const;
    Fraction operator *(const Fraction& f) const;
    friend Fraction operator *(double d , const Fraction& f);
    Fraction operator /(const Fraction& f) const;
    bool operator ==(const Fraction& f) const;
    bool operator !=(const Fraction& f) const;
    bool operator >(const Fraction& f) const;
    bool operator >(double d) const;
    bool operator >=(const Fraction& f) const;
    bool operator <(const Fraction& f) const;
    bool operator <=(const Fraction& f) const;
    Fraction operator ++();
    Fraction operator ++(int dummy);
    Fraction operator --();
    Fraction operator --(int dummy);
    friend ostream& operator <<(ostream& output , const Fraction& f);
    friend istream& operator >>(istream& input , Fraction& f);
    int find_gcd(int a , int b) const;
    int find_lcm(int a , int b) const;
    Fraction reduce(const Fraction& f) const;
    int get_up();
    int get_down();
};

#endif
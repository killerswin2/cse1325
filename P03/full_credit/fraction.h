#ifndef __FRACTION_H
#define __FRACTION_H

#include <iostream>
#include <string>

class Fraction{
    private:
        int _numerator;
        int _denominator;
        void reduce();
        bool compare(Fraction& rhs);
    public:
        Fraction(int numerator = 0, int denominator = 1);
        Fraction operator-();
        Fraction operator+(Fraction& rhs);
        Fraction operator-(Fraction& rhs);
        Fraction operator*(Fraction& rhs);
        Fraction operator/(Fraction& rhs);
        friend std::ostream& operator<<(std::ostream& ost, Fraction& m);
        friend std::istream& operator>>(std::istream& ist, Fraction& m);
        friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
};
    

#endif
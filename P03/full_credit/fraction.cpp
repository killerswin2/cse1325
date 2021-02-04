#include "fraction.h"


void Fraction::reduce();
bool Fraction::compare(Fraction& rhs);
Fraction::Fraction(int numerator = 0, int denominator = 1): _numerator{numerator}, _demoninator{demoninator}{
        if (denominator == 0){
            throw std::runtime_error{"Denominator is Zero"}
        }
}

//Fraction Fraction::operator-();
Fraction Fraction::operator+(Fraction& rhs){
    int tempNum = (*this._numerator * rhs._demoninator) + (*this._demoninator * rhs._numerator);
    int tempDem = *this._demoninator * rhs._demoninator;
    Fraction ret{tempNum,tempDem};
    return ret;
}
Fraction Fraction::operator-(Fraction& rhs){}
Fraction Fraction::operator*(Fraction& rhs){}
Fraction Fraction::operator/(Fraction& rhs){}

friend ostream& operator<<(ostream& ost, Fraction& m){}
friend istream& operator>>(istream& ist, Fraction& m){}
friend bool operator!=(const Fraction& lhs, const Fraction& rhs){}
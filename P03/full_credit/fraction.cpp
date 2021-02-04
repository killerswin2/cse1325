#include "fraction.h"


void Fraction::reduce();
bool Fraction::compare(Fraction& rhs);
Fraction::Fraction(int numerator = 0, int denominator = 1): _numerator{numerator}, _denominator{denominator}{
        if (denominator == 0){
            throw std::runtime_error{"Denominator is Zero"}
        }
}

//Fraction Fraction::operator-();

/*This function will add both fractions
Formula used is a/b + c/d = (ad+bc)/bd */
Fraction Fraction::operator+(Fraction& rhs){
    /*Numerator*/
    int tempNum = (*this._numerator * rhs._denominator) + (*this->_denominator * rhs._numerator);   
    /*Denominator*/
    int tempDem = *this._denominator * rhs._denominator;                                           
    Fraction retFraction{tempNum,tempDem};
    return retFraction;
}
Fraction Fraction::operator-(Fraction& rhs){

}
Fraction Fraction::operator*(Fraction& rhs){}
Fraction Fraction::operator/(Fraction& rhs){}

friend ostream& operator<<(ostream& ost, Fraction& m){}
friend istream& operator>>(istream& ist, Fraction& m){}
friend bool operator!=(const Fraction& lhs, const Fraction& rhs){}
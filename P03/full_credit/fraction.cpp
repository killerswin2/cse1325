#include "fraction.h"


void Fraction::reduce();
bool Fraction::compare(Fraction& rhs);
Fraction::Fraction(int numerator = 0, int denominator = 1): _numerator{numerator}, _denominator{denominator}{
        if (denominator == 0){
            throw std::runtime_error{"Denominator is Zero"}
        }
}

//Fraction Fraction::operator-();

/*
This operator will add both fractions
Formula used is a/b + c/d = (ad+bc)/bd 
*/
Fraction Fraction::operator+(Fraction& rhs){
    /*Numerator: ad+bc*/
    int tempNum = (*this._numerator * rhs._denominator) + (*this._denominator * rhs._numerator);   
    /*Denominator: bd*/
    int tempDen = *this._denominator * rhs._denominator;                                           
    Fraction retFraction{tempNum,tempDen};
    return retFraction;
}

/*
This operator will sub both fractions
Formula used is a/b - c/d = (ad-cb)/bd
*/
Fraction Fraction::operator-(Fraction& rhs){
    /*Numerator: ad-cb*/
    int tempNum = (*this._numerator * rhs._denominator) - (*this._denominator * rhs._numerator);
    /*Denominator: bd*/
    int tempDen = *this._denominator * rhs._denominator;
    Fraction retFraction{tempNum,tempDen};
    return retFraction;
}

/*
This operator will muti both fractions
Formula used is a/b * c/d = ac/bd
*/
Fraction Fraction::operator*(Fraction& rhs){
    /*Numerator: ac*/
    int tempNum = *this._numerator * rhs._numerator;
    /*Denominator: bd*/
    int tempDen = *this._denominator * rhs._denominator;
    Fraction retFraction{tempNum,tempDen};
    return retFraction;
}
/*
This operator will divide both fractions
Formula used is a/b / c/d = ad/bc
*/
Fraction Fraction::operator/(Fraction& rhs){
    /*Numerator: ad*/
    int tempNum = *this._numerator * rhs._denominator;
    /*Denominator: bc*/
    int tempDen = *this._denominator * rhs._numerator;
    Fraction retFraction{tempNum,tempDen};
    return retFraction;
}

friend ostream& operator<<(ostream& ost, Fraction& m){}
friend istream& operator>>(istream& ist, Fraction& m){}
friend bool operator!=(const Fraction& lhs, const Fraction& rhs){}
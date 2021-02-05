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

/*
This operator will print out the fraction with a / in the middle
it converts the numerator first into a string and then does the same to
the denominator
*/
friend ostream& operator<<(std::ostream& ost, Fraction& m){
    ost << std::to_string(m._numerator) << "/" << std::to_string(m._denominator);
    return ost;    
}

/*
This operator will take user input and place the numerator in the numerator
then it places the denominator and places the denominator.
The operator work by finding the / and then substrings before and after to get 
the values of both numerator and denominator. Later the substrings are converted 
to integers with stoi.
*/
friend istream& operator>>(std::istream& ist, Fraction& m){
    std::string temp;
    ist >> temp;
    int postion = temp.find("/");
    m._numerator = std::stoi(temp.substr(postion-1,1));
    m._denominator = std::stoi(temp.substr(postion+1,1));
    return ist;

}
/*
This operator will determine if the two fractions are not equal
and return 1 if both are not equal and 0 if they are both equal.
operator uses a if statement to make comparison 
*/
friend bool operator!=(const Fraction& lhs, const Fraction& rhs){
    if(lhs._numerator != rhs._numerator || lhs._denominator != rhs._numerator){
        return 1;
    }else{
        return 0;
    }
}
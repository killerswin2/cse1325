#include "fraction.h"

int gcd(int temp1, int temp2){
    if(temp2 == 0){
        return temp1;
    }else{
        gcd(temp2, temp1 % temp2);
    }
    return 1;
}


void Fraction::reduce(){
    if(this->_denominator < 0){
        this->_denominator = -this->_denominator;
        this->_numerator = -this->_numerator;
    }
   int common = gcd(this->_denominator, this->_numerator);
   this->_denominator = this->_denominator / common;
   this->_numerator = this->_numerator / common;
}


Fraction::Fraction(int numerator, int denominator): _numerator{numerator}, _denominator{denominator}{
        if (denominator == 0){
            throw std::runtime_error{"Denominator is Zero"};
        }
}

//Fraction Fraction::operator-();

/*
This operator will add both fractions
Formula used is a/b + c/d = (ad+bc)/bd 
*/
Fraction Fraction::operator+(Fraction& rhs){
    /*Numerator: ad+bc*/
    int tempNum = (this->_numerator * rhs._denominator) + (this->_denominator * rhs._numerator);   
    /*Denominator: bd*/
    int tempDen = this->_denominator * rhs._denominator;                                           
    Fraction retFraction{tempNum,tempDen};
    return retFraction;
}

/*
This operator will sub both fractions
Formula used is a/b - c/d = (ad-cb)/bd
*/
Fraction Fraction::operator-(Fraction& rhs){
    /*Numerator: ad-cb*/
    int tempNum = (this->_numerator * rhs._denominator) - (this->_denominator * rhs._numerator);
    /*Denominator: bd*/
    int tempDen = this->_denominator * rhs._denominator;
    Fraction retFraction{tempNum,tempDen};
    return retFraction;
}

/*
This operator will muti both fractions
Formula used is a/b * c/d = ac/bd
*/
Fraction Fraction::operator*(Fraction& rhs){
    /*Numerator: ac*/
    int tempNum = this->_numerator * rhs._numerator;
    /*Denominator: bd*/
    int tempDen = this->_denominator * rhs._denominator;
    Fraction retFraction{tempNum,tempDen};
    return retFraction;
}

/*
This operator will divide both fractions
Formula used is a/b / c/d = ad/bc
*/
Fraction Fraction::operator/(Fraction& rhs){
    /*Numerator: ad*/
    int tempNum = this->_numerator * rhs._denominator;
    /*Denominator: bc*/
    int tempDen = this->_denominator * rhs._numerator;
    Fraction retFraction{tempNum,tempDen};
    return retFraction;
}

/*
This operator will print out the fraction with a / in the middle
it converts the numerator first into a string and then does the same to
the denominator
*/
std::ostream& operator<<(std::ostream& ost, Fraction& m){
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
std::istream& operator>>(std::istream& ist, Fraction& m){
    std::string temp;
    ist >> temp;
    int postion = temp.find("/");
    if(postion == -1 ){
        std::runtime_error{"Read a bad Fraction"};
    }
    m._numerator = std::stoi(temp.substr(postion-1,1));
    m._denominator = std::stoi(temp.substr(postion+1,1));
    return ist;

}
/*
This operator will determine if the two fractions are not equal
and return 1 if both are not equal and 0 if they are both equal.
operator uses a if statement to make comparison 
*/
bool operator!=(const Fraction& lhs, const Fraction& rhs){
    if(lhs._numerator != rhs._numerator || lhs._denominator != rhs._numerator){
        return 1;
    }else{
        return 0;
    }
}
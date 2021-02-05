#include "fraction.h"


int main(){
    Fraction one;
    Fraction two;
    std::cout << "Enter a Fraction in the form of a/b\n";
    std::cin >> one;
    std::cout << "Enter another Fraction in the form of a/b\n";
    std::cin >> two;
    Fraction inverse1, inverse2, sum, diff, product, quotient;
	inverse1 = -one;
	inverse2 = -two;
    sum = one + two;
    diff = one - two;
    product = one * two;
    quotient = one / two;
    std::cout << "The inverses: "<< inverse1 <<" ,"<< inverse2 <<std::endl;
    std::cout << "The sum: " << sum <<std::endl;
    std::cout << "The difference: " << diff <<std::endl;
    std::cout << "the product: " << product <<std::endl;
    std::cout << "the quotient: " << quotient <<std::endl;
    
    return 0;
}

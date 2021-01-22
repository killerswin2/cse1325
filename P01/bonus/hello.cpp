/*
	Author: Ellis Nielsen
*/

#include <iostream>

int main(void){
	std::cout << "Please Enter your name: ";
	std::string names;
	std::getline(std::cin, names);
	std::string line = "Hello";
	std::cout << line << " " << names << "!"<<std::endl;
	return 0;
}

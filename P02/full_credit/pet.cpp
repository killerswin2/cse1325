#include "pet.h"


Pet::Pet(std::string name, double age, Type type): _name{name}, _age{age}, _type{type}{}

std::string Pet::to_string(){
	std::string toReturn;
	std::string Animal;
	try{
	switch(_type){
		case Type::CAT: Animal = "Cat"; break;
		case Type::DOG: Animal = "Dog" ; break;
		case Type::COW: Animal = "Cow"; break;
		case Type::CHICKEN:Animal = "Chicken"; break;
		default: Animal = "UNKNOWN"; throw "UNKNOWN TYPE"; break;
	}
	}catch(std::string &str){
		std::cerr << "Unknown Type, defaulting to Cat" << std::endl;
		Animal = "Cat";
	}
	toReturn = _name + " is a " + Animal + " aged " + std::to_string(_age);
	return toReturn;
	
}

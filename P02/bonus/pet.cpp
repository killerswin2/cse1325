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
double Pet::human_years(){
	double pet_life;
	try{
	switch(_type){
		case Type::CAT: pet_life = 12.0; break;
		case Type::DOG: pet_life = 10.0 ; break;
		case Type::COW: pet_life = 15.0; break;
		case Type::CHICKEN: pet_life = 5.0; break;
		default:  pet_life = 1; throw "UNKNOWN TYPE"; break;
	}
	}catch(std::string &str){
		std::cerr << "Unknown Type, defaulting to Cat" << std::endl;
		pet_life = 12.0;
	}
	return _age * 80.0 / pet_life;
}
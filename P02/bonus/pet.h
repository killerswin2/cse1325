#ifndef __PET_H
#define __PET_H

#include <iostream>
#include <vector>

enum class Type{
	CAT, DOG, COW, CHICKEN
};


class Pet{
	private:
		std::string _name;
		double _age;
		Type _type;
	public:
		Pet(std::string name, double age, Type type);
		double human_years();
		std::string to_string();
};

#endif
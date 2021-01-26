#include "pet.h"

int main(void){
	std::vector<Pet> pets;
	
	pets.push_back(Pet{"Dave", 25.5, Type::CAT});
	pets.push_back(Pet{"Dave1", 25.5, Type::DOG});
	pets.push_back(Pet{"Dave2", 25.5, Type::COW});
	pets.push_back(Pet{"Dave3", 25.5, Type::CHICKEN});
	
	for(int i = 0; i< pets.size(); i++){
		std::cout << pets[i].to_string() <<" or " <<std::to_string(pets[i].human_years()) <<" in human-equivalent years" << std::endl;
	}
	return 0;
} 
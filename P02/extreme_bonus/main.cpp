#include "pet.h"

bool isgreaterbool(Pet temp1, Pet temp2){
	return temp1.human_years() < temp2.human_years();
}

int main(void){
	std::vector<Pet> pets;
	
	pets.push_back(Pet{"Dave", 35.6, Type::CAT});
	pets.push_back(Pet{"Dave1", 45.63, Type::DOG});
	pets.push_back(Pet{"Dave2", 15.2, Type::COW});
	pets.push_back(Pet{"Dave3", 85.3, Type::CHICKEN});
	
	std::sort(pets.begin(), pets.end(), isgreaterbool);
	
	for(int i = 0; i< pets.size(); i++){
		std::cout << pets[i].to_string() <<" or " <<std::to_string(pets[i].human_years()) <<" in human-equivalent years" << std::endl;
	}
	return 0;
} 
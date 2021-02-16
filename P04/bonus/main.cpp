#include "deck.h"
#include <map>

int main(void){
	Deck deck;
	deck.add_card("A style of programming focused on the use of classes and class hierarchies","Object_Oriented Programming");
	deck.add_card("Reuse and extension of fields and method implementations from another class","Interitence");
	deck.add_card("Bundling data and code into a restricted container","Encapsulation");
	deck.add_card("Specifying a general interface while hiding implementation details","Abstraction","A type of art");
	deck.add_card( "A data type that can typically be handled directly by the underlying hardware","Primitive type", "what works well in assembly");
	deck.add_card("A data type consisting of a fixed set of constant values called enumerators","Enumerated type");
	deck.add_card("A template encapsulating data and code that manipulates it","Class", "a different struct that private");
	deck.add_card("An encapsulated bundle of data and code","Instance");
	deck.add_card("An instance of a class containing a set of encapsulated data and associated methods","Object");
	deck.add_card("A block of memory associated with a symbolic name that contains an object instance or aprimitive data value","Variable");
	deck.add_card("A short string representing a mathematical, logical, or machine control action","Operator", "We overload these a lot");
	deck.add_card("A class member variable","Attribute");
	deck.add_card("A special class member that creates and initializes an object from the class","Constructor");
	deck.add_false_answer("Destructor");
	deck.add_false_answer("Method");
	std::cout << "Type the number of the your guess (-1 to quit)" << std::endl;
	try{
		std::vector<std::string> option = deck.options();
		/*
			print out the options	
		*/
		for(int i = 0; i< option.size()-2; ++i){
			for(int i = 0; i < option.size(); ++i){
				std::cout << std::to_string(i)<< ") " << option[i] << std::endl;
			}
			/*
				get a card to guess and then take user guess
			*/
			Card* question_temp = deck.deal();
			std::cout << *(question_temp) <<": " ;
			int guess;
			std::cin >> guess;
			if(guess == -1){
				return 0;
			}
			/*
				find out if the guess was correct.
			*/
			std::cout << question_temp->attempt(option[guess]) << "\n"<< std::endl;	
		}
		
	}catch(std::runtime_error& e){
		std::cerr << e.what() << std::endl;
	}

	
	
	return 0;
}

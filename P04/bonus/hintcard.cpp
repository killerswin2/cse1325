#include "hintcard.h"

Hintcard::Hintcard(std::string question, std::string answer, std::string hint):Card{question, answer},_hint{hint}{}

std::string Hintcard::attempt(std::string response){
	if(_answer.compare(response)!= 0){
		return "X - incorrect. HINT: " + _hint + "\n";
	}else{
		return "Correct Answer\n";
	}
}

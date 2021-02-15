#include "card.h"

Card::Card(std::string question, std::string answer):_question{question},_answer{answer}{}



std::string Card:: attempt(std::string response){
	if(_answer.compare(response)==0){
		return "Correct Answer";
	}else{
		return "Incorrect Answer";
	}
}



std::ostream& operator<<(std::ostream& ost, Card& m){
	ost << m._question;
	return ost;
}

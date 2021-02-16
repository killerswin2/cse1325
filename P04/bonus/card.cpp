#include "card.h"
/*
	take a question and answer in string
	initialization list to inintalize the class
*/
Card::Card(std::string question, std::string answer):_question{question},_answer{answer}{}


/*
	take a string
	compare the string to answer
	if same return correct
	else return not correct
*/
std::string Card:: attempt(std::string response){
	if(_answer.compare(response)==0){
		return "Correct Answer";
	}else{
		return "X - Correct answer was " + _answer + "\n";
	}
}


/*
	streaming out operator
	get a stream and a card
	insert into ostream the string of card	
*/
std::ostream& operator<<(std::ostream& ost, Card& m){
	ost << m._question;
	return ost;
}

#include "deck.h"
#include "hintcard.h"
/*
	take a question and an answer and use 
	a card to hold that info
	add 1 to the next card
	and shuffle the cards
*/
void Deck::add_card(std::string question, std::string answer, std::string hint){
	if(hint.compare("")==0){
		_cards.push_back(new Card{question,answer});
	}else{
		_cards.push_back(new Hintcard{question,answer,hint});
	}
	_options.push_back(answer);
	++_next_card;
	unsigned int seed = std::time(NULL);
	shuffle(_cards.begin(), _cards.end(), std::default_random_engine(seed));
}
/*
	add a false answer to the vector of 
	_options
*/
void Deck::add_false_answer(std::string false_answer){
	_options.push_back(false_answer);
}

/*
	return the vector of strings
	that contain the options to
	select
*/
std::vector<std::string> Deck::options(){
	return _options;
}

/*
	if the next card is 1 return the last card
	if the card is 0 throw error
	else subtract one from next card
	and return _cards
*/
Card* Deck::deal(){
	static int temp  = _cards.size();

	if(temp - _next_card  ==  1){
		return (_cards[0]);
	}
	else if(_next_card == 0){
		throw std::runtime_error{"No Cards Created"};
	}
	else{
		--temp;
		return (_cards[temp]);
	}
}

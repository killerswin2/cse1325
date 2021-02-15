#include "deck.h"

void Deck::add_card(std::string question, std::string answer){
	_cards.push_back(Card{question,answer});
	_options.push_back(answer);
	++_next_card;
	unsigned int seed = time(NULL);
	shuffle(_cards.begin(), _cards.end(), std::default_random_engine(seed));
}

void Deck::add_false_answer(std::string false_answer){
	_options.push_back(false_answer);
}

std::vector<std::string> Deck::options(){
	return _options;
}

Card& Deck::deal(){
	if(_next_card == 1){
		return _cards[0];
	}
	else if(_next_card == 0){
		throw std::runtime_error{"No Cards Created"};
	}
	else{
		--_next_card;
		return _cards[_next_card];
	}
}

#ifndef __DECK_H
#define __DECK_H
#include "card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class Deck{
	private:
		std::vector<Card> _cards;
		std::vector<std::string> _options;
		int _next_card = 0;
	public:
		void add_card(std::string question, std::string answer);
		void add_false_answer(std::string false_answer);
		std::vector<std::string> options();
		Card& deal();
	
};


#endif

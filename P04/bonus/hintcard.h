#ifndef __HINT_H
#define __HINT_H
#include "card.h"

class Hintcard : public Card{
	private:
		std::string _hint;
	public:
		Hintcard(std::string question, std::string answer, std::string hint);
		std::string attempt(std::string response) override;
		
};



#endif

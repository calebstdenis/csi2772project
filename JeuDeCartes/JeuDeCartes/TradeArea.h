#include "Card.h"
#include <string>
#include "CardFactory.h"
#include <istream>

class TradeArea
{
public:
	TradeArea(std::istream, CardFactory*);
	TradeArea& operator+= (Card*);
	bool legal(Card*);
	Card* trade(std::string);
	int numCards();
	void operator<< (int);
};
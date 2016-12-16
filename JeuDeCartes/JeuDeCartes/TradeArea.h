#include "Card.h"
#include <string>
#include "CardFactory.h"
#include <istream>
#include <list>

class TradeArea
{
	list<Card*> cards;
public:
	TradeArea() = default;
	TradeArea(istream&, CardFactory*);
	TradeArea& operator+=(Card*);
	bool legal(Card*) const;
	Card* trade(string);
	int numCards();
	friend std::ostream& operator<<(ostream&, const TradeArea &);
};
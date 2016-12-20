#include "Card.h"
#include <string>
#include "CardFactory.h"
#include <istream>
#include <list>

class TradeArea
{
	list<Card*> cards;
	friend class Table; //so that table can manipulate the list of cards directly. used for Table::clearTradeArea()
public:
	TradeArea() = default;
	TradeArea(istream&, CardFactory*);
	TradeArea& operator+=(Card*);
	bool legal(Card*) const;
	Card* trade(string);
	int numCards();
	friend std::ostream& operator<<(ostream&, const TradeArea &);
};
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table
{
	Player p1, p2;
	Deck deck;
	DiscardPile discardPile;
	TradeArea tradeArea;
public:
	Table();//voir dans le document pour le constructeur
	bool win(std::String);
	void printHand(bool);

	void operator<< (int);
};
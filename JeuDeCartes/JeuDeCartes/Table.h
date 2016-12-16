#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include <array>
#include <iterator>

class Table
{
	std::array<Player*,2> players;
	int currentPlayer = 0;
	Deck *deck;
	DiscardPile *discardPile;
	TradeArea *tradeArea;
public:
	Table(std::istream&, CardFactory*);
	Table(Player*, Player*, Deck*, DiscardPile*, TradeArea*); //for constructor injection

	Player& currentTurn() const; //returns the player whose turn it is
	Player& endTurn(); //ends a player's turn and returns the next player whose turn it is.
	bool win(std::string&) const;

	void print(std::ostream&) const;
	friend std::ostream& operator<<(ostream&, const Table&);

};
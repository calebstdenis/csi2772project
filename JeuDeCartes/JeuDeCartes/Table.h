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

	void clearTradeArea(); //adds unwanted TradeArea cards to the Discard Pile

	//Getters
	Player* getPlayer1() const;
	Player* getPlayer2() const;
	Deck* getDeck() const;
	DiscardPile* getDiscardPile() const;
	TradeArea* getTradeArea() const;

	void print(std::ostream&) const;
	friend std::ostream& operator<<(ostream&, const Table&);

};
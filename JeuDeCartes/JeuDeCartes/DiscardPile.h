#include <iostream>

class Card;

class DiscardPile {
public:
	DiscardPile& operator+=(Card*);
	Card* pickUp();
	Card* top();
	friend std::ostream& operator<<(std::ostream&, const Deck&);
};
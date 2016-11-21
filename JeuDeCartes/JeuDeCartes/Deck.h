#include <iostream>
#include "Card.h"

class Deck {
public: 
	Deck(const std::istream&, CardFactory*);
	Card* draw();
	friend std::ostream& operator<<(std::ostream&, const Deck&);
};
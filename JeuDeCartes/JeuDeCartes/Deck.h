#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <vector>

class CardFactory;

class Deck : private std::vector<Card*> {
	friend class CardFactory;
public: 
	Deck();
	Deck(const std::istream&, CardFactory*);
	Card* draw();
	friend std::ostream& operator<<(std::ostream&, const Deck&);
};
#endif
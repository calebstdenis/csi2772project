#ifndef DECK_H
#define DECK_H
#include <vector>

class Card;
class CardFactory;

//Derivation is private to prevent insertion of Cards. Useful members are made public with "using" however.
class Deck : protected std::vector<Card*> {
	friend class CardFactory;
	Deck(); //no point in defining a destructor as Deck does not maintain any special state on the Heap. Vector does not have a virtual desctructor besides.
	
public: 
	Card* draw();
	Deck(const Deck&);
	Deck(std::istream&, CardFactory*);
	friend std::ostream& operator<<(std::ostream&, const Deck&);
	using vector<Card*>::size;
	using vector<Card*>::begin;
	using vector<Card*>::end;
	using vector<Card*>::empty;
};
#endif
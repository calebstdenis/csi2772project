#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <vector>

class CardFactory;

//Derivation is private to prevent insertion of Cards. Useful members are made public with "using" however.
class Deck : private std::vector<Card*> {
	friend class CardFactory;
	Deck(); //no point in defining a destructor as Deck does not maintain any special state on the Heap. Vector does not have a virtual desctructor besides.
	template <class C> inline Deck& addCards(int n) { //Used by CardFactory to create cards while staying DRY
		for (int i = 0; i < n; i++) 
			push_back(new C); 
		return *this;
	}
public: 
	Deck(const std::istream&, CardFactory*);
	Card* draw();
	friend std::ostream& operator<<(std::ostream&, const Deck&);
	using vector<Card*>::size;
	using vector<Card*>::begin;
	using vector<Card*>::end;
	using vector<Card*>::empty;
};
#endif
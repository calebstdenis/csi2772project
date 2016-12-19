#include <iostream>
#include <vector>

class Card;

class DiscardPile {
	std::vector<Card*> pile;
public:
	DiscardPile() = default;
	DiscardPile(istream&, CardFactory*);
	DiscardPile& operator+=(Card*);
	Card* pickUp();
	Card* top()const;
	void print(std::ostream&);
	friend std::ostream& operator<<(std::ostream&, const DiscardPile&);
};
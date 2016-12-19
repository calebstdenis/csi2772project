#include <iostream>
#include <vector>

class Card;
class CardFactory;

class DiscardPile {
	std::vector<Card*> pile;
public:
	DiscardPile() = default;
	DiscardPile(std::istream&, CardFactory*);
	DiscardPile& operator+=(Card*);
	Card* pickUp();
	Card* top()const;
	void print(std::ostream&);
	friend std::ostream& operator<<(std::ostream&, const DiscardPile&);
};
#include <iostream>
#include <deque>

class Card;
class CardFactory;

class Hand
{
	std::deque<Card*> main;
public:
	Hand() = default;
	Hand(std::istream&, CardFactory*);
	Hand& operator+=(Card*);
	Card* play();
	Card* top();
	Card* operator[](int);
	friend std::ostream& operator<<(std::ostream&, const Hand&);
};
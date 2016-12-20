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
	Card* top() const;
	Card* operator[](int);
	friend bool operator==(const Hand&, const Hand&); //for testing
	friend std::ostream& operator<<(std::ostream&, const Hand&);
};
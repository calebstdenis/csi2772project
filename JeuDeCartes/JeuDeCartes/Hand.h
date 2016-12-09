#include <iostream>
#include <deque>

class Card;
class CardFactory;

class Hand
{
	std::deque<Card*> main;
public:
	Hand(const std::istream&, CardFactory*);
	Hand& operator+=(Card*);
	Card* play();
	Card* top();
	Card* operator[](int);
};
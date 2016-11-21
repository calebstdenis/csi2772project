#include <iostream>

class Card;
class CardFactory;

class Hand
{
public:
	Hand(const std::istream&, CardFactory*);
	Hand& operator+=(Card*);
	Card* play();
	Card* top();
	Card* operator[](int);
};
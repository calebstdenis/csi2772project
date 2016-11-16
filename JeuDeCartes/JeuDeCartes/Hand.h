#include "Card.h"
#include "CardFactory.h"

class Hand
{
public:
	Hand(const istream&, CardFactory*);
	Hand& operator+=(Card*);
	Card* play();
	Card* top();
	Card* operator[](int);
};
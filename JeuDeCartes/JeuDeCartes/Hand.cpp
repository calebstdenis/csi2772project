#include "Hand.h"
#include "Card.h"
#include "CardFactory.h"

Hand::Hand(std::istream& is, CardFactory* cf)
{
	char c;
	while (is >> c) {
		main.push_back(cf->loadCard(c));
	}
}

Hand& Hand::operator+= (Card* c)
{
	main.push_back(c);
	return *this;
}

Card* Hand::play()
{
	Card* c = main.front();
	main.pop_front();
	return c;
}

Card* Hand::top() const
{
	return main.front();
}

Card* Hand::operator[] (const int i)
{
	Card* c = main[i];
	main.erase(main.begin() + i);
	return c;
}

bool operator==(const Hand &h1, const Hand &h2)
{
	return std::equal(h1.main.cbegin(), h1.main.cend(), h2.main.cbegin(), h2.main.cend(), Card::areSameType);
}

std::ostream& operator<<(std::ostream& os, const Hand& hand)
{
	for (Card* card : hand.main) {
		os << card << " ";
	}
	return os;
}

bool Hand::isEmpty()
{
	return main.empty();
}

int Hand::getLength()
{
	return main.size();
}
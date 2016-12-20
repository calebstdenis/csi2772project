#include "DiscardPile.h"
#include "Card.h"
#include "CardFactory.h"

DiscardPile::DiscardPile(istream& is, CardFactory* cf)
{
	char c;
	while (is >> c) {
		pile.push_back(cf->loadCard(c));
	}
}

size_t DiscardPile::size() const {
	return pile.size();
}

Card* DiscardPile::top() const
{
	return pile.back();
}
Card* DiscardPile::pickUp()
{
	Card * c = pile.back();
	pile.pop_back();
	return c;
}
DiscardPile& DiscardPile::operator+=(Card* c)
{
	pile.push_back(c);
	return *this;
}
std::ostream& operator<< (std::ostream & os, const DiscardPile & discardPile)
{
	if (discardPile.size() == 0) {
		return os;
	}
	else {
		return os << discardPile.top()->getName()[0];
	}
}

void DiscardPile::print(std::ostream & os)
{
	for (Card* card : pile) {
		os << card->getName()[0];
	}
}
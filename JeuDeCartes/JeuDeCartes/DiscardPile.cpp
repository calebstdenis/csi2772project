#include "DiscardPile.h"
#include "Card.h"

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
	os.write(discardPile.top()->getName().c_str, discardPile.top()->getName().size);//je ne suis pas s�r que c'est ca qu'il faut faire
	return os;
}

/*void DiscardPile::print(std::ostream & os)
{

}*/
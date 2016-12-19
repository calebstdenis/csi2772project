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

Card* Hand::top()
{
	return main.front();
}

Card* Hand::operator[] (const int i)
{
	Card* c = main[i];
	int size = main.size();//la taille vas changer lorsqu'on enleve l'indice donc on stoque la bone valeur dans un int temporaire
	for (int j = 0; j < size; j++)
	{
		if (j == i)
			main.pop_front();
		else
			main.push_back(play());
	}
	return c;
}

std::ostream& operator<<(std::ostream& os, const Hand& hand)
{
	for (Card* card : hand.main) {
		os << card << " ";
	}
	return os;
}
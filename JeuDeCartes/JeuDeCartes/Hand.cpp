#include "Hand.h"
#include "Card.h"

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
	
	return c;
}
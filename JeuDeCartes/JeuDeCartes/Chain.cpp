#include <iterator>
#include <algorithm>
#include "Chain.h"
#include "GameExceptions.h"

template <class T>
Chain<T>::Chain(std::istream& in, CardFactory* cf)
{
}

template <class T>
int Chain<T>::sell()
{
	int num = elements.size();
	for (int i = 4; i > 0; i--)
	{
		if (num > t.getCardPerCoins(i))
			return i;
	}
	return 0;
}

template <class T>
Chain<T>& Chain<T>::operator+= (Card* c)
{
	if (c->getName() == T::name)
	{
		elements.pushBack((T*)c);
	}
	else
		throw IllegalTypeException();
	return *this;
}

template <class T>
std::ostream& operator<<(std::ostream & os, const Chain<T> & chaine)
{
	os.write((char*)(T.name),T.name.size());
	for (int i = 0; i < elements.size(); i++)
	{
		os.put(*((char*)T.getName()));//la première lettre
	}
	return *this;
}
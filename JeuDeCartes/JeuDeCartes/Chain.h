#include <vector>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Card.h"
#include "CardFactory.h"
#include "GameExceptions.h"
#include "IOUtil.h"

template <class T> class Chain {
	std::vector<T*> elements;
public: 
	Chain() = default;
	Chain(std::istream&, CardFactory*);
	int size();
	int sell();
	Chain<T>& operator+=(Card*);
	template <class T> friend std::ostream& operator<<(std::ostream&, const Chain<T>&);
};

template <class T>
Chain<T>::Chain(std::istream& in, CardFactory* cf)
{
	char c;
	while (in >> c) {
		if (c != T::name[0]) {
			throw corrupt_game_file_exception("A card was found in a chain whose gemstone type did not belong.");
		}
		Card* card = cf->loadCard(c);
		elements.push_back((T*)card);
	}
}

template <class T>
int Chain<T>::sell()
{
	for (int i = 4; i > 0; i--)
	{
		if (size() >= elements[0]->getCardsPerCoin(i))
			return i;
	}
	return 0;
}

template <class T>
int Chain<T>::size() {
	return elements.size();
}

template <class T>
Chain<T>& Chain<T>::operator+= (Card* c) throw IllegalTypeException
{
	if (c->getName() == T::name)
	{
		elements.push_back((T*)c);
	}
	else
		throw new IllegalTypeException();
	return *this;
}

template <class T>
std::ostream& operator<<(std::ostream & os, const Chain<T> &chaine)
{
	os << T::name << std::setw(IOUtil::COLUMN_WIDTH);
	for (int i = 0; i < chaine.elements.size(); i++)
	{
		//os << T::name[0];
		T.print();
	}
	return os;
}
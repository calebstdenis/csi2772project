#include <vector>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Card.h"
#include "CardFactory.h"
#include "GameExceptions.h"
#include "IOUtil.h"

/*
Commentaires au correcteur:
	Dans les instructions, on nous demande de surdéfinir << pour le patron Chain. 
	Cependant, si on fait ceci on ne peut pas l'utiliser commme fonction virtuelle dans Chain_Base,
	puisque l'opérateur d'insertion devrait être implanté comme fonction amie. 
	Ainsi, on fait comme pour Card au lieu: une fonction membre print() et un operateur ami << dans la superclasse.
*/

class Chain_Base {
	virtual size_t size() const = 0;
	virtual int sell() const = 0;
	virtual Chain_Base& operator+=(Card*) = 0;
	virtual void print(ostream&) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Chain_Base& cb) { cb.print(os); }
};

template <class T> class Chain : public Chain_Base {
	std::vector<T*> elements;
public: 
	Chain() = default;
	Chain(std::istream&, CardFactory*);
	size_t size() const override final;
	int sell() const override final;
	Chain<T>& operator+=(Card*) override final;
	void print(ostream&) const override final;
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
int Chain<T>::sell() const
{
	for (int i = 4; i > 0; i--)
	{
		if (size() >= elements[0]->getCardsPerCoin(i))
			return i;
	}
	return 0;
}

template <class T>
size_t Chain<T>::size() const {
	return elements.size();
}

template <class T>
Chain<T>& Chain<T>::operator+= (Card* c) {
	if (c->getName() == T::name)
	{
		elements.push_back((T*)c);
	}
	else
		throw IllegalTypeException();
	return *this;
}

template<class T>
inline void Chain<T>::print(ostream & os) const {
	os << T::name << std::setw(IOUtil::COLUMN_WIDTH);
	for (int i = 0; i < chaine.elements.size(); i++)
	{
		os << chaine.elements[i] << " ";
	}
}
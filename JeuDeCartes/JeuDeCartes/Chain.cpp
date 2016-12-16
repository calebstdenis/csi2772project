#include "Chain.h"
#include "illegalType.h"



template <typename T: public Card> Chain<T>::Chain(const std::istream& is, CardFactory* cf)
{

}

Chain<T>::Chain()
{
}

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

Chain<T>& Chain<T>::operator+= (Card* c)
{
	if (c->getName() == T.getName())
	{
		elements.pushBack((T*)c);
	}
	else
		throw illegalType;
	return &this;
}

std::ostream& operator<<(std::ostream & os, const Chain<T> & chaine)
{
	os.write((char*)(T.name),T.name.size());
	for (int i = 0; i < elements.size(); i++)
	{
		os.put(*((char*)T.getName()));//la première lettre
	}
	return *this;
}
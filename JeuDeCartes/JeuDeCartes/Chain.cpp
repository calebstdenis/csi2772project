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
	throw illegalType;
	return &this;
}

Chain<T>& Chain<T>::operator+= (T* c)
{
	elements.pushBack(c);
	return &this;
}

std::ostream& std::ostream::operator<< (std::ostream & os, const Chain & chaine)//je ne suis pas certain de l'implémentation mais je crois que c'est proche de ça
{
	cout << T.getName() << " ";
	for (int i = 0; i < elements.size(); i++)
	{
		cout << &((char*)T.getName()) << " ";//la première lettre
	}
}
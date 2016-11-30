#include <iostream>
#include <vector>
#include "CardFactory.h"

template <typename T: public Card> class Chain {
	std::vector<T*> elements;
public: 
	Chain();
	Chain(const std::istream&, CardFactory*);
	int sell();
	Chain<T>& operator+=(Card*);
	Chain<T>& operator+=(T*);//polymorphisme pour trouver les erreurs
	friend std::ostream& operator<<(std::ostream&, const Chain&);
};
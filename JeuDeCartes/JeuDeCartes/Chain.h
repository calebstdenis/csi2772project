#include <iostream>
#include <vector>
#include "CardFactory.h"

template <typename T> class Chain {
	std::vector<T*> elements;
public: 
	Chain() = default;
	Chain(std::istream&, CardFactory*);
	int sell();
	Chain<T>& operator+=(Card*);
	friend std::ostream& operator<<(std::ostream&, const Chain<T>&);
};
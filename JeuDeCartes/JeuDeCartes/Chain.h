#include <iostream>

template <typename T> class Chain {
public: 
	Chain(const std::istream&, CardFactory*);
	int sell();
	Chain<T>& operator+=(Card*);
	friend std::ostream& operator<<(std::ostream&, const Chain&);
};
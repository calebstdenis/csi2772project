#include <string>;
#include "Chain.h"

class Player
{
	std::string nom;
	Chain[3] chain;
public:
	Player(std::string);
	Player(const std::istream &, bool);
	std::string getName();
	int getNumCoins();
	Player & operator+=(int);
	int getMaxNumChains();
	int getNumChains();
	Chain & operator[] (int);
	void buyThirdChain();
	void printHand(std::ostream&, bool);
	void operator<<(int);
};

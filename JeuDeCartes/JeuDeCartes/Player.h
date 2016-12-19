#include <string>
#include <vector>
#include "Chain.h"
#include "Hand.h"
#include "CardFactory.h"


class Player
{
	std::string nom;
	int numCoins;
	int maxNumChain;
	std::vector<Chain<Card*>> chain;
	Hand main;
public:
	Player(std::string&);
	Player(std::istream &, CardFactory*);
	std::string getName() const;
	int getNumCoins() const;
	Player & operator+=(int);
	int getMaxNumChains();
	int getNumChains();
	Chain<Card*> & operator[] (int);
	void buyThirdChain();
	void printHand(std::ostream&, bool);
	friend std::ostream& operator<<(std::ostream&, const Player &);
	// ajouté la méthode print pour enregistrer
	void print(std::ostream&);
};

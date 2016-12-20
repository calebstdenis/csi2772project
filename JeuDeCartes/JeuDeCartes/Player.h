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
	std::vector<Chain_Base*> chain;
	Hand main;
public:
	Player(std::string&);
	Player(std::istream &, CardFactory*);
	std::string getName() const;
	int getNumCoins() const;
	Player & operator+=(int);
	int getMaxNumChains();
	int getNumChains();
	Chain_Base & operator[] (int);
	void buyThirdChain();
	void printHand(std::ostream&, bool);
	friend std::ostream& operator<<(std::ostream&, const Player &);
	void print(std::ostream&); // ajout� la m�thode print pour enregistrer
	void draw(Card*);
	//ajout� play pour jouer une carte
	void play();
	void play(Card*);
};

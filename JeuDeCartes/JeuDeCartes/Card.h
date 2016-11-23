#ifndef CARD_H
#define CARD_H
#include <string>
#
using namespace std;

struct Card {
	virtual int getCardsPerCoin(int) const = 0;
	virtual string getName() const = 0;
};

class Quartz : Card { 
	int cardsPerCoin[4];
public: 
	Quartz();
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};
class Hematite : Card {
	int cardsPerCoin[4];
public:
	Hematite();
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};
class Obsidian : public Card {};
class Malachite : public Card {};
class Turquoise : public Card {};
class Ruby : public Card {};
class Amethyst : public Card {};
class Emerald : public Card {};


/* 
std::string Quartz::name = "Quartz";
std::string Quartz::name = "Hermatite";
std::string Quartz::name = "Obsidian";
std::string Quartz::name = "Malachite";
std::string Quartz::name = "Turquoise";
std::string Quartz::name = "Ruby";
std::string Quartz::name = "Amethyst";
std::string Quartz::name = "Emerald";
*/
#endif
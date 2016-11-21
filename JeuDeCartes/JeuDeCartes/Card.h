#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
public:
	virtual int getCardsPerPoint(int);
	virtual std::string getName();
};

class Quartz : public Card {};
class Hermatite : public Card {};
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
#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card {
public: 
	virtual int getCardsPerCoin(int) const = 0;
	virtual string getName() const = 0;
};

class Quartz : Card { 
	static const string name;
	static const int cardsPerCoin[4];
public: 
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Hematite : Card {
	static const string name;
	static const int cardsPerCoin[4];
public:
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Obsidian : Card {
	static const string name;
	static const int cardsPerCoin[4];
public:
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Malachite : Card {
	static const string name;
	static const int cardsPerCoin[4];
public:
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Turquoise : Card {
	static const string name;
	static const int cardsPerCoin[4];
public:
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Turquoise : Card {
	static const string name;
	static const int cardsPerCoin[4];
public:
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Amethyst : Card {
	static const string name;
	static const int cardsPerCoin[4];
public:
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Ruby : Card {
	static const string name;
	static const int cardsPerCoin[4];
public:
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Emerald : Card {
	static const string name;
	static const int cardsPerCoin[4];
public:
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};
#endif
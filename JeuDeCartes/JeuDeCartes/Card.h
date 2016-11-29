#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card {
public: 
	Card() = default;
	Card(const Card&) = delete;
	Card& operator=(const Card&) = delete;

	virtual int getCardsPerCoin(int) const = 0;
	virtual string getName() const = 0;
};

class Quartz : public Card { 
	static const int cardsPerCoin[4];
public: 
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Hematite : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Obsidian : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Malachite : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Turquoise : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Amethyst : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Ruby : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};

class Emerald : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
};
#endif
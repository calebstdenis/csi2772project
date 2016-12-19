#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card {
public: 
	Card() = default; //no point in defining a destructor 
	Card(const Card&) = delete;
	Card& operator=(const Card&) = delete;

	//here we chose against overloading == to avoid confusing semantics. Cards should only be equal if they are the exact same card, not two cards of the same type. 
	bool isSameTypeAs(Card* card) { return this->getName() == card->getName();  }
	
	virtual int getCardsPerCoin(int) const = 0;
	virtual string getName() const = 0;
	virtual void print(ostream&) const = 0;

	friend ostream& operator<<(std::ostream&, const Card*);
};

class Quartz : public Card { 
	static const int cardsPerCoin[4];
public: 
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class Hematite : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class Obsidian : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class Malachite : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class Turquoise : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class Amethyst : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class Ruby : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class Emerald : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};
#endif
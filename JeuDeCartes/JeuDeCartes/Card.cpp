#include "Card.h"
#include <stdexcept>
#include <climits>

using namespace std;

ostream& operator<<(std::ostream& o, const Card* c) {
	c->print(o);
	return o;
}

int getCardsPerCoin(int numCoins, const int(&cardsPerCoin)[4]) {
	if (numCoins <= 0 || numCoins > 4) {
		throw invalid_argument("The number of coins must be a positive integer.");
	}
	return cardsPerCoin[numCoins - 1];
}


const string Quartz::name = "Quartz";
const string Hematite::name = "Hematite";
const string Obsidian::name = "Obsidian";
const string Malachite::name = "Malachite";
const string Turquoise::name = "Turquoise";
const string Ruby::name = "Ruby";
const string Amethyst::name = "Amethyst";
const string Emerald::name = "Emerald";

const int Quartz::cardsPerCoin[4] = { 4, 6, 8, 10 };
const int Hematite::cardsPerCoin[4] = { 3, 6, 8, 9 };
const int Obsidian::cardsPerCoin[4] = { 3, 5, 7, 8 };
const int Malachite::cardsPerCoin[4] = { 3, 5, 6, 7 };
const int Turquoise::cardsPerCoin[4] = { 2, 4, 6, 7 };
const int Ruby::cardsPerCoin[4] = { 2, 4, 5, 6 };
const int Amethyst::cardsPerCoin[4] = { 2, 3, 4, 5 };
const int Emerald::cardsPerCoin[4] = { NULL, 2, 3, INT_MAX };

string Quartz::getName() const { return name; }
string Hematite::getName() const { return name; }
string Obsidian::getName() const { return name; }
string Malachite::getName() const { return name; }
string Turquoise::getName() const { return name; }
string Ruby::getName() const { return name; }
string Amethyst::getName() const { return name; }
string Emerald::getName() const { return name; }

void Quartz::print(ostream& os) const { os << name[0]; }
void Hematite::print(ostream& os) const { os << name[0]; }
void Obsidian::print(ostream& os) const { os << name[0]; }
void Malachite::print(ostream& os) const { os << name[0]; }
void Turquoise::print(ostream& os) const { os << name[0]; }
void Ruby::print(ostream& os) const { os << name[0]; }
void Amethyst::print(ostream& os) const { os << name[0]; }
void Emerald::print(ostream& os) const { os << name[0]; }

int Quartz::getCardsPerCoin(int numCoins) const {
	return ::getCardsPerCoin(numCoins, cardsPerCoin);
}

int Hematite::getCardsPerCoin(int numCoins) const {
	return ::getCardsPerCoin(numCoins, cardsPerCoin);
}

int Obsidian::getCardsPerCoin(int numCoins) const {
	return ::getCardsPerCoin(numCoins, cardsPerCoin);
}

int Malachite::getCardsPerCoin(int numCoins) const {
	return ::getCardsPerCoin(numCoins, cardsPerCoin);
}

int Turquoise::getCardsPerCoin(int numCoins) const {
	return ::getCardsPerCoin(numCoins, cardsPerCoin);
}

int Ruby::getCardsPerCoin(int numCoins) const {
	return ::getCardsPerCoin(numCoins, cardsPerCoin);
}

int Amethyst::getCardsPerCoin(int numCoins) const {
	return ::getCardsPerCoin(numCoins, cardsPerCoin);
}

int Emerald::getCardsPerCoin(int numCoins) const {
	int val = ::getCardsPerCoin(numCoins, cardsPerCoin);
	if (val == NULL) {
		string msg = "An emerald chain sells for more than " + to_string(numCoins) + " coins.";
		throw invalid_argument(msg);
	}
	return val;
}




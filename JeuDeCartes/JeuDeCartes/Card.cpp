#include "Card.h"
#include <stdexcept>
using namespace std;

int getCardsPerCoinHelper(int numCoins, const int(&cardsPerCoin)[4]) {
	if (numCoins <= 0 || numCoins > 4) {
		throw invalid_argument("The number of coins must be a positive integer.");
	}
	return cardsPerCoin[numCoins - 1];
}

string Quartz::getName() const { return "Quartz"; }
string Hematite::getName() const { return "Hematite"; }

Quartz::Quartz() : cardsPerCoin{ 4, 6, 8, 10 } {}
Hematite::Hematite() : cardsPerCoin{ 3, 6, 8, 9 } {}

int Quartz::getCardsPerCoin(int numCoins) const {
	return getCardsPerCoinHelper(numCoins, cardsPerCoin);
}
int Hematite::getCardsPerCoin(int numCoins) const {
	return getCardsPerCoinHelper(numCoins, cardsPerCoin);
}



#include <algorithm>
#include <random>
#include <string>
#include "Card.h"
#include "CardFactory.h"

using namespace std;

CardFactory::CardFactory() : deck(Deck()) {
	const int numCardsInDeck = 104;
	deck.reserve(numCardsInDeck);
	deck.addCards<Quartz>(20)
		.addCards<Hematite>(18)
		.addCards<Obsidian>(16)
		.addCards<Malachite>(14)
		.addCards<Turquoise>(12)
		.addCards<Ruby>(10)
		.addCards<Amethyst>(8)
		.addCards<Emerald>(6);
}

CardFactory* CardFactory::instance = nullptr;

CardFactory* CardFactory::getFactory() {
		if (instance == nullptr) {
		instance = new CardFactory;
	}
	return instance;
}

Deck CardFactory::getDeck() {
	std::shuffle(deck.begin(), deck.end(), default_random_engine());
	return deck;
}



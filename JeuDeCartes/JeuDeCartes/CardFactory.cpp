#include <algorithm>
#include <chrono>
#include <functional>
#include <random>
#include <string>
#include "Card.h"
#include "CardFactory.h"
#include "Deck.h"

using namespace std;

//Second item in pair: A lambda for creating a Card of a given type
//First item in pair: The number of cards of a given type (i.e. the number of times the lambda will be called). 
const pair<int, function<Card*()>> cardsInDeck[] = {
	{ 20, [] { return new Quartz; }},
	{ 18, [] { return new Hematite; }},
	{ 16, [] { return new Obsidian; }}, 
	{ 14, [] { return new Malachite; }},
	{ 12, [] { return new Turquoise; }},
	{ 10, [] { return new Ruby; }},
	{ 8, [] { return new Amethyst; }},
	{ 6, [] { return new Emerald; }}
};

const int numCardsInDeck = 104;

CardFactory* CardFactory::instance = nullptr;

CardFactory::CardFactory() : deck(Deck()) {
	deck.reserve(numCardsInDeck);
	//Create the corresponding number of cards for each gem
	for (auto cardsPerGem : cardsInDeck) {
		for (int i = 0; i < cardsPerGem.first; i++) {
			deck.push_back(cardsPerGem.second());
		}
	}
}

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



#include "Card.h"
#include "Deck.h"

Deck::Deck() : vector<Card*>() {}

Card* Deck::draw() {
	Card* card = back();
	pop_back();
	return card;
}
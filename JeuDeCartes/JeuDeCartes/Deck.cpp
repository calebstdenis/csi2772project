#include "Card.h"
#include "CardFactory.h"
#include "Deck.h"
#include "GameExceptions.h"

Deck::Deck() : vector<Card*>() {}

Deck::Deck(const Deck& d) : vector<Card*>(d) {}

Card* Deck::draw() {
	Card* card = back();
	pop_back();
	return card;
}

//Get the line with the Deck cards and read from that line as a stream.
Deck::Deck(std::istream& in, CardFactory* cf) : vector<Card*>() {
	char c;
	while (in >> c) {
		push_back(cf->loadCard(c));
	}
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
	for (Card* card : deck) {
		out << card->getName()[0];
	}
	return out;
}
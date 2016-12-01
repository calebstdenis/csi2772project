#include <sstream>
#include "Card.h"
#include "CardFactory.h"
#include "Deck.h"
#include "Exceptions.h"

Deck::Deck() : vector<Card*>() {}

Card* Deck::draw() {
	Card* card = back();
	pop_back();
	return card;
}

//Get the line with the Deck cards and read from that line as a stream.
Deck::Deck(std::istream& in, CardFactory* cf) : vector<Card*>() {
	string line;
	std::getline(in, line);
	istringstream lineStream(line);
	char c;

	while (lineStream >> c) {
		push_back(cf->initCard(c));
	}
	if (!lineStream.eof()) {
		throw corrupt_game_file();
	}
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
	for (Card* card : deck) {
		out << card->getName()[0];
	}
	out << endl;
	return out;
}
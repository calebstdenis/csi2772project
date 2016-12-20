#include "Table.h"
#include "GameExceptions.h"
#include <sstream>

Table::Table(Player *p1, Player *p2, Deck *deck, DiscardPile *discardPile, TradeArea *tradeArea)
	:players{p1, p2}, deck(deck), discardPile(discardPile), tradeArea(tradeArea) {}

Player& Table::currentTurn() const
{
	return *players[currentPlayer];
}

Player& Table::endTurn()
{
	currentPlayer = ++currentPlayer % players.size();
	return *players[currentPlayer];
}

bool Table::win(std::string& winner) const
{
	const Player p1 = *players[0], p2 = *players[1];

	if (!deck->empty()) {
		return false;
	}
	if (p1.getNumCoins() == p2.getNumCoins()) {
		winner = p1.getName() + "and" + p2.getName();
	}
	else {
		winner = p1.getNumCoins() > p2.getNumCoins() ? p1.getName() : p2.getName();
	}
	return true;
}

void Table::print(std::ostream &out) const
{
	out << *players[0] << endl;
	out << *players[1] << endl;
	out << *deck << endl;
	out << *discardPile << endl;
	out << *tradeArea << endl;
	out << currentPlayer << endl;
}

//Helper for constructing a table from the save file.
template <class T> T* constructSingleLineComponent(std::istream& in, CardFactory * cf) {
	string line;
	std::getline(in, line);
	istringstream lineStream(line);

	if (!in || !lineStream) {
		throw corrupt_game_file_exception();
	}

	T *result = new T(lineStream, cf);

	//Input failed before reaching the end of the line
	if (!in.eof()) {
		throw corrupt_game_file_exception();
	}

	return result;
}

/*
All save-file constructors except Player expect a single-line stream containing only their component.
This imposes certain special conditions on the Player constructor in relation to the read marker of the stream.
This introduces implicit coupling between this constructor and the Player constructor. However, other save-constructors are pretty well decoupled from one another.
*/
Table::Table(std::istream& in, CardFactory * cf)
{
	players = { new Player(in, cf), new Player(in, cf) };
	deck = constructSingleLineComponent<Deck>(in, cf);
	discardPile = constructSingleLineComponent<DiscardPile>(in, cf);
	tradeArea = constructSingleLineComponent<TradeArea>(in, cf);
	if (!in >> currentPlayer) {
		throw corrupt_game_file_exception();
	}
}

std::ostream & operator<<(ostream &out, const Table &table)
{
	out << endl;
	out << "---------" << endl;
	out << "TABLE" << endl;
	out << "---------" << endl;
	for (int i = 0; i < table.players.size(); i++) {
		out << "JOUEUR " << i;
		if (table.currentPlayer == i) {
			out << i << "(Ton Tour):";
		}
		out << endl;
		out << *table.players[i] << endl;
	}
	out << "DISCARD PILE:" << endl;
	out << *table.discardPile << endl;
	out << endl << "TRADE AREA:" << endl;
	out << *table.tradeArea << endl;
	return out;
}

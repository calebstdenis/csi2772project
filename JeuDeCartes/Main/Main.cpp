#include "Table.h"
#include <iostream>

int main()
{
	//singleton CardFactory
	CardFactory* instance;
	Player* p1 = new Player(getString("nom de Joueur 1"));
	Player* p2 = new Player(getString("nom de Joueur 2"));
	Deck* deck = &instance->getDeck();
	DiscardPile* discardPile = new DiscardPile();
	TradeArea* tradeArea = new TradeArea();
	if (query("charger la partie sauvegardée?"))
	{
		p1 = new Player(cin, instance);
		p2 = new Player(cin, instance);
		deck = new Deck(cin, instance);
		discardPile = new DiscardPile(cin, instance);
		tradeArea = new TradeArea(cin, instance);
	}
	//créer table
	Table table(p1,p2,deck,discardPile,tradeArea);
	
	while (!deck->empty())
	{

	}

    return 0;
}

bool query(char* text)
{
	cout << text << endl << "o/n";
	char c;
	do
	cin >> c;
	while (c == 'o' || c == 'n');
	if (c == 'o')
		return true;
	return false;
}

std::string getString(char* text)
{
	cout << text << endl;
	std::string s;
	cin >> s;
	return s;
}


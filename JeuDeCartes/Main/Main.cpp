#include "Table.h"
#include <iostream>

int main()
{
	//singleton CardFactory
	CardFactory* instance;
	//autres variables
	Player* p1 = new Player(getString("nom de Joueur 1"));
	Player* p2 = new Player(getString("nom de Joueur 2"));
	Deck* deck = &instance->getDeck();
	DiscardPile* discardPile = new DiscardPile();
	TradeArea* tradeArea = new TradeArea();
	bool d�but = true;
	if (query("charger la partie sauvegard�e?"))
	{
		p1 = new Player(cin, instance);
		p2 = new Player(cin, instance);
		deck = new Deck(cin, instance);
		discardPile = new DiscardPile(cin, instance);
		tradeArea = new TradeArea(cin, instance);
		d�but = false;
	}
	//cr�er table
	Table table(p1,p2,deck,discardPile,tradeArea);

	if (d�but)//piger 5 cartes au d�but de la partie
	{ 
		for (int i = 0; i<5;i++)
		p1->draw(deck->draw());
		p2->draw(deck->draw());
	}
	Player* current = p2;
	while (!deck->empty())
	{
		if (current == p1)//changer de joueur � chaque ronde
		{
			current = p2;
			cout << "C'est le tour du joueur 2 /n";
		}
		else
		{
			current = p1;
			cout << "C'est le tour du joueur 1 /n";
		}
		//afficher la table pour le joueur
		cout << table;//je ne crois pas que ca affiche la bonne chose
		//piger la premi�re carte de deck
		current->draw(deck->draw());
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


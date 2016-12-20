#include "Table.h"
#include <iostream>

int main()
{
	//singleton CardFactory
	CardFactory* instance;
	//autres variables
	Player* p1 = new Player(getString("nom de Joueur 1"));
	Player* p2 = new Player(getString("nom de Joueur 2"));
	Deck* deck = &(instance->getDeck());
	DiscardPile* discardPile = new DiscardPile();
	TradeArea* tradeArea = new TradeArea();
	bool début = true;
	if (query("charger la partie sauvegardée?"))
	{
		p1 = new Player(cin, instance);
		p2 = new Player(cin, instance);
		deck = new Deck(cin, instance);
		discardPile = new DiscardPile(cin, instance);
		tradeArea = new TradeArea(cin, instance);
		début = false;
	}
	//créer table
	Table table(p1,p2,deck,discardPile,tradeArea);

	if (début)//piger 5 cartes au début de la partie
	{ 
		for (int i = 0; i<5;i++)
		p1->draw(deck->draw());
		p2->draw(deck->draw());
	}
	Player* current;
	while (!deck->empty())
	{
		current = &table.currentTurn();

		//afficher la table pour le joueur
		cout << table;//je ne crois pas que ca affiche la bonne chose
		//piger la première carte de deck
		current->draw(deck->draw());
		//ajoute des cartes de tradeArea à ses propres chaines avant de jouer
		while (query("ajouter des cartes placés en échange?") && tradeArea->numCards() > 0)
		{
			//afficher les cartes de tradeArea
			cout << tradeArea;//pas sûr que c'est la bonne chose mais si ca affiche juste les cartes c'est bon
			try
			{
				current->play(tradeArea->trade(getString("Entrez le nom de la carte a ajouter à vos chaînes:"))); //méthode a implémenter pour ajouter une carte dans une chaine
			}
			catch (game_logic_exception e)
			{
				e.what();
			}
		}
		//vider tradeArea
		//méthode non implémenté pour faire cela

		do
		{
			//jouer la première carte de la main du joueur
			cout << "placer la première carte /n";
			current->printHand(cout, true);//imprimer la première carte
			//jouer la carte
			current->play();
			cout << "voici votre main a présent";
			current->printHand(cout, false);
		} while (query("jouer une autre carte?"));//ajouter la condition de la main du joueur qui est vide
		
		table.endTurn();
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


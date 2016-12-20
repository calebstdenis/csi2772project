#include "Table.h"
#include <iostream>

bool query(char* text)
{
	cout << text << endl << "o/n" << endl;
	char c;
	do
		cin >> c;
	while (c != 'o' && c != 'n');
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


int main()
{
	//singleton CardFactory
	CardFactory* instance = CardFactory::getFactory();
	//autres variables
	Player* p1 = new Player(getString("nom de Joueur 1"));
	Player* p2 = new Player(getString("nom de Joueur 2"));
	Deck* deck = new Deck(instance->getDeck());
	DiscardPile* discardPile = new DiscardPile();
	TradeArea* tradeArea = new TradeArea();
	bool début = true;
	if (query("charger la partie sauvegardee?"))
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
		for (int i = 0; i < 5; i++) {
			p1->draw(deck->draw());
			p2->draw(deck->draw());
		}
	}
	Player* current;
	while (!deck->empty())
	{
		current = &table.currentTurn();

		//afficher la table pour le joueur
		cout << table;
		//ajoute des cartes de tradeArea à ses propres chaines avant de jouer
		while (query("ajouter des cartes places en echange?") && tradeArea->numCards() > 0)
		{
			//afficher les cartes de tradeArea
			cout << tradeArea;//pas sûr que c'est la bonne chose mais si ca affiche juste les cartes c'est bon
			try
			{
				current->play(tradeArea->trade(getString("Entrez le nom de la carte a ajouter a vos chaines:"))); 
			}
			catch (game_logic_exception e)
			{
				e.what();
			}
		}
		table.clearTradeArea();

		do
		{
			//jouer la première carte de la main du joueur
			cout << "placer la première carte" << endl;
			current->printHand(cout, true);//imprimer la première carte
			current->play();
			cout << "voici votre main a present" << endl;
			current->printHand(cout, false);
		} while (!(current->isHandEmpty()) && query("jouer une autre carte?"));

		//se débarasser d'une carte arbitraire
		cout << "choisir une carte par son numero (en commencant par 0 pour la première carte) pour s'en debarasser" << endl;
		current->printHand(cout, false);
		int num;
		cin >> num;
		*discardPile += current->removeIndex(num);

		//placer les 3 premières carts de deck dans tradeArea et placer les cartes de DiscardPile qui matchent dessus
		for (int i = 0; i<3; i++)
			*tradeArea += deck->draw();
		while (tradeArea->legal(discardPile->top()))
			*tradeArea += discardPile->pickUp();

		//le joueur pige deux cartes
		current->draw(deck->draw());
		current->draw(deck->draw());

		table.endTurn();
	}

    return 0;
}

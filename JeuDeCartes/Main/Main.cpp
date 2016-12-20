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
	Player* p1, *p2;
	Deck* deck;
	DiscardPile* discardPile;
	TradeArea* tradeArea; 

	bool loadFromSave = IOUtil::promptForInput<bool>("Charger la partie sauvegardee?");

	if (loadFromSave) {
		p1 = new Player(cin, instance);
		p2 = new Player(cin, instance);
		deck = new Deck(cin, instance);
		discardPile = new DiscardPile(cin, instance);
		tradeArea = new TradeArea(cin, instance);
	}
	else {
		string p1Name = IOUtil::promptForInput<string>("nom de Joueur 1");
		string p2Name = IOUtil::promptForInput<string>("nom de Joueur 2");
		p1 = new Player(p1Name);
		p2 = new Player(p2Name);
		deck = new Deck(instance->getDeck());
		discardPile = new DiscardPile();
		tradeArea = new TradeArea();

		for (int i = 0; i < 5; i++) {
			p1->draw(deck->draw());
			p2->draw(deck->draw());
		}
	}

	//créer table
	Table table(p1,p2,deck,discardPile,tradeArea);

	Player* current;
	while (!deck->empty())
	{
		current = &table.currentTurn();

		//afficher la table pour le joueur
		cout << table;
		//ajoute des cartes de tradeArea à ses propres chaines avant de jouer
		while (tradeArea->numCards() > 0 && IOUtil::promptForInput<bool>("prendre des cartes places en echange?"))
		{
			//afficher les cartes de tradeArea
			cout << tradeArea << endl;
			try
			{
				string cardName = IOUtil::promptForInput<string>("Entrez le nom complet de la carte a ajouter a vos chaines: ");
				current->play(tradeArea->trade(cardName)); 
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
			cout << "Vous jouez la carte superieure de votre main, qui est: ";
			current->printHand(cout, true); //imprimer la première carte
			current->play();
			cout << "Voici votre main a present: " << endl;
			current->printHand(cout, false);
		} while (!(current->isHandEmpty()) && IOUtil::promptForInput<bool>("jouer une autre carte?"));

		//se débarasser d'une carte arbitraire
		cout << "choisir une carte par son numero (en commencant par 0 pour la première carte) pour s'en debarasser" << endl;
		current->printHand(cout, false);

		int num;
		cin >> num;
		*discardPile += current->removeIndex(num);

		//placer les 3 premières carts de deck dans tradeArea et placer les cartes de DiscardPile qui matchent dessus
		for (int i = 0; i<3 && !deck->empty(); i++)
			*tradeArea += deck->draw();
		while (discardPile->size() != 0 && tradeArea->legal(discardPile->top()))
			*tradeArea += discardPile->pickUp();

		//le joueur pige deux cartes
		for (int i = 0; i < 2 && !deck->empty(); i++) {
			current->draw(deck->draw());
		}
		table.endTurn();
	}

    return 0;
}

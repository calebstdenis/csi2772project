#include "Table.h"
#include "GameExceptions.h"
#include <iostream>
#include <fstream>

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

	Table* table;

	bool loadFromSave = IOUtil::promptForInput<bool>("Charger la partie sauvegardee?");

	if (loadFromSave) {
		try {
			ifstream saveIn(IOUtil::SAVE_FILE);
			table = new Table(saveIn, instance);
		}
		catch (corrupt_game_file_exception e) {
			cout << "Le fichier de jeu est corrompu!" << endl;
			IOUtil::promptForInput<char>("Appuyez Enter pour quitter.");
			return 1;
		}
		p1 = table->getPlayer1();
		p2 = table->getPlayer2();
		deck = table->getDeck();
		discardPile = table->getDiscardPile();
		tradeArea = table->getTradeArea();
	}
	else {
		string p1Name = IOUtil::promptForInput<string>("nom de Joueur 1");
		string p2Name = IOUtil::promptForInput<string>("nom de Joueur 2");
		p1 = new Player(p1Name);
		p2 = new Player(p2Name);
		deck = new Deck(instance->getDeck());
		discardPile = new DiscardPile();
		tradeArea = new TradeArea();

		table = new Table(p1, p2, deck, discardPile, tradeArea);

		for (int i = 0; i < 5; i++) {
			p1->draw(deck->draw());
			p2->draw(deck->draw());
		}
	}

	Player* current;
	string winner;
	while (!table->win(winner))
	{
		if (IOUtil::promptForInput<bool>("Quitter et sauvegarder le jeu?")) {
			ofstream save(IOUtil::SAVE_FILE);
			table->print(save);
			return 0;
		}
		current = &table->currentTurn();

		//afficher la table pour le joueur
		cout << *table;
		//ajoute des cartes de tradeArea à ses propres chaines avant de jouer
		while (tradeArea->numCards() > 0 && IOUtil::promptForInput<bool>("prendre des cartes places en echange?"))
		{
			//afficher les cartes de tradeArea
			cout << tradeArea << endl;
			//afficher les piles du joueur
			cout << *current << endl;
			try
			{
				string cardName = IOUtil::promptForInput<string>("Entrez le nom complet de la carte a ajouter a vos chaines: ");
				current->play(tradeArea->trade(cardName)); 
			}
			catch (game_logic_exception e)
			{
				e.what();
				//return 1;//ne retourne rien ici ca finit le jeu
			}
		}
		table->clearTradeArea();

		do
		{
			//jouer la première carte de la main du joueur
			cout << "Vous jouez la carte superieure de votre main, qui est: ";
			current->printHand(cout, true); //imprimer la première carte
			current->play();
			//afficher les piles du joueur
			cout << *current << endl;
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
		table->endTurn();
	}
	cout << "Victoire " << winner << endl;
	IOUtil::promptForInput<char>("Appuyez Enter pour terminer la partie.");

    return 0;
}

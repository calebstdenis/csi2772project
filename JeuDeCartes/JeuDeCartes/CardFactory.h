class Deck;

class CardFactory
{
public:
	CardFactory();//créer toutes les cartes dans les bonnes proportions

	static CardFactory* getFactory();

	Deck getDeck();
};

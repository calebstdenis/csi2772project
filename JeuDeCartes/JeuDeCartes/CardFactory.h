#include "Deck.h"

class CardFactory
{
	static CardFactory *instance;
	Deck deck;
	CardFactory();//cr�er toutes les cartes dans les bonnes proportions
public:
	~CardFactory() = delete;
	CardFactory(const CardFactory&) = delete;
	CardFactory& operator=(const CardFactory&) = delete;

	static CardFactory* getFactory();

	Deck getDeck();
};

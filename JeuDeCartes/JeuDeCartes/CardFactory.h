#import "Deck.h"

class CardFactory
{
public:
	CardFactory();//cr�er toutes les cartes dans les bonnes proportions

	static CardFactory* getFactory();

	Deck getDeck();
};

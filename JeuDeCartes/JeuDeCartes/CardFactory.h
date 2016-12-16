#include <map>
#include "Deck.h"

/* All the cards of the game are created only once in the constructor.
* Pointers to these cards are kept in a Deck and a multimap.
* The deck is used for the call to getDeck(), which returns a shuffled copy of the deck
* The multimap contains the same pointers. It is used to construct a game from a file.
* More information can be found in CardFactory.cpp
*/
class CardFactory
{
	CardFactory();//créer toutes les cartes dans les bonnes proportions
	static CardFactory *instance;
	Deck deck;
	std::multimap<char, Card*> unloadedCards;

	template <class C> void addCards(int); //Helper function for initializing the cards
	
public:
	~CardFactory() = delete;
	CardFactory(const CardFactory&) = delete;
	CardFactory& operator=(const CardFactory&) = delete;

	static CardFactory* getFactory();

	Deck getDeck();

	Card* loadCard(char); //Retrieves a card in the deck corresponding to the character - used to build from save file

	static constexpr int numCardsInDeck = 104;
};

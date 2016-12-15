#include "Card.h"
#include "Deck.h"
#include "CardFactory.h"
#include "CppUnitTest.h"
#include "Exceptions.h"
#include <algorithm>
#include <iterator>
#include <functional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(DeckTests)
	{
	public:
		size_t static const CARDS_IN_DECK = 104;
		size_t static const QUARTZ_CARDS_IN_DECK = 20;
		size_t static const EMERALD_CARDS_IN_DECK = 6;

		TEST_METHOD(GetDeck_RightNumberOfDistinctCards)
		{
			auto *cf = CardFactory::getFactory();
			vector<Card*> quartz, emerald;

			auto deck = cf->getDeck();
			std::sort(deck.begin(), deck.end());
			auto uniqueElems = std::unique(deck.begin(), deck.end()); //ensure there are no duplicates

			//get all quartz and emerald cards
			std::copy_if(deck.begin(), uniqueElems, std::back_inserter(quartz), [](Card* c) { return c->getName() == "Quartz"; });
			std::copy_if(deck.begin(), uniqueElems, std::back_inserter(emerald), [](Card* c) { return c->getName() == "Emerald"; });

			Assert::AreEqual(CARDS_IN_DECK, deck.size());
			Assert::AreEqual(QUARTZ_CARDS_IN_DECK, quartz.size());
			Assert::AreEqual(EMERALD_CARDS_IN_DECK, emerald.size());
		}

		TEST_METHOD(GetDeck_CardsAreShuffled) {
			auto *cf = CardFactory::getFactory();

			auto deck1 = cf->getDeck();
			auto deck2 = cf->getDeck();

			//Technically this could be true if two decks are shuffled the same way, but this is extremely unlikely
			bool decksAreSame = std::equal(deck1.begin(), deck1.end(), deck2.begin(), [](Card* c, Card* d) { return c->getName() == d->getName(); });
			Assert::IsFalse(decksAreSame);
		}

		TEST_METHOD(LoadSavedDeck) {
			auto *cf = CardFactory::getFactory();
			stringstream s;
			auto deck1 = cf->getDeck();

			//remove a couple cards from the Deck
			deck1.draw();
			deck1.draw();

			s << deck1; 
			s.seekg(0); //move back to start to read in save file
			Deck deck2(s, cf);

			bool decksAreSame = std::equal(deck1.begin(), deck1.end(), deck2.begin(), [](Card* c, Card* d) { return c->getName() == d->getName(); });
			Assert::IsTrue(decksAreSame);
		}

		TEST_METHOD(LoadDeck_CorruptedSaveExtraCard) {
			auto *cf = CardFactory::getFactory();
			stringstream s;
			auto deck1 = cf->getDeck();

			s << deck1;
			s.seekp(0);
			s << 'Q'; //corrupt the save with an extra Quartz card
			s.seekg(0); //move back to start
			
			auto constructFromFile = [&] { Deck(s, cf); };

			Assert::ExpectException<corrupt_game_file>(constructFromFile);
		}

		TEST_METHOD(LoadDeck_CorruptedSaveInvalidInput) {
			auto *cf = CardFactory::getFactory();
			stringstream s;
			auto deck1 = cf->getDeck();

			s << deck1;
			s.seekp(0);
			s << '1'; //corrupt the save with a number
			s.seekg(0); //move back to start

			auto constructFromFile = [&] { Deck(s, cf); };

			Assert::ExpectException<corrupt_game_file>(constructFromFile);
		}

	};
}
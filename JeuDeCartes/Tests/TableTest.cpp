#include "Table.h"
#include "CppUnitTest.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(TableTests)
	{
	public:
		Player *p1, *p2;
		Deck *deck;
		DiscardPile *discardPile;
		TradeArea *tradeArea;
		CardFactory *cardFactory;
		Table *table;

		TEST_METHOD_INITIALIZE(initComponents) {
			p1 = new Player(string("David"));
			p2 = new Player(string("Caleb"));
			discardPile = new DiscardPile;
			tradeArea = new TradeArea;
			cardFactory = CardFactory::getFactory();
			deck = &cardFactory->getDeck();
			table = new Table(p1, p2, deck, discardPile, tradeArea);
		}

		TEST_METHOD(SwitchTurns) {
			//Arrange
			bool firstTurnIsDavid, turnChangedToCaleb, secondTurnIsCaleb, turnChangedToDavid, thirdTurnIsDavid, fourthTurnIsCaleb;

			//Act
			firstTurnIsDavid = &table->currentTurn() == p1;
			turnChangedToCaleb = &table->endTurn() == p2;
			secondTurnIsCaleb = &table->currentTurn() == p2;
			turnChangedToDavid = &table->endTurn() == p1;
			thirdTurnIsDavid = &table->currentTurn() == p1;
			table->endTurn();
			fourthTurnIsCaleb = &table->currentTurn() == p2;

			Assert::IsTrue(firstTurnIsDavid);
			Assert::IsTrue(turnChangedToCaleb);
			Assert::IsTrue(secondTurnIsCaleb);
			Assert::IsTrue(turnChangedToDavid);
			Assert::IsTrue(thirdTurnIsDavid);
			Assert::IsTrue(fourthTurnIsCaleb);
		}

		TEST_METHOD(SaveAndLoadTable) {

		}

		TEST_METHOD_CLEANUP(DeleteAndResetFactory) {
			delete p1;
			delete p2;
			delete discardPile;
			delete tradeArea;
			cardFactory->resetUnloadedCards();
		}


	};
}
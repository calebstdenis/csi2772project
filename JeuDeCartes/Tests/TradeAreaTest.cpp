#include "TradeArea.h"
#include "GameExceptions.h"
#include "CppUnitTest.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(TradeAreaTests)
	{
	public:

		TEST_METHOD(OnlyExistingGemLegal) {

			//Arrange
			Card *q1 = &Quartz(), *q2 = &Quartz(), *r = &Ruby();

			//Act
			auto ta = TradeArea();
			ta += q1;

			//Assert
			Assert::IsTrue(ta.legal(q2));
			Assert::IsFalse(ta.legal(r));
		}

		TEST_METHOD(TradeLastTwoCardsOfGemType_AttemptToTradeThree_ExceptionAfterThirdTrade) {

			//Act
			auto ta = TradeArea();
			ta += &Malachite();
			ta += &Ruby();
			ta += &Malachite();

			auto tradeMalachite = [&] { return ta.trade(Malachite::name); };
			Card* tradedMalachite1 = tradeMalachite();
			Card* tradedMalachite2 = tradeMalachite();

			//Assert
			Assert::IsTrue(tradedMalachite1->getName() == Malachite::name);
			Assert::IsTrue(tradedMalachite2->getName() == Malachite::name);
			Assert::IsTrue(tradedMalachite1 != tradedMalachite2);

			//exception should be thrown when attemping to trade a non-existant third Malachite
			Assert::ExpectException<game_logic_exception>(tradeMalachite); 
		}

		TEST_METHOD(Size) {

			//Arrange
			TradeArea emptyTA, nonemptyTA;

			//Act
			nonemptyTA += &Amethyst();
			nonemptyTA += &Amethyst();

			//Assert
			Assert::AreEqual(0, emptyTA.numCards());
			Assert::AreEqual(2, nonemptyTA.numCards());
		}

		TEST_METHOD(LoadTradeAreaFromSave) {
			//Arrange
				Card
				*q = &Quartz(),
				*h = &Hematite(),
				*o = &Obsidian(),
				*m = &Malachite(),
				*t = &Turquoise(),
				*r = &Ruby(),
				*a = &Amethyst(),
				*e = &Emerald();

			TradeArea savedTA;
			TradeArea loadedTA;
			stringstream save;

			//Act
			savedTA += q;
			savedTA += h;
			savedTA += o;

			save << savedTA;
			save.seekg(0);
			loadedTA = TradeArea(save, CardFactory::getFactory());

			//Assert
			Assert::IsTrue(loadedTA.legal(q));
			Assert::IsTrue(loadedTA.legal(h));
			Assert::IsTrue(loadedTA.legal(o));
			Assert::IsFalse(loadedTA.legal(m));
			Assert::IsFalse(loadedTA.legal(t));
			Assert::IsFalse(loadedTA.legal(r));
			Assert::IsFalse(loadedTA.legal(a));
			Assert::IsFalse(loadedTA.legal(e));
		}

		//Reset CardFactory so that changes to state in one test do not carry over
		TEST_METHOD_CLEANUP(resetUnloadedCards)
		{
			CardFactory::getFactory()->resetUnloadedCards();
		}


	};
}
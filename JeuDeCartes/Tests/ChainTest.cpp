#include "CppUnitTest.h"
#include "Card.h"
#include "CardFactory.h"
#include "Chain.h"
#include "GameExceptions.h"
#include <iostream>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(ChainTests)
	{
	public:

		TEST_METHOD(AddWrongCard_ThrowIllegalTypeException) {
			//Arrange
			Chain<Hematite> hematiteChain;
			auto addWrongCardType = [&] { hematiteChain += &Turquoise(); };

			//Assert
			Assert::ExpectException<IllegalTypeException>(addWrongCardType);
		}
		TEST_METHOD(Sell4Quartz_Get1Coin) {
			//Arrange
			Chain<Quartz> quartzChain;
			for (int i = 0; i < 4; i++)
				quartzChain += &Quartz();

			//Act
			int resultCoins = quartzChain.sell();

			//Assert
			Assert::AreEqual(1, resultCoins);
		}

		TEST_METHOD(Sell3Emerald_Get3Coins) {
			//Arrange
			Chain<Emerald> emeraldChain;
			for (int i = 0; i < 3; i++)
				emeraldChain += &Emerald();

			//Act
			int resultCoins = emeraldChain.sell();

			//Assert
			Assert::AreEqual(3, resultCoins);
		}

		TEST_METHOD(Sell4Emerald_GetCoinsFor3Emerald) {
			Chain<Emerald> emeraldChain4, emeraldChain3;
			for (int i = 0; i < 3; i++)
				emeraldChain3 += &Emerald();
			for (int i = 0; i < 4; i++)
				emeraldChain4 += &Emerald();

			//Act
			int resultCoins3 = emeraldChain4.sell();
			int resultCoins4 = emeraldChain4.sell();

			//Assert
			Assert::AreEqual(resultCoins3, resultCoins4);
		}

		TEST_METHOD(SaveAndLoadChain_Valid) {
			//Arrange
			Chain<Ruby> savedChain, loadedChain;
			auto cardFactory = CardFactory::getFactory();
			for (int i = 0; i < 4; i++)
				savedChain += &Ruby();
			stringstream save;

			//Act
			save << savedChain;
			save.seekg(0); //back to start of stream
			save.ignore(Ruby::name.length(), ' '); //ignore the name of the chain. this will be read in the Player constructor.
			loadedChain = Chain<Ruby>(save, cardFactory);

			//Assert
			Assert::AreEqual(savedChain.size(), loadedChain.size());
		}

		TEST_METHOD(SaveAndLoadChain_Invalid) {
			//Arrange
			Chain<Ruby> savedChain, loadedChain;
			auto cardFactory = CardFactory::getFactory();
			for (int i = 0; i < 4; i++)
				savedChain += &Ruby();
			stringstream save;
			auto loadCorruptedSave = [&] { loadedChain = Chain<Ruby>(save, cardFactory); };

			//Act
			save << savedChain;
			save << 'T'; //Add a Turquoise card to the save of the Ruby chain
			save.seekg(0); //back to start of stream
			save.ignore(Ruby::name.length(), ' '); //ignore the name of the chain. this will be read in the Player constructor.
			
			//Assert
			Assert::ExpectException<corrupt_game_file_exception>(loadCorruptedSave);
		}

		//Reset CardFactory so that changes to state in one test do not carry over
		TEST_METHOD_CLEANUP(resetUnloadedCards)
		{
			CardFactory::getFactory()->resetUnloadedCards();
		}
	};
}
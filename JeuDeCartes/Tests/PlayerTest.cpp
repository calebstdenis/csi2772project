#include "Player.h"
#include <sstream>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(PlayerTests)
	{
	public:

		TEST_METHOD(SaveAndLoadPlayer_WithChains) {
			//Arrange
			Player *savedPlayer = new Player(string("Ajax"));
			Player *loadedPlayer;
			stringstream save;

			/*Add 5 ruby cards and 3 quartz cards to hand, and make chains with all of them */
			for (int i = 0; i < 5; i++) {
				Card* ruby = new Ruby;
				savedPlayer->draw(ruby);
			}

			for (int i = 0; i < 3; i++) {
				Card* quartz = new Quartz;
				savedPlayer->draw(quartz);
			}

			for (int i = 0; i < 8; i++) {
				savedPlayer->play();
			}

			/* Add Turquoise and Emerald cards to hand */
			savedPlayer->draw(new Turquoise);
			savedPlayer->draw(new Emerald);

			/* Save and load Player*/
			savedPlayer->print(save);
			loadedPlayer = new Player(save, CardFactory::getFactory());

			//Assert
			Assert::IsTrue(*savedPlayer == *loadedPlayer);
		}

		TEST_METHOD(SaveAndLoadPlayer_WithoutChains) {
			//Arrange
			Player *savedPlayer = new Player(string("Ajax"));
			Player *loadedPlayer;
			stringstream save;

			/* Add Turquoise and Emerald cards to hand */
			savedPlayer->draw(new Turquoise);
			savedPlayer->draw(new Emerald);

			/* Save and load Player*/
			savedPlayer->print(save);
			loadedPlayer = new Player(save, CardFactory::getFactory());

			//Assert
			Assert::IsTrue(*savedPlayer == *loadedPlayer);
		}

		TEST_METHOD_CLEANUP(resetUnloadedCards)
		{
			CardFactory::getFactory()->resetUnloadedCards();
		}


	};
}
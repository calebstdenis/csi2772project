#include "Hand.h"
#include "Card.h"
#include "CppUnitTest.h"
#include "CardFactory.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(TableTests)
	{
	public:

		TEST_METHOD(SwitchTurns) {
			//Arrange
			Hand savedHand, loadedHand;
			savedHand += &Quartz();
			savedHand += &Hematite();
			savedHand += &Quartz();
			savedHand += &Ruby();
			stringstream save;

			//Act
			save << savedHand;
			loadedHand = Hand(save, CardFactory::getFactory());

			//Assert
			Assert::IsTrue(savedHand == loadedHand);
		}


	};
}
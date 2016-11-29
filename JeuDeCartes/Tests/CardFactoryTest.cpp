#include "Card.h"
#include "Deck.h"
#include "CardFactory.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(CardFactoryTests)
	{
	public:

		TEST_METHOD(GetFactory)
		{
			auto *cf = CardFactory::getFactory();
		}

	};
}
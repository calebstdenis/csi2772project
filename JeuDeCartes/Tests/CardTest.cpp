#include "Card.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(CardTests)
	{
	public:
		
		TEST_METHOD(Names) 
		{
			Card
				*q = &Quartz(),
				*h = &Hematite(),
				*o = &Obsidian(), 
				*m = &Malachite(),
				*t = &Turquoise(), 
				*r = &Ruby(),
				*a = &Amethyst(),
				*e = &Emerald();

			Assert::IsTrue("Quartz" == q->getName());
			Assert::IsTrue("Hematite" == h->getName());
			Assert::IsTrue("Obsidian" == o->getName());
			Assert::IsTrue("Malachite" == m->getName());
			Assert::IsTrue("Turquoise" == t->getName());
			Assert::IsTrue("Ruby" == r->getName());
			Assert::IsTrue("Amethyst" == a->getName());
			Assert::IsTrue("Emerald" == e->getName());
		}

		TEST_METHOD(CardsPerCoin_InRange) {
			Card *q = &Quartz();
			Card *e = &Emerald();

			Assert::AreEqual(6, q->getCardsPerCoin(2));
			Assert::AreEqual(2, e->getCardsPerCoin(2));
		}

	};
}
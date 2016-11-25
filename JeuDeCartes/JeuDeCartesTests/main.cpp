#include "gtest\gtest.h"
#include "Card.h"

int main(int ac, char* av[])
{
	Quartz q;
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}
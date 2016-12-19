#include "Player.h"
#include "GameExceptions.h"

Player::Player(std::string& nom)
{
	Player::nom = nom;
	numCoins = 0;//il va falloir rev�rifier le nombre de pi�ces au d�part
	maxNumChain = 2;
}

std::string Player::getName() const
{
	return nom;
}

int Player::getNumCoins() const
{
	return numCoins;
}

Player& Player::operator+= (int num)//ajoute des nouvelles pi�ces
{
	if (num < 0)
		throw new IndexOutOfBoundsException(num);
	else
		numCoins += num;
	return this;
}

int Player::getMaxNumChains()
{
	return maxNumChain;
}

int Player::getNumChains()
{
	return chain.size;
}

Chain<Card*>& Player::operator[](int i)
{
	return chain[i];
}

void Player::buyThirdChain()
{
	if (maxNumChain == 2)
	{
		if (numCoins < 2)
			throw new NotEnoughCoinsException();
		else
		{
			numCoins -= 2;
			maxNumChain = 3;
		}
	}
}

void Player::printHand(std::ostream& os, bool premier)
{
	if (premier)
	{
		main.top()->print();
	}
	else
	{
		//print toute la main
	}
}


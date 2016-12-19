#include "Player.h"

Player::Player(std::string& nom)
{
	Player::nom = nom;
	numCoins = 0;//il va falloir revérifier le nombre de pièces au départ
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

Player& Player::operator+= (int num)//ajoute des nouvelles pièces
{
	if (num < 0)
		throw IllegalTypeException(num);
	else
		numCoins += num;
	return &this;
}

int Player::getMaxNumChains()
{
	return maxNumChain;
}

int Player::getNumChains()
{
	return chain.size;
}

Chain& Player::operator[](int i)
{
	return &chain[i];
}

void Player::buyThirdChain()
{
	if (maxNumChain == 2)
	{
		if (numCoins < 2)
			throw NotEnoughCoinsException();
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
		os >> main.top();//print la première carte
	}
	else
	{
		//print toute la main
	}
}


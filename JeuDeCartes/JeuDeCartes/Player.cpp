#include "Player.h"
#include "GameExceptions.h"

Player::Player(std::string& nom)
{
	Player::nom = nom;
	numCoins = 0;
	maxNumChain = 2;
}

Player::Player(std::istream & is, CardFactory* cf)
{

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
		throw new IndexOutOfBoundsException(num);
	else
		numCoins += num;
	return *this;
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
		os << main;
	}
}

std::ostream& operator<<(std::ostream& os, const Player & player)
{
	os << player.nom << std::setw(IOUtil::COLUMN_WIDTH) << player.numCoins << " Coins" << endl;
	for (Chain<Card*> c : player.chain)
	{
		os << c;
	}
}




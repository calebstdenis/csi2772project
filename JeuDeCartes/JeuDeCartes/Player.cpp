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
	if (!(is >> nom))
		throw corrupt_game_file_exception();
	if (!(is >> numCoins))
		throw corrupt_game_file_exception();
	if (!(is >> maxNumChain))
		throw corrupt_game_file_exception();
	main = *new Hand(is,cf);

	Chain_Base* c;
	std::string s;
	while (is >> s)
	{
		if (s == Quartz::name)
			c = new Chain<Quartz>(is, cf);
		else if (s == Hematite::name)
			c = new Chain<Hematite>(is, cf);
		else if (s == Quartz::name)
			c = new Chain<Obsidian>(is, cf);
		else if (s == Malachite::name)
			c = new Chain<Malachite>(is, cf);
		else if (s == Turquoise::name)
			c = new Chain<Turquoise>(is, cf);
		else if (s == Ruby::name)
			c = new Chain<Ruby>(is, cf);
		else if (s == Amethyst::name)
			c = new Chain<Amethyst>(is, cf);
		else if (s == Emerald::name)
			c = new Chain<Emerald>(is, cf);
		else
			throw corrupt_game_file_exception();
		chain.push_back(c);
	}
	if (getNumChains() > maxNumChain)
		throw corrupt_game_file_exception();
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
	return (int)chain.size();
}

Chain_Base& Player::operator[](int i)
{
	return *chain[i];
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
		main.top()->print(os);
	}
	else
	{
		os << main;
	}
}

std::ostream& operator<<(std::ostream& os, const Player & player)
{
	os << player.nom << std::setw(IOUtil::COLUMN_WIDTH) << player.numCoins << " Coins" << endl;
	for (Chain_Base* c : player.chain)
	{
		os << *c;
	}
	return os;
}

void Player::print(std::ostream& os)
{
	os << nom << endl;
	os << numCoins << endl;
	os << maxNumChain << endl;
	os << main << endl;
	for (Chain_Base* c : chain)
	{
		os << c << endl;
	}
}

void Player::draw(Card * c)
{
	main += c;
}




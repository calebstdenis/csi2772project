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
	os << endl;
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

void Player::play() {
	play(main.play());
}

void Player::play(Card *c)
{
	for (int i = 0; i < getNumChains(); i++)//on essaye en premier d'ajouter la carte à une chaine existante
	{
		try
		{
			*chain[i] += c;
			return;//si on se rend ici il n'y a pas d'erreurs et tout est correct
		}
		catch (IllegalTypeException e)
		{
			//ne rien faire ici
		}
	}
	//s'il y a trop de chaines on en vend une ou achete une nouvelle si possible
	if (getNumChains() == maxNumChain)
	{
		bool b = true;
		if (maxNumChain == 2)
		{
			b = false;
			char ch;
			do
			{
				cout << "Acheter une nouvelle chaine?" << endl << "o/n";
				cin >> ch;
			}
			while (ch != 'o' && ch != 'n');
			if (ch == 'o')
			{
				try//retourner une valeur booléenne serait plus simple ici
				{
					buyThirdChain();
				}
				catch (NotEnoughCoinsException e)
				{
					b = true;
				}
			}
			else
				b = true;
		}
		if (b)
		{
			//vendre une chaine
			cout << "choisir une chaine a vendre (l'index commence a 0) /n";
			int num = 10;
			while (num > maxNumChain)
				cin >> num;
			*this+=chain[num]->sell();
		}
	}
	//créer nouvelle chaine
	Chain_Base* chainBase;
	std::string s = c->getName();
	if (s == Quartz::name)
		chainBase = new Chain<Quartz>();
	else if (s == Hematite::name)
		chainBase = new Chain<Hematite>();
	else if (s == Quartz::name)
		chainBase = new Chain<Obsidian>();
	else if (s == Malachite::name)
		chainBase = new Chain<Malachite>();
	else if (s == Turquoise::name)
		chainBase = new Chain<Turquoise>();
	else if (s == Ruby::name)
		chainBase = new Chain<Ruby>();
	else if (s == Amethyst::name)
		chainBase = new Chain<Amethyst>();
	else if (s == Emerald::name)
		chainBase = new Chain<Emerald>();
	else
		throw corrupt_game_file_exception();
	*chainBase += c;
	chain.push_back(chainBase);//ajouter une nouvelle chaine
}

Card* Player::removeIndex(int index)
{
	return main[index];
}

bool Player::isHandEmpty()
{
	return main.isEmpty();
}





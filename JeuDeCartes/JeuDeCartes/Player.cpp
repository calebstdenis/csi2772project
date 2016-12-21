#include "Player.h"
#include "GameExceptions.h"
#include <algorithm>
#include <iterator>
#include "IOUtil.h"

Player::Player(std::string& nom)
{
	Player::nom = nom;
	numCoins = 0;
	maxNumChain = 2;
}

Player::Player(std::istream & is, CardFactory* cf)
{
	int numChains; 

	if (!(is >> nom))
		throw corrupt_game_file_exception();
	if (!(is >> numCoins))
		throw corrupt_game_file_exception();
	if (!(is >> maxNumChain))
		throw corrupt_game_file_exception();
	if (!(is >> numChains))
		throw corrupt_game_file_exception();


	IOUtil::ignoreLine(is);

	//Get hand line
	string line;
	stringstream lineStream;
	std::getline(is, line);
	lineStream = stringstream(line);

	main = *new Hand(lineStream,cf);

	//Get chains line by line, if any
	Chain_Base* c;
	string s;
	for (int i = 0; i < numChains; i++) {
		getline(is, line);
		lineStream = stringstream(line);
		
		if (!(lineStream >> s))
			throw corrupt_game_file_exception();

		if (s == Quartz::name)
			c = new Chain<Quartz>(lineStream, cf);
		else if (s == Hematite::name)
			c = new Chain<Hematite>(lineStream, cf);
		else if (s == Obsidian::name)
			c = new Chain<Obsidian>(lineStream, cf);
		else if (s == Malachite::name)
			c = new Chain<Malachite>(lineStream, cf);
		else if (s == Turquoise::name)
			c = new Chain<Turquoise>(lineStream, cf);
		else if (s == Ruby::name)
			c = new Chain<Ruby>(lineStream, cf);
		else if (s == Amethyst::name)
			c = new Chain<Amethyst>(lineStream, cf);
		else if (s == Emerald::name)
			c = new Chain<Emerald>(lineStream, cf);
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
		os << *c << endl;
	}
	return os;
}

void Player::print(std::ostream& os)
{
	os << nom << endl;
	os << numCoins << endl;
	os << maxNumChain << endl;
	os << getNumChains() << endl;
	os << main << endl;
	for (Chain_Base* c : chain)
	{
		os << *c << endl;
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
			if (IOUtil::promptForInput<bool>("Acheter une nouvelle chaine?"))
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
			int num = 10;
			cout << "choisir une chaine a vendre (l'index commence a 0)" << endl;
			while (num > maxNumChain)
				cin >> num;
			*this+=chain[num]->sell();
			chain.erase(chain.begin() + num);
		}
	}
	//créer nouvelle chaine
	Chain_Base* chainBase;
	std::string s = c->getName();
	if (s == Quartz::name)
		chainBase = new Chain<Quartz>();
	else if (s == Hematite::name)
		chainBase = new Chain<Hematite>();
	else if (s == Obsidian::name)
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

bool operator==(const Player &p1, const Player &p2) {
	auto chainsSame = [](const Chain_Base *c1, const Chain_Base *c2) { return c1->size() == c2->size() && typeid(c1) == typeid(c2); };
	return p1.nom == p2.nom
		&& p1.numCoins == p2.numCoins
		&& p1.maxNumChain == p2.maxNumChain
		&& p1.main == p2.main
		&& equal(p1.chain.cbegin(), p1.chain.cend(), p2.chain.cbegin(), p2.chain.cend(), chainsSame);
}





#include <string>

class Player
{
	std::string nom;
	//Chain chain[3];
public:
	Player(std::string);
	Player(const std::istream &, bool);
	std::string getName() const;
	int getNumCoins() const;
	Player & operator+=(int);
	int getMaxNumChains();
	int getNumChains();
	//Chain & operator[] (int);
	void buyThirdChain();
	void printHand(std::ostream&, bool);
	friend std::ostream& operator<<(std::ostream&, const Player &);
};

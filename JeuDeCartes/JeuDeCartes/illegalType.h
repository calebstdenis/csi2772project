#include <exception>
using namespace std;

class IllegalType 
{
	virtual const char* what() const throw()
	{
		return "IllegalTypeException, wrong type";
	}
} illegalType;


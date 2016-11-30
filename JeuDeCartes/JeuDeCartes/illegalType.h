#include <exception>
using namespace std;

class IllegalTypeException 
{
	virtual const char* what() const throw()
	{
		return "IllegalTypeException, wrong type";
	}
} illegalType;


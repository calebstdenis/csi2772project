#ifndef GAME_EXCEPTIONS_H
#define GAME_EXCEPTIONS_H

#include <string>

class IllegalTypeException
{
public:
	IllegalTypeException() {}
	virtual const char* what() const throw()
	{
		return "IllegalTypeException, wrong type";
	}
};

class corrupt_game_file_exception : public std::runtime_error {
public:
	corrupt_game_file_exception() : std::runtime_error("Unable to read paused game from file.") {}
	explicit corrupt_game_file_exception(const std::string &s) : std::runtime_error("Unable to read paused game from file." + s) {}
};

class game_logic_exception : public std::runtime_error {
public:
	explicit game_logic_exception(const std::string &s) : std::runtime_error(s) {}
};

#endif

#include <string>

class corrupt_game_file : public std::runtime_error {
public:
	corrupt_game_file() : std::runtime_error("Unable to read paused game from file.") {}
};

class game_logic_error : public std::runtime_error {
public:
	explicit game_logic_error(const std::string &s) : std::runtime_error(s) {}
};


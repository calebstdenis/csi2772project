#include <string>

class corrupt_game_file : public std::runtime_error {
public:
	explicit corrupt_game_file() : std::runtime_error("Unable to read paused game from file.") {}
};
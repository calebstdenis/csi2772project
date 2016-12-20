#ifndef IO_UTIL
#define IO_UTIL

#include <iostream>
#include <limits>
#include <string>

namespace IOUtil {
	constexpr int COLUMN_WIDTH = 5;

	template <class T> T promptForInput(std::string msg) {
		std::cout << msg << std::endl;
		T val = std::cin.get();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return val;
	}

	//Bool: Specilalisation impliquant un char pour oui ou non.
	template <> bool promptForInput(std::string msg);

	template <> std::string promptForInput(std::string msg);
}

#endif
#ifndef IO_UTIL
#define IO_UTIL

#include <iostream>
#include <limits>
#include <string>

namespace IOUtil {
	constexpr int COLUMN_WIDTH = 5;
	constexpr char SAVE_FILE[] = "save";

	template <class T> T promptForInput(std::string msg) {
		std::cout << msg << std::endl;
		T val = std::cin.get();

		//Bug fix
		if (val == '\n') {
			std::cin >> val;
		}

		ignoreLine(std::cin);
		return val;
	}

	void ignoreLine(std::istream&);

	//Bool: Specilalisation impliquant un char pour oui ou non.
	template <> bool promptForInput(std::string msg);

	template <> std::string promptForInput(std::string msg);
}

#endif
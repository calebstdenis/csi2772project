#include "IOUtil.h"
#include <iostream>
#include <limits>
#include "IOUtil.h"

namespace IOUtil {

	void ignoreLine(std::istream& in) {
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//Bool: Specilalisation impliquant un char pour oui ou non.
	template <> bool promptForInput(std::string msg) {
		char res;
		do {
			res = promptForInput<char>(msg + "(o/n)");
			if (res != 'o' && res != 'n') {
				std::cout << "Entree invalide!" << std::endl;
				continue;
			}
			else break;
		} while (true);

		return res == 'o';
	}

	template <> std::string promptForInput(std::string msg) {
		std::cout << msg << std::endl;
		std::string s;
		std::getline(std::cin, s, '\n');
		return s;
	}
}
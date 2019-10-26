#include <iostream>

int main() {
	char letter;
	std::cout << "Enter your letter: " << std::endl;
	std::cin >> letter;

	if( letter >= 'a' && letter <= 'z' ) {
		std::cout << char(letter - ('a' - 'A')) << std::endl;
	} else {
		std::cout << "Not is small letter!" << std::endl;
	}


	return 0;
}

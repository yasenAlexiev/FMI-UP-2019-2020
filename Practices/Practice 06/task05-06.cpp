#include <iostream>

bool isLetter(char c) {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

bool isSmallLetter(char c) {
	return ('a' <= c && c <= 'z');
}

bool isCapitalLetter(char c) {
	return ('A' <= c && c <= 'Z');
}

char returnOppositeLetter(char c) {
	char result;
	if(isSmallLetter(c)) {
		result = c - ('a' - 'A');	
	} else if(isCapitalLetter(c)) {
		result = c + ('a' - 'A');	
	} else {
		std::cout << "Is not a letter" << std::endl;
		result = c;	
	}
	return result;
}

int main() {
	char c;
	std::cout << "Enter a letter: ";
	std::cin >> c;

	if(isLetter(c)) {
		std::cout << "This is letter!" << std::endl;
		std::cout << "The opposite is: " << returnOppositeLetter(c) << std::endl;
	} else {
		std::cout << "This is not a letter" << std::endl;
	}
	
	return 0;
}

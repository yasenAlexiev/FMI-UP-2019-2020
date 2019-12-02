#include <iostream>

#define MAX 1000

int main() {
	unsigned points[MAX];
	size_t numPlayers;
	do {
		std::cout << "Enter number of players: ";
		std::cin >> numPlayers;
	} while(numPlayers < 0 || numPlayers > MAX);

	for(int i = 0; i < numPlayers; ++i) {
		std::cin >> points[i];
	}

	for(int i = 0; i < 3; ++i) {
		std::cout << points[i] << std::endl;
	}
	return 0;
}

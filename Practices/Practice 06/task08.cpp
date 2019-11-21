#include <iostream>

void squareEverythingFrom1toN(unsigned short n) {
	for(int i = 1; i <= n; ++i) {
		std::cout << i*i << ' ';
	}	
}

int main() {
	unsigned short n;
	std::cout << "Enter number: ";
	std::cin >> n;

	squareEverythingFrom1toN(n);

	return 0;
}

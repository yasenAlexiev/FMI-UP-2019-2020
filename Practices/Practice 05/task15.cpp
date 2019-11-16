#include <iostream>

int main() {
	unsigned short n;
	std::cout << "Enter number: ";
	std::cin >> n;

	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < (n-i); ++j) {
			std::cout << ' ';
		}
		for(int j = 1; j <= (i*2 - 1); ++j) {
			std::cout << '*';	
		}
		std::cout << std::endl;
	}

	for(int i = 0; i < n-1; ++i) {
		std::cout << ' ';
	}
	std::cout << '*' << std::endl;

	for(int i = 0; i < n-1; ++i) {
		std::cout << ' ';
	}
	std::cout << '*' << std::endl;
	
	return 0;
}

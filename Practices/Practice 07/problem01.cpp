#include <iostream>

int main() {
	int number;
	std::cin >> number;
	unsigned short k;
	std::cin >> k;
	unsigned mask = 1 << k;

	std::cout << ((number & mask) ? 1 : 0 ) << std::endl;


	return 0;
}

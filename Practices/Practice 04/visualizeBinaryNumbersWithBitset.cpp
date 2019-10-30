#include <iostream>
#include <bitset>

int main() {
	unsigned int number;

	std::cin >> number;

	std::bitset<32> numberAsBinary32(number);
	std::bitset<64> numberAsBinary64(number);

	std::cout << numberAsBinary32 << std::endl;
	std::cout << numberAsBinary64 << std::endl;

	return 0;
}

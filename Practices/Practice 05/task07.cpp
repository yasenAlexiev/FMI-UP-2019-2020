#include <iostream>

int main() {
	unsigned number, reverseNumber = 0;
	std::cin >> number;

	unsigned buff = number;
	while(buff > 0) {
		reverseNumber += buff % 10;
		reverseNumber *= 10;
		buff /= 10;
	}
	reverseNumber /= 10;
	std::cout << (reverseNumber == number ? "Yup" : "Nope") << std::endl;

	return 0;
}

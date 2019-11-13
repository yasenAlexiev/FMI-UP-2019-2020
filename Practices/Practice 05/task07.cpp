#include <iostream>

int main() {
	unsigned number, reverceNumber = 0;
	std::cin >> number;

	unsigned buff = number;
	while(buff > 0) {
		reverceNumber += buff % 10;
		reverceNumber *= 10;
		buff /= 10;
	}
	reverceNumber /= 10;
	std::cout << (reverceNumber == number ? "Yup" : "Nope") << std::endl;

	return 0;
}

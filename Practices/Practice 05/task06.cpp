#include <iostream>

int main() {
	unsigned number;
	std::cin >> number;

	unsigned sumDigits = 0;

	while(number > 0) {
		sumDigits += number % 10;
		number /= 10;
	}
	
	std::cout << "Sum of digits is: " << sumDigits << std::endl;

	return 0;
}

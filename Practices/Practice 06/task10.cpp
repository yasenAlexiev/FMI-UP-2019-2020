#include <iostream>

unsigned sumDigits(unsigned number) {
	unsigned sum = 0;
	while(number > 0) {
		sum += number%10;
		number /= 10;	
	}
	return sum;
}

int main() {
	unsigned number;
	std::cout << "Enter a number: ";
	std::cin >> number;

	std::cout << sumDigits(number) << std::endl;

	return 0;
}

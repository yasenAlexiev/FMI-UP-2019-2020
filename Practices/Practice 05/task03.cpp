#include <iostream>
#include <math.h>

int main() {
	unsigned int number;
	std::cout << "Enter a number" << std::endl;
	std::cin >> number;
	double sq = sqrt(number);
	bool isPrime = true;
	for(int i = 2; i < sq; ++i) {
		if(number % i == 0) {
			isPrime = false;
			break;
		}
	}

	std::cout << (isPrime ? "Is prime" : "Not a prime" ) << std::endl;

	return 0;
}

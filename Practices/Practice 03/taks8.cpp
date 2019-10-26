#include <iostream>
#include <math.h>

int main() {
	unsigned a, b, c;
	std::cout << "Enter your numbers: " << std::endl;
	std::cin >> a >> b >> c;

	if(a + b > c && a + c > b && b + c > a) {
		std::cout << "Valid sides on triangle!" << std::endl;
		double p = (a + b + c) / 2.0;
		double S = sqrt(p * (p-a) * (p-b) * (p-c));
		std::cout << "Area is: " << S << std::endl;
	} else {
		std::cout << "Not valid sides on triangle!" << std::endl;
	}

	return 0;
}

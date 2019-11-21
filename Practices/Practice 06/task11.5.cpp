#include <iostream>

unsigned long long factorial(unsigned short n) {
	unsigned long long fact = 1;
	for(int i = 1; i <= n; ++i) {
		fact *= i;
	}
	return fact;
}


int main() {
	unsigned short n;
	std::cout << "Enter number: ";
	std::cin >> n;

	std::cout << n << "! = " << factorial(n) << std::endl;

	return 0;
}

#include <iostream>
#include <math.h>

void funnyFunction(unsigned long long n, unsigned long long m) {
	unsigned long long powered;
	for(int j = 1; j <= n; j+=2) {
		powered = pow(j, m);
		std::cout << powered << ' ';
	}

	std::cout << std::endl;

	for(int j = 2; j <= n; j+=2) {
		std::cout << j%m << ' ';
	}
}

int main() {
	unsigned long long n, m;
	std::cout << "Enter two numbers: " << std::endl;
	std::cin >> n >> m;

	funnyFunction(n, m);

	return 0;
}

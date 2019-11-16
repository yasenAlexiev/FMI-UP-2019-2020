#include <iostream>
#include <math.h>

bool isPrime(int number) {
	double sq = sqrt(number);

	for(int i = 2; i <= sq; ++i) {
		if(number%i == 0) {
			return false;
		}
	}
	return true;
}

void primesInRange(unsigned n, unsigned m) {

	for(int i = m; i <= n; ++i) {
		if ( isPrime(i) ) {
			std::cout << i << " ";
		}
	}
}

int main() {
	unsigned n,m;
	std::cout << "Enter interval [m, n]: ";
	std::cin >> m >> n;

	primesInRange(n, m);

	return 0;
}

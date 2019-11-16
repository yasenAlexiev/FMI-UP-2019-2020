#include <iostream>
#include <math.h>

bool isPrime(unsigned number) {
	double sq = sqrt(number);
	
	for(int i = 2; i <= sq; ++i) {
		if(number%i == 0) {
			return false;		
		}	
	}
	return true;
}

int main() {
	unsigned short n;
	std::cout << "Enter number: ";
	std::cin >> n;
	
	unsigned i = 2;
	unsigned short counter = 0;
	while(counter < n) {
		if(isPrime(i)) {
			std::cout << i << " ";
			++counter;
		}
		++i;
	}

	return 0;
}

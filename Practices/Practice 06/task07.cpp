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
	const unsigned MAX = 1000000;	

	for(int i = 1; i <= MAX; ++i) {
		if(isPrime(i)) {
			std::cout << i << " ";
		}
	}

	return 0;
}

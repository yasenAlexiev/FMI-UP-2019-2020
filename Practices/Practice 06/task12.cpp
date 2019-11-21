#include <iostream>

void fibonacciToN(unsigned short n) {

	unsigned f1 = 0, f2 = 1, f3;
	std::cout << f1 << " " << f2;	
	for( int i = 2; i <= n; ++i) {
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
		std::cout << " " << f3;
	}
}

int main() {
	unsigned short n;
	std::cout << "Enter number" << std::endl;
	std::cin >> n;

	fibonacciToN(n);	

	return 0;
}

#include <iostream>
#include <math.h>

int main() {
	unsigned short n;
	std::cout << "Enter number: ";
	std::cin >> n;

	for(int i = 1; i <= n; ++i) {
		std::cout << "The number " << i << "cubed is: " << pow(i, 3) << std::endl;
	}

	return 0;
}

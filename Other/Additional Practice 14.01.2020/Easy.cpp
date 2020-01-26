#include <iostream>

//task 1
unsigned factorial(unsigned n) {
	if(n < 2) {
		return n;
	}

	return n*factorial(n-1);
}

//task 2
unsigned triangleBlocks(unsigned rowsCount) {
	if(rowsCount < 2) {
		return rowsCount;
	}

	return rowsCount+triangleBlocks(rowsCount - 1);
}

int main() {
	
	unsigned number;

	std::cin >> number;

	std::cout << "Factorial of " << number << " is: " << factorial(number) << std::endl;
	std::cout << "Sum of blocks to " << number << " row is: " << triangleBlocks(number) << std::endl;

	return 0;
}

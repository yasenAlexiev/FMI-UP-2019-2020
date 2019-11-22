#include <iostream>

void swapWithCopies(int x, int y) {
	int buff = x;
	x = y;
	y = buff;
	std::cout << "After swap with copies..." << std::endl;
}

void swapWithReference(int& x, int& y) {
	int buff = x;
	x = y;
	y = buff;
	std::cout << "After swap with reference..." << std::endl;
}

int main() {
	int a, b;
	std::cout << "Enter two numbers: " << std::endl;
	std::cin >> a >> b;

	swapWithCopies(a, b);
	std::cout << "a: " << a << " b: " << b << std::endl;

	swapWithReference(a, b);
	std::cout << "a: " << a << " b: " << b << std::endl;


	return 0;
}

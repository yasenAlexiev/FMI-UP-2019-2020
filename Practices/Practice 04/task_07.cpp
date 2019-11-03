#include <iostream>

int main() {
	unsigned a;

	std::cin >> a;
	//00000.0001000.0000
	//0000.00000111.1111
	//0000.0000111111111
	std::cout << (((a ^ a-1) == ((a<<1) - 1) ) ? "Yup" : "Nope") << std::endl;

	return 0;
}

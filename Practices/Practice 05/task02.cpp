#include <iostream>

int main() {
	int a, b, c;
	std::cout << "Enter two numbers a and b (a < b)" << std::endl;
	std::cin >> a >> b;
	
	do {	
		std::cout << "Enter number between a and b" << std::endl;
		std::cin >> c;
	} while(c < a || c > b);

	
	return 0;
}

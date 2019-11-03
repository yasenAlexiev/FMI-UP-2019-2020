#include <iostream>


int main() {
	unsigned int a, b;

	std::cin >> a >> b;

	if( a ^ b ) {
		std::cout << "Nope" << std::endl;
	} else {
		std::cout << "Yup" << std::endl;	
	}

	return 0;
}

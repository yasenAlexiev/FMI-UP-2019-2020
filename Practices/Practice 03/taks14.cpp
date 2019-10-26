#include <iostream>
#include <math.h>

int main() {
	unsigned short number1, number2, operation;
	std::cout << "Enter two numbers and operation: " << std::endl;
	std::cin >> number1 >> number2 >> operation;

	if(number1 < 1 || number2 < 1 || number1 > 101 || number2 > 101) {
		std::cout << "Invalid number, sorry" << std::endl;
		return -1;
	}

	switch( operation ) {
		case 1: {
			std::cout << "Number1: " << ++number1 << ", Number2: " << ++number2 << std::endl;
			break;
		}
		case 2: {
			std::cout << "Number1: " << --number1 << ", Number2: " << --number2 << std::endl;
			break;
		}
		case 3: {
			std::cout << "Number1 + Number2: " << number1 + number2 << std::endl;
			break;
		}
		case 4: {
			std::cout << "Number1 - Number2: " << number1 - number2 << std::endl;
			break;
		}
		case 5: {
			std::cout << "Number1 * Number2: " << number1 * number2 << std::endl;
			break;
		}
		case 6: {
			std::cout << "Number1 / Number2: " << double(number1) / double(number2) << std::endl;
			break;
		}
		case 7: {
			std::cout << "Number1 ^ Number2: " << pow(number1, number2) << std::endl;
			break;
		}
		default: {
			std::cout << "Invalid operation!" << std::endl;
			break;
		}
	}

	return 0;
}

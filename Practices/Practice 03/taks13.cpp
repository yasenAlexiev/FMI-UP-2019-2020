#include <iostream>
#include <math.h>

int main() {
	double mark;
	std::cout << "Enter your mark: " << std::endl;
	std::cin >> mark;
	
	if( mark > 6.0 || mark < 2.0 ) {
		std::cout << "Not in the scale!" << std::endl;
		return -1;
	}
	
	if( mark < 3.0 ) {
		std::cout << "Fail" << std::endl;
		return 0;
	}


	switch((int)round(mark)) {
		case 3:
			std::cout << "Average" << std::endl;
			break;
		case 4:
			std::cout << "Above average" << std::endl;
			break;
		case 5:
			std::cout << "Good" << std::endl;
			break;
		case 6:
			std::cout << "Exellent" << std::endl;
			break;
		default:
			std::cout << "Not in the scale!" << std::endl;
			break;
	}

	return 0;
}

#include <iostream>


int main() {
	int x;
	std::cin >> x;
	//first way
	if(x%2 == 0) {
		std::cout << "Even number!" << std::endl;
	} else {
		std::cout << "Odd number!" << std::endl;
	}

	//second way
	/*	
	if(x&1 == 0) {
		std::cout << "Even number!" << std::endl;
	} else {
		std::cout << "Odd number!" << std::endl;
	}
	*/

	// what's the difference between this two?
	
	return 0;
}

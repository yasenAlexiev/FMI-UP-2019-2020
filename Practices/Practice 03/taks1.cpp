#include <iostream> // for cout and cin
#include <stdlib.h> // for abs()

int main() {
	int number;
	std::cin >> number;
	// 1 way
	if(number < 0){	
		std::cout << "Absolute value: " << -number << std::endl;	
	} else {		
		std::cout << "Absolute value: " << number << std::endl;	
	}

	//2 way	
	/*	
	std::cout << "Absolute value: " << abs(number) << std::endl;	
	*/	


	//3 way
	/*
	if(number < 0){	
		number = -number;	
	}

	std::cout << "Absolute value: " << number << std::endl;	
	*/


	return 0;
}

#include <iostream>

#define MIN_RANGE 1000
#define MAX_RANGE 9999

int main() {
	unsigned short number;
	std::cout << "Enter your number in range [1000..9999]" << std::endl;
	std::cin >> number;

	if( number < MIN_RANGE || number > MAX_RANGE ) {
		std::cout << "Number out of range!" << std::endl;
		return -1;
	}

	unsigned short first_number = 0, second_number = 0;
	
	//first way to "pars" the number
	//if the number will be abcd
	first_number = number%10 + (number/1000)*10; //d + a * 10
	second_number = (number/10)%10 + ((number/100)%10)*10; // c + b * 10
	
	// second way
	/*
	first_number = number%10; // first_number = d
	number /= 10; // number = abc
	second_number = number%10; // second number = c
	number /= 10; // number = ab
	second_number += (number%10)*10; // second_number = c + b * 10
	number /= 10; // number = a
	first_number += number * 10; // first_number = d + a * 10
	*/

	if(first_number < second_number) {	
		std::cout << first_number << " is less then " << second_number << std::endl;
	} else if(first_number > second_number) {	
		std::cout << first_number << " is greater then " << second_number << std::endl;
	} else {	
		std::cout << first_number << " is equal to " << second_number << std::endl;
	}


	return 0;
}

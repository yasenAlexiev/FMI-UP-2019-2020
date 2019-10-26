#include <iostream>

int main() {	
	const double min = -99.99;
	const double max = 99.99;

	double a, b, c;
	std::cout << "Enter your numbers: \n";	
	std::cin >> a >> b >> c;
	
	//first way
	if(a <= max && a >= min &&
	   b <= max && b >= min &&
	   c <= max && c >= min)
	{
		if(a < b && a < c) {
			if(b < c) {	
				std::cout << a << ", " << b << ", " << c << std::endl;
			} else {	
				std::cout << a << ", " << c << ", " << b << std::endl;
			}
		} else if(b < a && b < c) {	
			if(a < c) {	
				std::cout << b << ", " << a << ", " << c << std::endl;
			} else {	
				std::cout << b << ", " << c << ", " << a << std::endl;
			}
		} else {	
			if(a < b) {	
				std::cout << c << ", " << a << ", " << b << std::endl;
			} else {	
				std::cout << c << ", " << b << ", " << a << std::endl;
			}
		}	
	} else {	
		std::cout << "Number out of range!" << std::endl;
	}

	// second way
	/*
	double smallest, middle, greater;
	if(a <= max && a >= min &&
	   b <= max && b >= min &&
	   c <= max && c >= min)
	{
		if(a < b && a < c) {
			smallest = a;
			if(b < c) {		
				middle = b;
				greater = c;
			} else {	
				middle = c;
				greater = b;
			}
		} else if(b < a && b < c) {	
			smallest = b;
			if(a < c) {
				middle = a;
				greater = c;
			} else {
				middle = c;
				greater = a;
			}
		} else {
			smallest = c;
			if(a < b) {
				middle = a;
				greater = b;
			} else {
				middle = b;
				greater = a;
			}
		}
		std::cout << smallest << ", " << middle << ", " << greater << std::endl;
	} else {	
		std::cout << "Number out of range!" << std::endl;
	}
	*/
	return 0;
}

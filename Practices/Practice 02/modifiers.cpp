#include <iostream>
#include <iomanip>

void modifiers()
{
	std::cout << "Types and their respective sized:" << std::endl;
	std::cout << "char: " << sizeof(char) << std::endl;
	std::cout << "int: " << sizeof(int) << std::endl;
	std::cout << "float: " << sizeof(float) << std::endl;
	std::cout << "double: " << sizeof(double) << std::endl;
	std::cout << "bool: " << sizeof(bool) << std::endl;
	int x = 5;
	std::cout << sizeof(x) << std::endl; // can be used on variables too

	std::cout << std::endl;
	// What are the ranges of these variables?
	std::cout << std::scientific << "Min value for float: " << FLT_TRUE_MIN << std::endl << std::endl;

	std::cout << std::fixed << "Max value for float: " << FLT_MAX << std::endl << std::endl;
	
	std::cout << std::scientific << "Min value for double: " << DBL_TRUE_MIN << std::endl << std::endl;

	std::cout << std::fixed << "Max value for double: " << DBL_MAX << std::endl << std::endl;

	std::cout << std::scientific << "Max value for double: " << DBL_MAX << std::endl << std::endl;


	int x = INT32_MAX;
	int y = x;
	std::cout << "1.9b + 1.6b = " << x + y << std::endl << std::endl;

	signed int signedResult = x + y;
	unsigned int unsignedResult = x + y;
	std::cout << "1.9b + 1.6b = " << signedResult << " - signedResult" << std::endl << std::endl;
	std::cout << "1.9b + 1.6b = " << unsignedResult << " - unsignedResult" << std::endl << std::endl;

	std::cout << "unsignedResult + unsignedResult = " << unsignedResult + unsignedResult << std::endl << std::endl;

	signed int signedNumber = -5; // signed int is the same as int
	unsigned int unsignedNumber = -5;
	std::cout << "signedNumber = " << signedNumber << std::endl;
	std::cout << "unsignedNumber = " << unsignedNumber << std::endl;
	std::cout << "short int: " << sizeof(short int) << std::endl;
	std::cout << "int: " << sizeof(int) << std::endl;
	std::cout << "long int: " << sizeof(long int) << std::endl;
	std::cout << "long long int: " << sizeof(long long int) << std::endl << std::endl;

	// Integral types : char <= short int <= int <= long int <= long long int
	// short int is the same as int, the same is true for long, long long

	std::cout << "Long max: " << LONG_MAX << std::endl;
	std::cout << "unsigned long max: " << ULLONG_MAX << std::endl;
	std::cout << "long long max: " << LLONG_MAX << std::endl;
	std::cout << "unsigned long long max: " << ULLONG_MAX << std::endl;

	// signed <--> unsigned
	// short <--> long
}
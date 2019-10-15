//Create sizeOfTypes.cpp from Yasen Alexiev on 15.10.2019

#include <iostream>

int main() {
	// You can use sizeof() with types for argument
	std::cout << "sizeof(int): " << sizeof(int) << " byte(s)" << std::endl;	
	std::cout << "sizeof(char): " << sizeof(char) << " byte(s)" << std::endl;
	std::cout << "sizeof(float): " << sizeof(float) << " byte(s)" << std::endl;
	std::cout << "sizeof(double): " << sizeof(double) << " byte(s)" << std::endl;
	std::cout << "sizeof(bool): " << sizeof(bool) << " byte(s)" << std::endl;
	
	std::cout << std::endl;

	int x = 5;
	char c = 't';
	float f = 3.14;
	double d = 3.1415;
	bool boolean = true;

	//Or with variable
	std::cout << "sizeof(int): " << sizeof(x) << " byte(s)\n"; // this \n is sign for new line and that way you "told" on the output streamto pass on the next line on the console
	std::cout << "sizeof(char): " << sizeof(c) << " byte(s)\n";
	std::cout << "sizeof(float): " << sizeof(f) << " byte(s)\n";
	std::cout << "sizeof(double): " << sizeof(d) << " byte(s)\n";
	std::cout << "sizeof(bool): " << sizeof(boolean) << " byte(s)\n";
	std::cout << std::endl;

	//Also you can skip the brackets, but don't use it that way
	std::cout << "sizeof(int):\t" << sizeof x << " byte(s)" << std::endl;
	std::cout << "sizeof(char):\t" << sizeof c << " byte(s)" << std::endl;
	std::cout << "sizeof(float):\t" << sizeof f << " byte(s)" << std::endl;
	std::cout << "sizeof(double):\t" << sizeof d << " byte(s)" << std::endl;
	std::cout << "sizeof(bool):\t" << sizeof boolean << " byte(s)" << std::endl;
	// this \t is sign for tab, make one tab space on the console
	std::cout << std::endl;
	
	//More types and their size in bytes	
	std::cout << "sizeof(unsigned int): " << sizeof(unsigned int) << " byte(s)\n"
				 "sizeof(signed int): " << sizeof(signed int) << " byte(s)\n"
				 "sizeof(short int): " << sizeof(short int) << " byte(s)\n"
				 "sizeof(long int): " << sizeof(long int) << " byte(s)\n"
				 "sizeof(long long int): " << sizeof(long long int) << " byte(s)\n"
				 "sizeof(unsigned long long int): " << sizeof(unsigned long long int) << " byte(s)\n";
	std::cout << std::endl;

	std::cout << "sizeof(unsigned char): " << sizeof(unsigned char) << " byte(s)" << std::endl;	
	std::cout << "sizeof(long double): " << sizeof(long double) << " byte(s)" << std::endl;	


	//More information on:
	//https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm
	
	return 0;
}

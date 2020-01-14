#include <iostream>

typedef char* string;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int a = 8;
	int b = 37;
	int (*ptrF)(int, int);
	ptrF = max;
	std::cout << ptrF(a, b) << std::endl;
	std::cout << &ptrF << std::endl;	
	return 0;
}

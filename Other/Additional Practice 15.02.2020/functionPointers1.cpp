#include <iostream>

typedef void(*CallBackFuncPtr)(int&);

enum TypeInteger {
	Even		= 1,
	Odd			= 2,
	Positive	= 4,
	Negative	= 8
};

bool isEven(int x) {
	return !(x%2);
}

bool isOdd(int x) {
	return x%2;
}

bool isPositive(int x) {
	return x > 0;
}

bool isNegative(int x) {
	return x < 0;
}

void forEachElement(int* array, size_t size, CallBackFuncPtr cbp) {
	for(int i = 0; i < size; ++i) {
		cbp(array[i]);
	}
}

void forEachElement(int* array, size_t size, CallBackFuncPtr cbp, int whichOne) {
	bool forEven		= (whichOne & Even)		> 0;
	bool forOdd			= (whichOne & Odd)		> 0;
	bool forPositive	= (whichOne & Positive)	> 0;
	bool forNegative	= (whichOne & Negative)	> 0;
	
#if 0
	std::cout << forEven << std::endl;
	std::cout << forOdd << std::endl;
	std::cout << forPositive << std::endl;
	std::cout << forNegative << std::endl;
#endif
	for(int i = 0; i < size; ++i) {
		int copy = array[i];
		if(			forEven && isEven(copy) ) {
			cbp(array[i]);
		} else if(	forOdd && isOdd(copy) ) {	
			cbp(array[i]);
		} else if(	forPositive && isPositive(copy) ) {	
			cbp(array[i]);
		} else if(	forNegative && isNegative(copy) ) {
			cbp(array[i]);
		}
	}

	std::cout << std::endl;
}
void print(int& x) {
	std::cout << x << ' ';
}

void doubleIt(int& x) {
	x *= 2;
}

int main() {

	size_t size = 10;	
	int array[] = {-3, 1, 0, -10, 23, 2, 5, 37, 0, -5};

	{	
		CallBackFuncPtr out = print;
		std::cout << "\nEven numbers: " << std::endl;
		forEachElement(array, size, out, Even);
		std::cout << "\nOdd numbers: " << std::endl;
		forEachElement(array, size, out, Odd);
		std::cout << "\nPositive numbers: " << std::endl;
		forEachElement(array, size, out, Positive);
		std::cout << "\nNegative numbers: " << std::endl;
		forEachElement(array, size, out, Negative);

		std::cout << "\nPositive and odd numbers: " << std::endl;
		forEachElement(array, size, out, Positive | Odd);
		std::cout << "\nPositive and even numbers: " << std::endl;
		forEachElement(array, size, out, Positive | Even);
		std::cout << "\nNegative and odd numbers: " << std::endl;
		forEachElement(array, size, out, Negative | Odd);
	}

	{
		CallBackFuncPtr cbp = doubleIt;
		CallBackFuncPtr out = print;
		forEachElement(array, size, cbp);
		std::cout << "\nDouble every number in original array: " << std::endl;
		forEachElement(array, size, out);
	}



	return 0;
}

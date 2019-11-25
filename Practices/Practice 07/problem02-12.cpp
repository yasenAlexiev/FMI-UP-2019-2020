#include <iostream>
#include <limits.h>

#define MAX_SIZE 100

void swap(int& a, int& b) {
	int buff = a;
	a = b;
	b = buff;
}

//problem 02
void printArray(int array[], const unsigned short size) {
	for(int i = 0; i < size; ++i) {
		std::cout << array[i] << ' ';
	}
}

void fillArray(int array[], const unsigned short size) {
	for(int i = 0; i < size; ++i) {
		std::cin >> array[i];
	}
}

//problem 03
double getAverage(int array[], const unsigned short size) {
	double sum = 0;

	for(int i = 0; i < size; ++i) {
		sum += array[i];
	}
	return sum/size;
}

// problem 04
void sqrArray(int array[], const unsigned short size) {	

	for(int i = 0; i < size; ++i) {
		std::cout << array[i] * array[i] << ' ';
	}
}

// problem 05
void findOddsNumbers(int array[], const unsigned short size) {
	for(int i = 0; i < size; ++i) {
		if(array[i] % 2) {
			std::cout << array[i] << ' ';
		}
	}
}

// problem 06
void reverceArray(int array[], const unsigned short size) {
	for(int i = 0; i < size/2; ++i) {
		swap(array[i], array[size-1-i]);
	}
}

int min(const int& a, const int& b) {
	return ((a < b) ? a : b);
}

// problem 07
int findMinElement(int array[], const unsigned short size) {
	int minElement = array[0];

	for(int i = 1; i < size; ++i) {
		minElement = min(minElement, array[i]);
	}
	return minElement;
}

// problem 08
int findElementIndex(int array[], const unsigned short size, const int& elem) {

	for(int i = 0; i < size; ++i) {
		if(array[i] == elem) {
			return i;
		}	
	}

	return -1;
}

// problem 09
int findSecondMinElement(int array[], const unsigned short size) {
	int min1 = array[0];
	int min2 = INT_MAX;
	for(int i = 1; i < size; ++i) {
		if(array[i] < min1) {
			min2 = min1;
			min1 = array[i];
		}	
	}

	return min2;
}

//problem 10
int findDuplicateElement(int array[], const unsigned short size) {
	for(int i = 0; i < size-1; ++i) {
		for(int j = i+1; j < size; ++j) {
			if(array[i] == array[j]) {
				return array[i];
			}
		}
	}
}

//problems 11
int differenceOddsEvens(int array[], const unsigned short size) {
	int sumOdds = 0, sumEvens = 0;

	for(int i = 0; i < size; ++i) {
		if(array[i] % 2) {
			sumOdds += array[i];
		} else {
			sumEvens += array[i];
		}
	}

	return sumEvens - sumOdds;
}

// problem 12
void greaterThan(int array[], const unsigned short size) {
	bool greaterThan;
	for(int i = 0; i < size-1; ++i) {
		greaterThan = true;
		for(int j = i + 1; j < size; ++j) {
			if(array[i] <= array[j]) {
				greaterThan = false;
			}
		}
		if(greaterThan) {
			std::cout << array[i] << ' ';
		}	
	}
	std::cout << array[size-1];
}


int main() {
	int array[MAX_SIZE];
	unsigned short size;
	std::cin >> size;

	fillArray(array, size);
	printArray(array, size);

	double average = getAverage(array, size);
	std::cout << "\nAverage: " << average << std::endl;
	
	std::cout << "Square of every number in array are :" << std::endl;
	sqrArray(array, size);
	std::cout << std::endl;


	std::cout << "Odds number in array are:" << std::endl;
	findOddsNumbers(array, size);
	std::cout << std::endl;

	std::cout << "Reverse array is: " << std::endl;
	reverceArray(array, size);
	printArray(array, size);
	std::cout << std::endl;
	reverceArray(array, size); //reverce array again for working with original

	std::cout << "Min element: " << findMinElement(array, size) << std::endl << std::endl;	

	
	int elem;
	std::cout << "Enter element which you wanna find: " << std::endl;
	std::cin >> elem;
	std::cout << "Index is: " << findElementIndex(array, size, elem) << std::endl << std::endl;

	
	std::cout << "Second min element is: " << findSecondMinElement(array, size) << std::endl << std::endl;

	std::cout << "Duplicate element is: " << findDuplicateElement(array, size) << std::endl << std::endl;

	std::cout << "Difference of all odds and all evens number is: " << differenceOddsEvens(array, size) << std::endl << std::endl;

	std::cout << "All numbers which are greater than all numbers right of them: " << std::endl;
	greaterThan(array, size);


	
	return 0;
}

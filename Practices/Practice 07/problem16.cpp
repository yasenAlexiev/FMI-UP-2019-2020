#include <iostream>

#define MAX_SIZE (1<<10)

void fillArray(int array[], const unsigned size) {
	for(int i = 0; i < size; ++i) {
		std::cin >> array[i];
	}
}

void printArray(int array[], const unsigned size) {
	for(int i = 0; i < size; ++i) {
		std::cout << array[i] << ' ';
	}
}

void greatestK(int array[], const unsigned size, const unsigned k) {
	if(k > size) {
		return;
	}
	int maxIndex;
	for(int i = 0; i < k; ++i) {
		maxIndex = i;
		for(int j = i + 1; j < size; ++j) {
			if(array[j] > array[maxIndex]) {
				maxIndex = j;
			}
		}
		if(i != maxIndex) {
			std::swap(array[i], array[maxIndex]);
		}
	}

	printArray(array, k);
}

int main() {
	unsigned n, k;
	int array[MAX_SIZE];

	std::cin >> n;
	fillArray(array, n);
	std::cin >> k;

	greatestK(array, n, k);
	
	return 0;
}

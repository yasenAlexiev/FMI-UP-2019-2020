#include <iostream>

#define MAX_SIZE_OF_ROW 100

void printArray(int array[], size_t size) {
	for(int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	size_t n;
	std::cout << "Enter with row of Pascal Triangle witch you want to see: ";
	std::cin >> n;

	int row1[MAX_SIZE_OF_ROW] = { 0, };
	int row2[MAX_SIZE_OF_ROW] = { 0, };

	row1[0] = 1;
	int lastValue;
	for(int i = 1; i < n; ++i) {
		if(i % 2 == 0) {	
			for(int j = 1; j <= i; ++j) {
				row1[j] = row2[j] + row2[j-1];
			}
			printArray(row1, i);
		} else {	
			for(int j = 1; j <= i; ++j) {
				row2[j] = row1[j] + row1[j-1];
			}
			printArray(row2, i);
		}
	}

	return 0;
}

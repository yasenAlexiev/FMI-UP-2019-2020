#include <iostream>

#define MAX_SIZE 100

void fillArray(int numbers[], unsigned short size) {
	for(int i = 0; i < size; ++i) {
		std::cin >> numbers[i];
	}	
}

void findSumK(int numbers[], unsigned short size, int k) {
	int index1 = -1, index2 = -1;

	for(int i = 0; i < size-1; ++i) {
		for(int j = i+1; j < size; ++j) {
			if(numbers[i] + numbers[j] == k) {
				index1 = i;
				index2 = j;
			}
		}
	}
	std::cout << numbers[index1] << ' ' << numbers[index2] << std::endl;
}

int main() {
	int numbers[MAX_SIZE];
	unsigned short size;
	std::cin >> size;

	fillArray(numbers, size);

	int k;
	std::cin >> k;	

	findSumK(numbers, size, k);	

	return 0;
}

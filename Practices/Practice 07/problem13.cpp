#include <iostream>

#define MAX_SIZE (1<<10)

void fillArray(int array[], const unsigned size) {
	for(int i = 0; i < size; ++i) {
		std::cin >> array[i];
	}
}

bool exist(const int elem, const int array[], const unsigned size) {
	
	for(int i = 0; i < size; ++i) {
		if( array[i] == elem ) {
			return true;
		}
	}
	return false;
}

void intersect(int array1[], int array2[], const unsigned size1, const unsigned size2) {
	for(int i = 0; i < size1; ++i) {
		if(exist(array1[i], array2, size2)) {
			std::cout << array1[i] << ' ';
		}
	}		
}

int main() {
	unsigned n, m;	
	int array1[MAX_SIZE];
	int array2[MAX_SIZE];
	
	std::cin >> n;
	fillArray(array1, n);

	std::cin >> m;
	fillArray(array2, m);

	intersect(array1, array2, n, m);
	
	return 0;
}

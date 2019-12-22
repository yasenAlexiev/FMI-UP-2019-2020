#include <iostream>

void deleteMatrix(int** matrix, size_t rows) {
	for(int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int** allocateMatrixByRowsAndCols(size_t n, size_t m) {
	int** matrix = new (std::nothrow) int* [n];
	if(matrix == nullptr) { // if operator new can't allocate memory on the heap
		return nullptr;		// return nullptr pointer. But for this, we should write
	}						// option (std::nothrow) after operator new!

	for(size_t i = 0; i < n; ++i) {
		matrix[i] = new (std::nothrow) int[m]; // same stuff here
		if(matrix[i] == nullptr) { // if operator new return nullptr, we should
			deleteMatrix(matrix, i); // clean all dynamic memory which we allocate before
			return nullptr;			// this moment, and return nullptr
		}
	}
	return matrix; // if all dynamic memory is allocate correctly, we return pointer
					// to this memory
}


int main() {
	size_t n, m;
	std::cin >> n >> m;
	int** matrix = allocateMatrixByRowsAndCols(n, m);

	if(matrix != nullptr) {	
		// do stuff with matrix
	}
	

	if(matrix != nullptr) {
		deleteMatrix(matrix, n);
	}

	return 0;
}

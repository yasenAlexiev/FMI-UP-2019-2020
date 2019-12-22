#include <iostream>
#include <iomanip> //std::setw()
#include <math.h> // std::log10()

#define MAX_ROWS (16)
#define MAX_COLS (16)

unsigned int find_max_element(unsigned int mat[][MAX_COLS], size_t n, size_t m) {
	
	unsigned int max_element = mat[0][0];

	for (size_t row = 0; row < n; row++) {
		for (size_t col = 0; col < m; col++) {
			if (max_element < mat[row][col]) {	// if we find bigger than current maximum
				max_element = mat[row][col];	// we take it's value
			}
		}
	}
	return max_element;
}

int find_max_cell_size(unsigned int mat[][MAX_COLS], size_t n, size_t m) {
	unsigned int max_element = find_max_element(mat, n, m);

	return ((int)log10(max_element) + 1) + 1;
}
	

void fill_matrix(unsigned int mat[][MAX_COLS], size_t n, size_t m) {

	for (size_t row = 0; row < n; row++) {
		for (size_t col = 0; col < m; col++) {
			std::cin >> mat[row][col];
		}
	}
}


void print_matrix(unsigned int mat[][MAX_COLS], size_t n, size_t m) {

    int cell_size = find_max_cell_size(mat, n, m);
	for (size_t row = 0; row < n; row++) {
		for (size_t col = 0; col < m; col++) {
			std::cout << std::setw(cell_size) << mat[row][col] << ' ';
		}
		std::cout << std::endl; // to separate the rows of the matrix
	}
}

void print_frame(unsigned int mat[][MAX_COLS], size_t n, size_t m) {
	
	int cell_size = find_max_cell_size(mat, n, m);
	for (size_t row = 0; row < n; row++) {
		for (size_t col = 0; col < m; col++) {
			if((row == 0 || row == n - 1) || (col == 0 || col == m - 1)) {
				std::cout << std::setw(cell_size) << mat[row][col] << ' ';
			} else {
				std::cout << std::setw(cell_size + 1) << ' ';
			}
		}	
		std::cout << std::endl;
	}
}


int main() {
	unsigned int n, m;

	std::cin >> n >> m;

	if (m >= MAX_ROWS || n >= MAX_COLS) {
		std::cout << "Error: can't handle such a big matrix!" << std::endl;
		return -1; // here we are exiting our program with error code -1
	}

	unsigned int matrix[MAX_ROWS][MAX_COLS];		// allocating enough memory

	fill_matrix(matrix, n, m);
	std::cout << std::endl;
	print_matrix(matrix, n, m);

	std::cout << std::endl;

	print_frame(matrix, n, m);


	return 0;
}

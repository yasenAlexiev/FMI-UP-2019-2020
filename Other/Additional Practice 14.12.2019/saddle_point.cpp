#include <iostream>

void fill_matrix(int mat[][MAX_COLS], size_t n, size_t m) {

	for (size_t row = 0; row < n; row++) {
		for (size_t col = 0; col < m; col++) {
			std::cin >> mat[row][col];
		}
	}
}

void print_matrix(int mat[][MAX_COLS], size_t n, size_t m) {

	for (size_t row = 0; row < n; row++) {
		for (size_t col = 0; col < m; col++) {
			std::cout << mat[row][col];
		}
		std::cout << std::endl;
	}
}

bool is_max_in_row(int mat[][MAX_COLS], int elem, size_t current_row, size_t cols) {
	for(int i = 0; i < cols; ++i) {
		if(mat[current_row][i] > elem) {
			return false;
		}
	}
	return true;
}

void saddle_point(int mat[][MAX_COLS], size_t rows, size_t cols) {
	
	for (size_t row = 0; row < n; row++) {
		for (size_t col = 0; col < m; col++) {
		
		}
	}
}

int main() {
	fill_matrix(matrix, n, m);
	std::cout << std::endl;
	print_matrix(matrix, n, m);
	
	saddle_point(matrix, n, m);
	

	return 0;
}

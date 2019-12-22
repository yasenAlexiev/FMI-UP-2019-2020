#include <iostream>

#define MAX_COLS (16)
#define MAX_ROWS (16)


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
			std::cout << mat[row][col] << ' ';
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

bool is_min_in_col(int mat[][MAX_COLS], int elem, size_t current_col, size_t rows) {
	for(int i = 0; i < rows; ++i) {
		if(mat[i][current_col] < elem) {
			return false;
		}
	}
	return true;
}
void saddle_point(int mat[][MAX_COLS], size_t n, size_t m) {
	
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			if(is_max_in_row(mat, mat[i][j], i, m) &&
			   is_min_in_col(mat, mat[i][j], j, n))
			{	
				std::cout << "The saddle point is: matrix(" <<
					i << ", " << j << ") = " << mat[i][j] << std::endl;
				return;
			}	
		}
	}
	// if we reach here there isn't a saddle point
	std::cout << "There isn't a saddle point in the given matrix!!!" << std::endl;
}

int main() {
	unsigned n, m;
	std::cin >> n >> m;

	if(n >= MAX_ROWS || m >= MAX_COLS) {
		std::cout << "Invalid input" << std::endl;
		return -1;
	}

	int matrix[MAX_ROWS][MAX_COLS];

	fill_matrix(matrix, n, m);
	std::cout << std::endl;
	print_matrix(matrix, n, m);
	
	saddle_point(matrix, n, m);
	

	return 0;
}

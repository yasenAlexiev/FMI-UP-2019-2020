#include <iostream>

#define MAX 100

void fillMatrix(int matrix[][MAX], unsigned rows, unsigned cols) {
	
	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < cols; ++j) {
			std::cin >> matrix[i][j];
		}
	}
}

int sumOfRow(int matrix[][MAX], unsigned index, unsigned cols) {
	int sum = 0;
	for(int i = 0; i < cols; ++i) {
		sum += matrix[index][i];	
	}
	return sum;
}

int sumOfCol(int matrix[][MAX], unsigned index, unsigned rows) {
	int sum = 0;
	for(int i = 0; i < rows; ++i) {
		sum += matrix[i][index];	
	}
	return sum;
}

bool hasMagicRows(int matrix[][MAX], unsigned rows, unsigned cols) {
	int sumsOfEveryRow[MAX];

	for(int i = 0; i < rows; ++i) {
		sumsOfEveryRow[i] = sumOfRow(matrix, i, cols);
	}

	for(int i = 0; i < rows - 1; ++i) {
		if(sumsOfEveryRow[i] != sumsOfEveryRow[i + 1]) {
			return false;
		}
	}
	return true;
}

bool hasMagicCols(int matrix[][MAX], unsigned rows, unsigned cols) {
	int sumsOfEveryCol[MAX];

	for(int i = 0; i < cols; ++i) {
		sumsOfEveryCol[i] = sumOfCol(matrix, i, rows);
	}

	for(int i = 0; i < cols - 1; ++i) {
		if(sumsOfEveryCol[i] != sumsOfEveryCol[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int matrix[MAX][MAX];
	unsigned N, M;
	std::cout << "Enter size of matrix: ";
	std::cin >> N >> M;

	fillMatrix(matrix, N, M);

	std::cout << (hasMagicRows(matrix, N, M) ? "Has Magic Rows!" : "Not magic-row-matrix" ) << std::endl;
	std::cout << (hasMagicCols(matrix, N, M) ? "Has Magic Cols!" : "Not magic-col-matrix" ) << std::endl;

	return 0;
}

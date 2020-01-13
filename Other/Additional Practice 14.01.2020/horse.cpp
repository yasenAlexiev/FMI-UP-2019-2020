#include <iostream>

using namespace std;

#define TABLE_SIZE 10
#define SIZE_DIFF 8

bool table[TABLE_SIZE][TABLE_SIZE];
int diff_X[SIZE_DIFF] = {-1, -1, 1, 1, -2, -2, 2, 2};
int diff_Y[SIZE_DIFF] = {2, -2, -2, 2, 1, -1, -1, 1};
bool hasSolution = false;

bool inArray(int x, int y, int size) {
	return ((x >= 0) && (x < size) && (y >= 0) && (y < size));
}

void printMatrix() {
	for(int i = 0; i < TABLE_SIZE; i++) {
		for(int j = 0; j < TABLE_SIZE; j++) {
			cout << "|" << ((table[i][j]) ? "*" : " ");
		}
		cout << endl;
	}
}

void horseMovement(int horsePos_x, int horsePos_y, int size) {
	table[horsePos_x][horsePos_y] = true;
	printMatrix();	
	for (int i = 0; i < size && !hasSolution; i++) {
		for (int j = 0; j < size; j++) {
			if (table[i][j])
				hasSolution = true;
			else
				hasSolution = false;
		}
	}

	for (int i = 0; i < SIZE_DIFF; i++) {
		int next_x = horsePos_x + diff_X[i];
		int next_y = horsePos_y + diff_Y[i];
		if ((!table[next_x][next_y]) && inArray(next_x, next_y, size)) {
			horseMovement(next_x, next_y, size);
		}
	}
	if (hasSolution)
		return;
	else
		table[horsePos_x][horsePos_y] = false;
}


int main() {
	for(int i = 0; i < TABLE_SIZE; i++) {
		for(int j = 0; j < TABLE_SIZE; j++) {
			table[i][j] = false;
			cout << "|" << ((table[i][j]) ? "*" : " ");
		}
		cout << endl;
	}
	int size;
	cin >> size;
	int horse_x, horse_y;
	cin >> horse_x >> horse_y;
	horseMovement(horse_x, horse_y, size);
	
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << "|" << ((table[i][j]) ? "*" : " ");
				}
				cout << "|" << endl;
			}
	bool allCellVisit = true;
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if (!(table[i][j])) {
				allCellVisit = false;
				break;
			}
		}
	}

	cout << ((allCellVisit) ? "True" : "False") << endl;

	return 0;
}

#include <iostream>

bool less(int a, int b) {
	return a < b;
}

bool greater(int a, int b) {
	return a > b;
}

bool sameSign(int a, int b) {
	return a*b > 0;
}

typedef bool(*Comparator)(int, int);
typedef bool(*SameSign)(int, int);

void sortWithFunction(int* array, size_t size, Comparator compare = less) {
	for(int i = 0; i < size - 1; ++i) {
		int index = i;
		for(int j = i + 1; j < size; ++j) {
			if(compare(array[j], array[index])) {
				index = j;
			}
		}
		if(index != i) {
			std::swap(array[i], array[index]);
		}
	}
}

void print(int* array, size_t size) {
	for(int i = 0; i < size; ++i) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
}

int main() {
	Comparator ascending = less;	
	Comparator descending = greater;		

	SameSign eq = sameSign;
	{
		Comparator asc = less;
		std::cout << "Address of less() function from 'ascending' instance is: " << &ascending << std::endl;
		std::cout << "Address of less() function from 'asc' instance is: " << &ascending << std::endl;
		std::cout << "\nAddress of greater() function from 'descending' instance is: " << &descending << std::endl;
		std::cout << "\nAddress of sameSign() function from 'eq' instance is: " << &eq << std::endl;

	}

	
	

	size_t size = 10;	
	int array[] = {4, 2, 1, 0, -10, 3, -2, 2, 2, -4, 21};
	
	std::cout << "\nArray: " << std::endl;
	print(array, size);

	sortWithFunction(array, size);
	std::cout << "\nAscending:" << std::endl;
	print(array, size);

	sortWithFunction(array, size, descending);
	std::cout << "\nDescending:" << std::endl;
	print(array, size);

	return 0;
}

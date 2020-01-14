#include <iostream>

int* array;
size_t size;
size_t capacity;

//info for cerr
//http://www.cplusplus.com/reference/iostream/cerr/
//http://www.cplusplus.com/forum/beginner/72020/

void init_array() {
	size = 0;
	capacity = 2;
	array = new (std::nothrow)int[capacity];
	if(array == NULL) {
		std::cerr << "Invalid allocation memory" << std::endl;
	}
}

void init_array_with_capacity(size_t newCapacity) {
	size = 0;
	capacity = newCapacity;
	array = new (std::nothrow)int[capacity];
	if(array == NULL) {
		std::cerr << "Invalid allocation memory" << std::endl;
	}
}

void destroy() {
	size = 0;
	capacity = 0;
	delete[] array;
	array = NULL;
}

void resize() {
	int* temp = new (std::nothrow) int[capacity*2];
	if(temp) {	
		for(int i = 0; i < size; ++i) {
			temp[i] = array[i];
		}	
		delete[] array;
		array = temp;
		capacity *= 2;

	} else {	
		std::cerr << "Invalid allocation memory" << std::endl;
	}
}

void push_back(int elem) {
	if(size >= capacity) {
		resize();
	}
	array[size] = elem;
	++size;
}

size_t getSize() {
	return size;
}

bool empty() {
	return size == 0;
}

void pop_back() {
	if(!empty()) {	
		--size;
	} else {
		std::cerr << "Error! Dynamic array is empty" << std::endl;
	}
}

void insert(int elem, size_t index) {
	if(size >= capacity) {
		resize();
	}
	if(index < size) {
		for(int i = size; i > index; --i) {
			array[i] = array[i-1];
		}
		array[index] = elem;
		++size;
	} else {
		push_back(elem);	
	}
}

void erase_keeping_order(size_t index) {
	if(index < size) {
		for(int i = index; i < size - 1; ++i) {
			array[i] = array[i+1];
		}
		--size;
	} else {
		std::cerr << "Index out of bound" << std::endl;
	}
}

void erase_not_keeping_order(size_t index) {
	if(index < size) {
		std::swap(array[index], array[size-1]);
		--size;
	} else {
		std::cerr << "Index out of bound" << std::endl;
	}
}


void print() {
	for(int i = 0; i < size; ++i) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
}

int getElem(size_t index) {
	if(index < size) {
		return array[index];
	} else {
		std::cerr << "Index out of bound" << std::endl;
	}
}


int main() {
	std::cout << "Initialize array with capacity 8" << std::endl;
	init_array_with_capacity(8);
	std::cout << std::endl;
	for(int i = 0; i < 10; ++i) {
		if(i%2) {	
			push_back(i);	
			std::cout << "Push back: " << i << std::endl;
		} else {		
			push_back(-i);
			std::cout << "Push back: " << -i << std::endl;
		}
	}
	std::cout << "\nItarate array: " << std::endl;	
	for(int i = 0; i < getSize(); ++i) {
		std::cout << getElem(i) << ' ';
	}
	std::cout << std::endl;
	
	std::cout << "\nInsert element 37 on index 8" << std::endl;
	insert(37, 8);
	
	print();
	
	std::cout << "\nErase element on index 2 and keeping order in array" << std::endl;
	erase_keeping_order(2);

	print();
	
	std::cout << "\nErase element on index 5 without keeping order in array" << std::endl;
	erase_not_keeping_order(5);

	print();

	std::cout << "\nTry to erase elemet on index 10 but fail..." << std::endl;
	erase_keeping_order(10);

	print();

	std::cout << "\nDestroy array" << std::endl;
	destroy();


	return 0;
}

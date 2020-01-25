#include <iostream>

#define MAX_SIZE (100)

void countPairsRecursive(char* text, int& count) {
	if(!*(text+1)) {
		return;
	}

	if(*(text-1) == *(text+1)) {
		++count;
	}
	countPairsRecursive(text+1, count);
}

//task2
int countPairs(char * text) {
	int count = 0;
	countPairsRecursive(text+1, count);
	return count;
}

int main() {

	char str[MAX_SIZE];

	std::cin >> str;

	std::cout << countPairs(str) << std::endl;


	return 0;
}

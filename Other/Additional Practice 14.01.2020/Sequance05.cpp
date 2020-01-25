#include <iostream>
#include <string.h>

#define MAX_SIZE (100)

bool isFirstNthEqual(char* str1, char* str2, size_t N) {
	size_t count = 0;
	while(*str1 && *str2 && *str1 == *str2) {
		++str1; ++str2; ++count;
	}

	return N <= count;
}

int strCountRecursive(char* string, char* substring, size_t length, size_t count = 0) {
	if(!*string) {
		return count;
	}
	if(isFirstNthEqual(string, substring, length)) {
		++count;
	}
	return strCountRecursive(string+1, substring, length, count);
}

int strCount(char* string, char* substring) {
	size_t length = strlen(substring);
	if(strlen(string) < length) {
		return 0;
	}
	if(strcmp(string, substring) == 0) {
		return 1;
	}
	return strCountRecursive(string, substring, length);
}

int main() {
	
	char string[MAX_SIZE];
	char substring[MAX_SIZE];

	std::cin >> string >> substring;

	std::cout << strCount(string, substring) << std::endl;

	return 0;
}

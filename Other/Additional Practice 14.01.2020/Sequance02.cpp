#include <iostream>

#define MAX_SIZE (100)

//task 2
int countHi(char* text, int count = 0) {
	if(!*text) {
		return count;
	}

	if(*text == 'h' && *(text+1) == 'i') {
		return countHi(text+2, count+1);
	} else {
		return countHi(text+1, count);
	}

}

//task 3
void changeXY(char* source, char* destination) {
	if(!*source) {
		*destination = '\0';
		return;
	}

	if(*source == 'x') {
		*destination = 'y';
	} else {
		*destination = *source;
	}
	changeXY(source+1, destination+1);
}

int main() {

	char str[MAX_SIZE];
	char dest[MAX_SIZE];

	std::cin >> str;

	std::cout << countHi(str) << std::endl;
	
	changeXY(str, dest);

	std::cout << dest << std::endl;

	return 0;
}

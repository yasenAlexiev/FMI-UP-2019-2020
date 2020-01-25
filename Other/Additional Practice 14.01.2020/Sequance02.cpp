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


int main() {

	char str[MAX_SIZE];

	std::cin >> str;

	std::cout << countHi(str) << std::endl;
	
	return 0;
}

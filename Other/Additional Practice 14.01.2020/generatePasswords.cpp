#include <iostream>

/*
Разбиване на парола - по подадена дължина на паролата, генерирайте всички
възможни стрингове с тази дължина, съставени от малки и главни латински букви.
*/


bool isLetter(char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void generate(int length, char* pass, int index) {
	if(index == length) {
		pass[index] = '\0';
		std::cout << pass << std::endl;
		return;
	}
	for(char c = 'A'; c <= 'z'; ++c) {
		if(isLetter(c)) {
			pass[index] = c;	
			generate(length, pass, index+1);
		}
	}
}

void generatePass(int length) {
	char* pass = new char[length+1];
	generate(length, pass, 0);	
	delete[] pass;
}

int main() {
	
	generatePass(2);

	return 0;
}

#include <iostream>

#define MAX_SIZE (100)

//task 1
unsigned fibonacci(unsigned n) {
	if(n < 2) {
		return n;
	}

	return fibonacci(n-1) + fibonacci(n-2);
}

//task 2, version 1
unsigned pow1(unsigned base, unsigned power) {
	if(base == 0 || base == 1) {
		return base;
	}
	if(power == 0) {
		return 1;
	}
	if(power == 1) {
		return base;
	}

	return base * pow1(base, power-1);
}

// task 2, version 2, this is the faster way
unsigned pow2(unsigned base, unsigned power) {	
	if(base == 0 || base == 1) {
		return base;
	}
	if(power == 0) {
		return 1;
	}
	if(power == 1) {
		return base;
	}

	if(power%2 == 0) {
		unsigned res = pow2(base, power/2);
		return res*res;
	} else {
		return base * pow2(base, power-1);
	}
}

//task 3
void removeX(char * source, char * destination) {
	if(!*source) {
		return;
	}
	
	if(*source == 'X') {
		removeX(source+1, destination);
	} else {
		*destination = *source;
		removeX(source+1, destination+1);
	}
}

void cleanSingleLetter(char* text) {
	if(!*text) {
		return;
	}
	*text = *(text+1);
	cleanSingleLetter(text+1);
}

//task 4
void cleanText(char * text) {
	if(!*text) {
		return;
	}

	if(*text == *(text+1)) {
		cleanSingleLetter(text);
		cleanText(text);
	} else {	
		cleanText(text+1);
	}	

}


int main () {
	unsigned number;
	std::cin >> number;
	std::cout << number << " fibonacci number is: " << fibonacci(number) << std::endl;

	unsigned base, power;
	std::cin >> base >> power;
	std::cout << "pow1(" << base << ", " << power << ") = " << pow1(base, power) << std::endl;
	std::cout << "pow2(" << base << ", " << power << ") = " << pow2(base, power) << std::endl;

	char src[MAX_SIZE];
	char dest[MAX_SIZE] = {'\0', };
	
	std::cin >> src;

	removeX(src, dest);

	std::cout << dest << std::endl;

	cleanText(src);
	std::cout << src << std::endl;

	return 0;
}

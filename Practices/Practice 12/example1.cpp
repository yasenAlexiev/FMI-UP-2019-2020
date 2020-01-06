#include <iostream>
#include <string.h>

int main() {
	char str[] ="- This, a sample string.";
	char * pch;
	std::cout << "Splitting string \"" << str << "\" into tokens:\n";
	pch = strtok (str," ,.-");
	while (pch != NULL) {
		std::cout << pch << std::endl;
		pch = strtok (NULL, " ,.-");
	}

	return 0;
}

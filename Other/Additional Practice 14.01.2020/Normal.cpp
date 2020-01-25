#include <iostream>

#define MAX_SIZE (100)

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



int main () {
	
	char src[MAX_SIZE];
	char dest[MAX_SIZE] = {'\0', };
	
	std::cin >> src;

	removeX(src, dest);

	std::cout << dest << std::endl;


	return 0;
}

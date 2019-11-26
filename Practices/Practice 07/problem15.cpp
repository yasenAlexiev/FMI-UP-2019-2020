#include <iostream>

#define MAX_SIZE (1<<12)

int main() {
	bool array[MAX_SIZE];

	unsigned n;
	std::cin >> n;

	for(int i = 0; i < n; ++i) {
		array[i] = true;	
	}	

	array[0] = array[1] = false;
	for(int i = 2; i < n/2; ++i) {
		if(array[i]) {
			for(int j = i*2; j < n; j += i) {
				array[j] = false;
			}
		}	
	}
	int number;
	while(true) {
		std::cin >> number;

		if(number == -1) {
			break;
		}
		if(number < n) {
			std::cout << ((array[number]) ? "Is prime" : "Not prime") << std::endl;
		} else {
			std::cout << "Invalid number" << std::endl;
		}
	}

	return 0;
}

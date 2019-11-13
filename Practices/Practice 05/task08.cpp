#include <iostream>

int main() {
	unsigned n;
	std::cin >> n;
	unsigned prod = 1;
	for(int i = 1; i <= n; ++i) {
		prod *= i;
	}

	std::cout << prod << std::endl;
	
	return 0;
}

#include <iostream>

int main() {
	unsigned short n;
	std::cin >> n;

	for(int i = 1; i <= n; ++i) {
		std::cout << i*i << " ";
	}

	return 0;
}

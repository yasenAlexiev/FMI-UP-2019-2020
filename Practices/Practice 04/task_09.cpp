#include <iostream>

int main() {
	unsigned short n;
	std::cin >> n;
	
	unsigned short mask = 1 << (sizeof(unsigned short) * 8 - 1);
	while( mask > 0 ) {
		std::cout << ((n & mask) ? 1 : 0);	
		mask >>= 1;	
	}

	return 0;
}

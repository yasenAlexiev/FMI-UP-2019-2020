#include <iostream>


int main() {
	//just like in task 5
	const unsigned short numberOfBits = sizeof(unsigned long) * 8;	// 64 bits usually
	unsigned long a;
	unsigned short b;

	std::cin >> a >> b;

	unsigned long mask = (1 << (numberOfBits - b)) - 1;
	//mask = 0000....0001000....00000 // 1 on index (numberofBits - b)
	//and then we subtract 1 and bits will be 00000..00001111..11111
	unsigned long buff = a & mask; // copy right bits in buff
	buff <<= b; // shift them to left
	a >>= (numberOfBits - b); // shift left bits on A to right

	a |= buff; // and finally return bits in buff on the left side on A

	std::cout << a;

	return 0;
}

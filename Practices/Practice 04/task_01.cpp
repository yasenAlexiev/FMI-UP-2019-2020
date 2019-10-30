#include <iostream>

int main()
{
	// int is 4 bytes -> 32 bits, unsigned modifier makes it only positive.
	// In other words, without a sign.
	// Since b is in the range [0, 31], we use short to save memory.
	unsigned int a;
	short int b;

	std::cout << "Please enter a, b: ";
	std::cin >> a >> b;

	// Initialize the mask with only 1 rightmost bit set to 1.
	// mask here looks like 00...001 - 32 symbols overall.
	unsigned int mask = 1;

	// Shift the single leftmost bit b times to the left.
	// If b = 3, mask = 00...001000 after this operation.
	// another way to intilialize the mask would be:
	// mask = pow(2, b) - this is what we're essentially doing with the code below.
	mask = (mask << b);

	// We use the properties of bitwise AND - &:
	// 0 & x = 0, where x = 0 or x = 1;
	// 1 & x = x, where x = 0 or x = 1;
	// The mask looks something like 000..010..00
	// So the result of (a & mask) will look like 000..0x0..00,
	// where x = 0 or x = 1 depending on the value of a.
	// Don't forget the parenthesis or thing may get weird.
	if ((a & mask) > 0)
	{
		std::cout << 1;
	}
	else
	{
		std::cout << 0;
	}

	std::cout << std::endl;
	return 0;
}

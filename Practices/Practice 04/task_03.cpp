#include <iostream>

int main()
{
	unsigned int a;
	short int n;

	std::cout << "Please enter a, n: ";
	std::cin >> a >> n;

	unsigned int mask = 1;

	// The mask looks something like 000..1..00
	mask = (mask << n);

	// We use the properties of bitwise OR - & stated in task_01.cpp
	// but instead of having the mask 000..1..0,
	// we need the mask to be 111..0..11 (we do that with the bitwise negation operator).
	// Here we use the properties of the & operator:
	// 0 & x = 0, where x can be either 0 or 1.
	// 1 & x = x. => Since the mask is 111..0..11, all bits in a are left as they are, and the bit which
	// is a zero in the mask is converted to a zero i.e. the n-th bit is unset.
	unsigned int result = a & (~mask);

	std::cout << result << std::endl;

	return 0;
}
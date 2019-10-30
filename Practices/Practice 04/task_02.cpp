#include <iostream>

int main()
{
	unsigned int a;
	short int n;

	std::cout << "Please enter a, n: ";
	std::cin >> a >> n;

	unsigned int mask = 1;

	mask = (mask << n);

	// We use the properties of bitwise OR - |:
	// 0 | x = x, where x = 0 or x = 1;
	// 1 | x = 1, where x = 0 or x = 1;
	// The mask looks something like 000..010..00
	// So the result of (a | mask) will be exactly the same as a,
	// but with the n-th bit set.
	unsigned int result = a | mask;

	std::cout << result << std::endl;

	return 0;
}


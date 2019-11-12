#include <iostream>

void f(int x, int y, int z) // same names as in main(), but
					//they are copies. Same values in varibles, but on
					//different place in memory(different address)
{	
	std::cout << "\nIn f():" << std::endl;
	++x; ++y; ++z; // change copies
	//and the copies have different address from main varibles
	std::cout << "Address of x: " << &x << ", value: " << x << std::endl;
	std::cout << "Address of y: " << &y << ", value: " << y << std::endl;
	std::cout << "Address of z: " << &z << ", value: " << z << std::endl;
}

void g(int& a, int& b, int& c) // pass arguments by reference
						// they are exactly the same varible
						// no matter if they have different name

{
	std::cout << "\nIn g():" << std::endl;
	++a; ++b; ++c; // change main varibles
	//and the arguments of function have exactly the same address such as
	//the main varibles
	std::cout << "Address of a: " << &a << ", value: " << a << std::endl;
	std::cout << "Address of b: " << &b << ", value: " << b << std::endl;
	std::cout << "Address of c: " << &c << ", value: " << c << std::endl;
}

int main() {
	int x, y, z;
	std::cin >> x >> y >> z;
	
	std::cout << "\nIn main(): \n";
	std::cout << "Address of x: " << &x << ", value: " << x << std::endl;
	std::cout << "Address of y: " << &y << ", value: " << y << std::endl;
	std::cout << "Address of z: " << &z << ", value: " << z << std::endl;

	f(x, y, z);

	std::cout << "\nIn main(): \n";
	std::cout << "Address of x: " << &x << ", value: " << x << std::endl;
	std::cout << "Address of y: " << &y << ", value: " << y << std::endl;
	std::cout << "Address of z: " << &z << ", value: " << z << std::endl;

	g(x, y, z);

	std::cout << "\nIn main(): \n";
	std::cout << "Address of x: " << &x << ", value: " << x << std::endl;
	std::cout << "Address of y: " << &y << ", value: " << y << std::endl;
	std::cout << "Address of z: " << &z << ", value: " << z << std::endl;

	return 0;
}

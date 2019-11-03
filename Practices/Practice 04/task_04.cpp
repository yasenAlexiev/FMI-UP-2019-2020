#include <iostream>


int main() {
	unsigned long int a;
	unsigned short x, y;

	std::cin >> a >> x >> y;

	unsigned maskX = 1 << x; // maskX = 0000...0001000..0000 // 1 on position X
	unsigned maskY = 1 << y; // maskY = 0000...0001000..0000 // 1 on position Y

	bool isSetX; // true if have set bit on position X; false - otherwise
	if( (a & maskX) != 0 ) { // a & maskX will be 0 if bit on index X is unset(0) and != 0 if is't set(1)
		isSetX = true;
	} else {
		isSetX = false;
	}

	bool isSetY; // true if have set bit on position Y; false - otherwise
	if( (a & maskY) != 0 ) { // a & maskY will be 0 if bit on index Y is unset(0) and != 0 if is't set(1)
		isSetY = true;
	} else {
		isSetY = false;
	}

	if( isSetX ) { // if the bit on position X is set(1)
		a = a | maskY; // we set bit on position Y to 1
	} else { // otherwise
		a = a & ~maskY; // set 0 on position Y
	}

	if( isSetY ) { // if the bit on index Y is set(1)
		a = a | maskX; // we set 1 on position X
	} else { // otherwise
		a = a & ~maskX; // set 0 on index X
	}

	/* Or you can use magic :)

	bool isSetX = (a & maskX) != 0;	
	bool isSetY = (a & maskY) != 0;

	a = (( isSetX ) ? a | maskY : a & ~maskY);
	a = (( isSetY ) ? a | maskX : a & ~maskX);
	
	*/

	std::cout << a;

	return 0;
}

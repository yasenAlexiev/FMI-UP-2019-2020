#include <iostream>
#include <math.h>

int main() {
	const int top = 3;
	const int bottom = -3;
	const int left = -5;
	const int right = 5;

	const int centerX = 3;
	const int centerY = 2;
	const unsigned int radius = 4;

	const unsigned int mushroom_radius = 5;
	const int bottom_mushroom = -3;
	const int left_mushroom = -2;
	const int right_mushroom = 2;
	
	double x, y;
	std::cout << "Enter coordinates of point: " << std::endl;
	std::cin >> x >> y;

	if(x <= right && x >= left && y <= top && y >= bottom) {		
		std::cout << "Point in rectangle!" << std::endl;
	} else {
		std::cout << "Point out of rectangle!" << std::endl;	
	}

	if( pow( x - centerX, 2 ) + pow( y - centerY, 2 ) <= radius * radius ) {	
		std::cout << "Point in circle!" << std::endl;
	} else {	
		std::cout << "Point out of circle!" << std::endl;
	}

	if( (y >= 0 && (x * x + y * y <= mushroom_radius * mushroom_radius ) ) ||
		(y < 0  && y <= bottom_mushroom && x >= left_mushroom && x <= right_mushroom) ) {	
		std::cout << "Point in mushroom!" << std::endl;
	} else {	
		std::cout << "Point out of mushroom!" << std::endl;
	}

	return 0;
}

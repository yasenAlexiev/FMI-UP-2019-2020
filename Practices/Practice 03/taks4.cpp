#include <iostream>
#include <math.h>

int main() {
	int x1, y1, x2, y2;
	std::cout << "Enter coordinates of two points: \n";
	std::cin >> x1 >> y1 >> x2 >> y2;
	
	double distance = sqrt( pow( (x2 - x1), 2 ) + pow( (y2 - y1), 2) );
	std::cout << distance << std::endl;

	//or
	//std::cout << sqrt( pow( (x2 - x1), 2 ) + pow( (y2 - y1), 2) ) << std::endl;
	
	return 0;
}

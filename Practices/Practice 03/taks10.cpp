#include <iostream>
#include <math.h>

int main() {
	const unsigned big_radius = 6;
	const unsigned middle_radius = 3;
	const unsigned small_radius = 1;
	
	const int left_center_x = -3;	
	const int right_center_x = 3;	
		
	double x, y;
	std::cout << "Enter coordinated of point: " << std::endl;
	std::cin >> x >> y;

	double distance_between_point_and_left_center = sqrt( pow(left_center_x - x, 2) + pow(y, 2) );
	double distance_between_point_and_right_center = sqrt( pow(right_center_x - x, 2) + pow(y, 2) );


	if( x * x + y * y <= big_radius * big_radius ) {
		if( x > 0) {
			if( (distance_between_point_and_left_center < small_radius ||
				 distance_between_point_and_left_center > middle_radius) &&
				 distance_between_point_and_right_center > small_radius )
			{
				std::cout << "Yin" << std::endl;
			} else {
				std::cout << "Yang" << std::endl;
			}
		} else {	
			if( (distance_between_point_and_right_center > small_radius &&
				 distance_between_point_and_right_center < middle_radius) ||
				 distance_between_point_and_left_center < small_radius )
			{
				std::cout << "Yin" << std::endl;
			} else {
				std::cout << "Yang" << std::endl;
			}	
		}	
	} else {
		std::cout << "In the chaos!!!" << std::endl;
	}



	return 0;
}

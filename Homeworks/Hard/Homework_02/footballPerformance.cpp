// Solution for hard homework 2
// Autor: Radoslav Hubenov, GitHub: @rrhubenov


#include <iostream>
#include <cmath>
#include <iomanip>

// Constants for all the points for the sides of the rectangle (counter-clockwise)
const int RECTANGLE_X1 = 5, RECTANGLE_Y1 = 2,
		RECTANGLE_X2 = -5, RECTANGLE_Y2 = 2,
		RECTANGLE_X3 = -5, RECTANGLE_Y3 = -2,
		RECTANGLE_X4 = 5, RECTANGLE_Y4 = -2;

bool isPointOutsideRect(double x, double y) {
	if(x < RECTANGLE_X3 || x > RECTANGLE_X1 || y < RECTANGLE_Y3 || y > RECTANGLE_Y1) {
		return true;
	} else return false;
}

// Mathematical magic. Link to the formula -> https://stackoverflow.com/a/14177062/8075423
bool isIntersecting(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	return ((((x3-x1)*(y2-y1) - (y3-y1)*(x2-x1))
            * ((x4-x1)*(y2-y1) - (y4-y1)*(x2-x1)) < 0)
            &&
           (((x1-x3)*(y4-y3) - (y1-y3)*(x4-x3))
            * ((x2-x3)*(y4-y3) - (y2-y3)*(x4-x3)) < 0));
}

// Some more mathematical pseudo-magic.
// Finds intersection point with the given rectangle side.
// Calculates the distance from the intersection point with the rectangle side and the inner point.
double calculateIntersectionDistance(double x1, double y1, double x2, double y2,
									 double side_x1, double side_y1,
									 double side_x2, double side_y2) {
	// Line AB represented as a1x + b1y = c1 
	double a1 = y2 - y1; 
	double b1 = x1 - x2; 
	double c1 = a1*(x1) + b1*(y1); 
  
	// Line CD represented as a2x + b2y = c2 
	double a2 = side_y2 - side_y1; 
	double b2 = side_x1 - side_x2; 
	double c2 = a2*(side_x1)+ b2*(side_y1); 
  
	double determinant = a1*b2 - a2*b1;

	double x = (b2*c1 - b1*c2)/determinant; 
	double y = (a1*c2 - a2*c1)/determinant; 

	// Check which of the two points is inside the rectangle
	if(isPointOutsideRect(x1, y1)) return std::sqrt(std::pow(x2 - x, 2) + std::pow(y2 - y, 2));
	else return std::sqrt(std::pow(x1 - x, 2) + std::pow(y1 - y, 2));
}

// Determine which of the four sides of the rectangle is being intersected.
double calculateDistance(double x1, double y1, double x2, double y2) {	
	if(isPointOutsideRect(x1, y1) || isPointOutsideRect(x2, y2)) {
		if(isPointOutsideRect(x1, y1) && isPointOutsideRect(x2, y2)) return 0;
		// Upper side
		else if(isIntersecting(x1, y1, x2, y2, RECTANGLE_X1, RECTANGLE_Y1, RECTANGLE_X2, RECTANGLE_Y2))
			return calculateIntersectionDistance(x1, y1, x2, y2, RECTANGLE_X1, RECTANGLE_Y1, RECTANGLE_X2, RECTANGLE_Y2);
		// Left side 
		else if(isIntersecting(x1, y1, x2, y2, RECTANGLE_X2, RECTANGLE_Y2, RECTANGLE_X3, RECTANGLE_Y3))
			return calculateIntersectionDistance(x1, y1, x2, y2, RECTANGLE_X2, RECTANGLE_Y2, RECTANGLE_X3, RECTANGLE_Y3);
		// Lower side
		else if(isIntersecting(x1, y1, x2, y2, RECTANGLE_X3, RECTANGLE_Y3, RECTANGLE_X4, RECTANGLE_Y4))
			return calculateIntersectionDistance(x1, y1, x2, y2, RECTANGLE_X3, RECTANGLE_Y3, RECTANGLE_X4, RECTANGLE_Y4);
		// Right side
		else return calculateIntersectionDistance(x1, y1, x2, y2, RECTANGLE_X4, RECTANGLE_Y4, RECTANGLE_X1, RECTANGLE_Y1);
	} else return std::sqrt(std::pow(x1-x2, 2) + std::pow(y2-y1, 2));
}

double calculateDistanceError(double distance) {
	const double PI = 3.14;
	return (PI*distance/2 + distance)/2;
}

int main() {
	double x1, y1, x2, y2;
	int distancesCount;
	double endDistance = 0;

	std::cin >> distancesCount;
	
	if(distancesCount == 0 || distancesCount == 1) return 0;

	std::cin >> x1 >> y1;

	for(int i = 1; i < distancesCount; i++) {
		std::cin >> x2 >> y2;	

		endDistance += calculateDistanceError(calculateDistance(x1, y1, x2, y2));

		x1 = x2;
		y1 = y2;
	}

	std::cout << std::fixed << std::setprecision(3) << endDistance;

	return 0;
}

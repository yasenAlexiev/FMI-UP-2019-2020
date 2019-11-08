#include <iostream>

int main()
{
	// Constant for error of equality check when comparing floating point numbers.
	const double EPSILON = 0.001;

	// Constants for the radiuses of each circle/ring.
	const short INNER_CIRCLE_RADIUS = 1;
	const short	MEDIUM_CIRCLE_RADIUS = 3;
	const short OUTER_CIRCLE_RADIUS = 8;

	// Constants for points awarded on successful shot for the different circles.
	const short INVALID_SHOT_POINTS = 0;
	const short	OUTER_CIRCLE_POINTS = 10;
	const short MEDIUM_CIRCLE_POINTS = OUTER_CIRCLE_POINTS * 2;
	const short	INNER_CIRCLE_POINTS = (OUTER_CIRCLE_POINTS + MEDIUM_CIRCLE_POINTS) * 2;

	// Variables to store and validate input, for example - (3, 3) (1, 2)
	char leftBrace, rightBrace, comma;
	double x, y, xOffset, yOffset;

	std::cout << "Please enter target coordinates and offset: ";
	// Read first pair of coordinates (x, y).
	std::cin >> leftBrace >> x >> comma >> y >> rightBrace;

	// Check if input is in the format of (x, y).
	if (leftBrace != '(' || comma != ',' || rightBrace != ')')
	{
		std::cout << "Invalid input." << std::endl;
		return 1;
	}

	// Read second pair of coordinates (u, v) and validate.
	std::cin >> leftBrace >> xOffset >> comma >> yOffset >> rightBrace;
	if (leftBrace != '(' || comma != ',' || rightBrace != ')')
	{
		std::cout << "Invalid input." << std::endl;
		return 1;
	}

	// Calculate distance between the point where the dart hits and the center of the dart board.
	double realX = x + xOffset;
	double realY = y + yOffset;
	double distanceFromCenter = sqrt(realX * realX + realY * realY);

	// Boolean variables to reduce clutter and increase readability of the if-statements below.
	bool dartHitsInnerCircle = abs(distanceFromCenter - INNER_CIRCLE_RADIUS) < EPSILON;
	bool dartHitsMediumCircle = abs(distanceFromCenter - MEDIUM_CIRCLE_RADIUS) < EPSILON;
	bool dartHitsOuterCircle = abs(distanceFromCenter - OUTER_CIRCLE_RADIUS) < EPSILON;
	bool dartMisses = distanceFromCenter > OUTER_CIRCLE_RADIUS;

	// We need to check for equality first in order to make sure input like (0, 0) (2.99991, 0) 
	// is 0 points instead of 20, since 2.99991 is essentially 3 for our program.
	if (dartHitsInnerCircle || dartHitsMediumCircle || dartHitsOuterCircle || dartMisses)
	{
		std::cout << INVALID_SHOT_POINTS;
	}
	else if (distanceFromCenter < INNER_CIRCLE_RADIUS)
	{
		std::cout << INNER_CIRCLE_POINTS;
	}
	else if (distanceFromCenter < MEDIUM_CIRCLE_RADIUS)
	{
		std::cout << MEDIUM_CIRCLE_POINTS;
	}
	else
	{
		std::cout << OUTER_CIRCLE_POINTS;
	}

	std::cout << std::endl;
	return 0;
}

#include <iostream>

int main()
{
	const double EPSILON = 0.001;

	int x1, y1, r1,
		x2, y2, r2;

	std::cout << "Please enter x1, y1, r1, x2, y2, r2: ";
	std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	int radiusSum = r1 + r2;
	int radiusDifference = abs(r1 - r2);

	// We do not need to check with epsilon when using > and < since the operators work as expected for floating point numbers.
	// The problems arise when we want to check if two numbers are exactly the same. For example 1/3 + 1/3 + 1/3 != 1.
	// Because 1/3 is 0.333... which is saved as 0.333333333333333314829616256247.. in the memory.
	bool circlesDoNotIntersect = distance > radiusSum || distance < radiusDifference;

	// We can think of the check as if we create a range around the number we check for equality against.
	// For example if we want to check if the variable distance is equals to 0. We do the following thing:
	// we create the range (0 - epsilon, 0 + epsilon) and we check if distance is in that range. We do that with the code below.
	bool circlesCoincide = (distance < EPSILON && radiusDifference < EPSILON);
	bool circlesTouch = !circlesCoincide &&
						(abs(distance - radiusSum) < EPSILON || abs(distance - radiusDifference) < EPSILON);

	if (circlesDoNotIntersect)
	{
		std::cout << "The circles do not intersect.";
	}
	else if (circlesTouch)
	{
		std::cout << "The circles touch.";
	}
	else
	{
		std::cout << "The circles intersect.";
	}

	std::cout << std::endl;

	return 0;
}

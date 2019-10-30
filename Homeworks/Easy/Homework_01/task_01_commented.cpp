#include <iostream>

// Sample test cases:
// 0 0 1 5 5 1 - Do not intersect.
// 0 0 5 0 0 1 - Do not intersect. (c2 is contained in c1)
// 0 0 1 0 2 1 - Touch.
// 0 0 4 0 2 2 - Touch. (c2 is contained in c1)
// 0 0 1 1 1 1 - Intersect.
// 0 0 2 1 1 1 - Intersect. (the center of c2 is in c1)
// 0 0 1 0 0 1 - Intersect. (they are the same circle)

int main()
{
	int x1, y1, r1,
		x2, y2, r2;

	std::cout << "Please enter x1, y1, r1, x2, y2, r2: ";
	std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	// In order to avoid using the == operator with floating point numbers, we can just make all the comparisons with the values squared.
	int distanceSquared = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
	int radiusSumSquared = (r1 + r2) * (r1 + r2);
	int radiusDifferenceSquared = (r1 - r2) * (r1 - r2);

	// Circle do not intersect in two cases:
	// 1. The circles are apart i.e. the distance between their centers is greater than the sum of their radiuses.
	// 2. One of the circles is in the other but does not touch/intersect with it i.e. the distance is less than the difference of their radiuses.
	bool circlesDoNotIntersect = distanceSquared > radiusSumSquared || distanceSquared < radiusDifferenceSquared;

	// Circles touch in two cases:
	// 1. In the case when one does not contain the other:
	//  The distance between the centers of the circles is exactly the same as the sum of their radiuses. 
	// 2. In the case when one does contain the other:
	//  The distance between the centers is exactly the same as the difference of their radiuses.
	// We also have to make sure that the two circles do not coincide.
	// This happens when the distance between the centers is 0 and so is the difference of their radiuses.
	// If we do not do the check distanceSquared == radiusDifferenceSquared will always be true since both are 0 when they coincide.
	bool circlesCoincide = (distanceSquared == 0 && radiusDifferenceSquared == 0);
	bool circlesTouch = (distanceSquared == radiusSumSquared || distanceSquared == radiusDifferenceSquared) && !circlesCoincide;

	// We have three cases: The two circles either intersect, do not intersect or they touch. If one of these conditions is true,
	// the rest are surely false. We can use this conclusion and let the else statement to take care of the final case - the intersection.
	// Of course in order for this to work properly we need to make sure that we have taken care of all the other cases fully.
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


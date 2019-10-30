#include <iostream>

int main()
{
	int x1, y1, r1,
		x2, y2, r2;

	std::cout << "Please enter x1, y1, r1, x2, y2, r2: ";
	std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	int distanceSquared = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
	int radiusSumSquared = (r1 + r2) * (r1 + r2);
	int radiusDifferenceSquared = (r1 - r2) * (r1 - r2);

	bool circlesDoNotIntersect = distanceSquared > radiusSumSquared || distanceSquared < radiusDifferenceSquared;

	bool circlesCoincide = (distanceSquared == 0 && radiusDifferenceSquared == 0);
	bool circlesTouch = (distanceSquared == radiusSumSquared || distanceSquared == radiusDifferenceSquared) && !circlesCoincide;

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


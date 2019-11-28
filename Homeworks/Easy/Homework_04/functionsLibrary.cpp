#include <iostream>

const double PI = 3.14;

// 4.2.1 - Returns the sum of the digits from 'decimalNumber' represented in base 'base'. The result is a decimal number.
int getSumOfDigitsWithDifferentBase(int decimalNumber, int base);

// 4.2.2 - Finds the greatest common divider of numbers 'a' and 'b'.
int greatestCommonDivider(int a, int b);

// 4.2.3 - Returns 'number' to the power of 'power'.
long customPow(int number, unsigned int power);

// 4.2.4 - Checks if a number is green.
bool isGreen(int number);

// 4.2.5 - Find sum of all green numbers in range [start, end].
long findGreenNumbersSumInRange(int start, int end);

// 4.2.6 - Checks if a number is red.
bool isRed(int number);

// 4.2.7 - Finds the absolute difference between the sums of green and red numbers in range [start, end].
long redGreenSumsAbsoluteDifference(int start, int end);

// Helper for 4.2.7 - Finds red numbers sum in range [start, end].
long findRedNumbersSumInRange(int start, int end);

// 4.2.8 - Finds approximation of first 'sequenceLength' members of a sequnce
double approximateSequence(double realNumber, unsigned int sequenceLength);

// Helpers for 4.2.8
double switchSign(int previousSign);
double powRealNumber(double realNumber, unsigned int power);
long factorial(int number);

// 4.2.9 - Functions to calculate cos(x), sin(x), tan(x), cotg(x). x is in radians.
double cosine(double radians);
double sine(double radians);
double tangent(double radians);
double cotangent(double radians);

// Helper for 4.2.9 - Converts radians to range [-PI, PI].
double fixRadiansRange(double radians);

int main()
{
	std::cout << "Example for 4.2.1" << std::endl;
	std::cout << "Number 5, base 2: " << getSumOfDigitsWithDifferentBase(5, 2) << std::endl;
	std::cout << "Number 5, base 3: " << getSumOfDigitsWithDifferentBase(5, 3) << std::endl;
	std::cout << "Number 5, base 10: " << getSumOfDigitsWithDifferentBase(5, 10) << std::endl << std::endl;

	std::cout << "Example for 4.2.2" << std::endl;
	std::cout << "GCD(3, 5) = " << greatestCommonDivider(3, 5) << std::endl;
	std::cout << "GCD(3, 9) = " << greatestCommonDivider(3, 9) << std::endl;
	std::cout << "GCD(12, 16) = " << greatestCommonDivider(12, 16) << std::endl << std::endl;

	std::cout << "Example for 4.2.3" << std::endl;
	std::cout << "2^4 = " << customPow(2, 4) << std::endl;
	std::cout << "3^5 = " << customPow(3, 5) << std::endl;
	std::cout << "9^0 = " << customPow(9, 0) << std::endl << std::endl;

	std::cout << "Example for 4.2.4 - show all green numbers in range [0, 1500]" << std::endl;
	for (int currentNumber = 0; currentNumber <= 1500; currentNumber++)
	{
		if (isGreen(currentNumber))
		{
			std::cout << currentNumber << " ";
		}
	}
	std::cout << std::endl << std::endl;

	std::cout << "Example for 4.2.5 - show the sum of all green numbers in range [0, 1500]" << std::endl;
	std::cout << findGreenNumbersSumInRange(0, 1500) << std::endl << std::endl;

	std::cout << "Example for 4.2.6 - show all red numbers in range [0, 300]" << std::endl;
	for (int currentNumber = 0; currentNumber <= 300; currentNumber++)
	{
		if (isRed(currentNumber))
		{
			std::cout << currentNumber << " ";
		}
	}
	std::cout << std::endl << std::endl;

	std::cout << "Example for 4.2.7 - show absolute difference between red and green numbers in range [0, 300]" << std::endl;
	std::cout << redGreenSumsAbsoluteDifference(0, 300) << std::endl << std::endl;


	std::cout << "Example for 4.2.8 - Approximation with x = 2, n = 7: " << std::endl;
	std::cout << approximateSequence(2, 7) << std::endl << std::endl;

	std::cout << "Example for 4.2.9" << std::endl;
	std::cout << "cosine(1) = " << cosine(1) << std::endl;
	std::cout << "sine(1) = " << sine(1) << std::endl;
	std::cout << "tangent(1) = " << tangent(1) << std::endl;
	std::cout << "cotangent(1) = " << cotangent(1) << std::endl << std::endl;

	return 0;
}

int getSumOfDigitsWithDifferentBase(int decimalNumber, int base)
{
	int sum = 0;
	while (decimalNumber > 0)
	{
		sum = sum + (decimalNumber % base);
		decimalNumber = decimalNumber / base;
	}

	return sum;
}

int greatestCommonDivider(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}

	return a;
}

long customPow(int number, unsigned int power)
{
	if (power == 0) return 1;
	if (power == 1) return number;

	long product = 1;
	for (int currentPower = 0; currentPower < power; currentPower++)
	{
		product *= number;
	}

	return product;
}

bool isGreen(int number)
{
	int digitSum = 0;
	int copy = number;

	int currentDigit;
	while (copy > 0)
	{
		currentDigit = copy % 10;
		digitSum += customPow(currentDigit, 3);

		copy = copy / 10;
	}

	return digitSum == number;
}

long findGreenNumbersSumInRange(int start, int end)
{
	// Making sure start is always the smaller number.
	if (start > end)
	{
		std::swap(start, end);
	}

	int sum = 0;
	for (int current = start; current <= end; current++)
	{
		if (isGreen(current))
		{
			sum += current;
		}
	}

	return sum;
}

bool isRed(int number)
{
	// Reuse the function from 4.2.1 with base 10 - returns the sum of the digits.
	int digitsSum = getSumOfDigitsWithDifferentBase(number, 10);

	// Loop can be optimized, it is that way for the sake of simplicity.
	int multiplicationResult;
	for (int multiplier = 1; multiplier < number; multiplier++)
	{
		multiplicationResult = multiplier * digitsSum;
		if (multiplicationResult == number)
		{
			return true;
		}
	}

	return false;
}

long redGreenSumsAbsoluteDifference(int start, int end)
{
	int greenSum = findGreenNumbersSumInRange(start, end);
	int redSum = findRedNumbersSumInRange(start, end);

	return abs(greenSum - redSum);
}

long findRedNumbersSumInRange(int start, int end)
{
	if (start > end)
	{
		std::swap(start, end);
	}

	int sum = 0;
	for (int current = start; current <= end; current++)
	{
		if (isRed(current))
		{
			sum += current;
		}
	}

	return sum;
}

double approximateSequence(double realNumber, unsigned int sequenceLength)
{
	double totalApproximation = 0;
	double currentApproximation = 0;

	// At the beginning of every loop we switch the sign, so the first sign will be positive.
	double sign = -1.0;
	double poweredRealNumber;
	double calculatedFactorial;

	for (int i = 0; i < sequenceLength; i = i + 2)
	{
		sign = switchSign(sign);
		poweredRealNumber = powRealNumber(realNumber, i);
		calculatedFactorial = factorial(i);

		currentApproximation = sign * poweredRealNumber / calculatedFactorial;

		// At some point currentApproximation breaks and becomes infinity. We stop the loop in order to not make the result infinity.
		if (isinf(currentApproximation))
		{
			break;
		}

		totalApproximation += currentApproximation;
	}

	return totalApproximation;
}

double switchSign(int previousSign)
{
	if (previousSign < 0)
	{
		return 1.0;
	}

	return -1.0;
}

double powRealNumber(double realNumber, unsigned int power)
{
	if (power == 0) return 1;
	if (power == 1) return realNumber;

	double product = 1;
	for (int currentPower = 0; currentPower < power; currentPower++)
	{
		product *= realNumber;
	}

	return product;
}

long factorial(int number)
{
	long product = 1;
	for (int current = 2; current <= number; current++)
	{
		product *= current;
	}

	return product;
}

double cosine(double radians)
{
	radians = fixRadiansRange(radians);

	return approximateSequence(radians, 40);
}

double sine(double radians)
{
	double cosineApproximation = cosine(radians);

	// We use the formula sin^2(x) + cos^2(x) = 1.
	double sineSquared = 1.0 - (cosineApproximation * cosineApproximation);
	return sqrt(sineSquared);
}

double tangent(double radians)
{
	double sineApproximation = sine(radians);
	double cosineApproximation = cosine(radians);

	return sineApproximation / cosineApproximation;
}

double cotangent(double radians)
{
	return 1.0 / tangent(radians);
}

double fixRadiansRange(double radians)
{
	while (radians > PI)
	{
		radians = radians - PI;
	}

	while (radians < -PI)
	{
		radians = radians + PI;
	}

	return radians;
}
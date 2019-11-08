#include <iostream>

int main()
{
	// We want to avoid magic numbers in our code, so we add constants for min and max values for our number.
	const short MIN_NUMBER = 1;
	const short MAX_NUMBER = 3000;

	short number;

	std::cout << "Please enter a number in the range [1, 3000]: ";
	std::cin >> number;

	if (number < MIN_NUMBER || number > MAX_NUMBER)
	{
		std::cout << "Invalid number!" << std::endl;
		return 1;
	}

	short firstDigit = number / 1000;
	short secondDigit = (number / 100) % 10;
	short thirdDigit = (number / 10) % 10;
	short fourthDigit = number % 10;

	switch (firstDigit)
	{
	case 1: std::cout << "M"; break;
	case 2: std::cout << "MM"; break;
	case 3: std::cout << "MMM"; break;
	}

	switch (secondDigit)
	{
	case 1:std::cout << "C"; break;
	case 2:std::cout << "CC"; break;
	case 3:std::cout << "CCC"; break;
	case 4:std::cout << "CD"; break;
	case 5:std::cout << "D"; break;
	case 6:std::cout << "DC"; break;
	case 7:std::cout << "DCC"; break;
	case 8:std::cout << "DCCC"; break;
	case 9:std::cout << "CM"; break;
	}

	switch (thirdDigit)
	{
	case 1:std::cout << "X"; break;
	case 2:std::cout << "XX"; break;
	case 3:std::cout << "XXX"; break;
	case 4:std::cout << "XL"; break;
	case 5:std::cout << "L"; break;
	case 6:std::cout << "LX"; break;
	case 7:std::cout << "LXX"; break;
	case 8:std::cout << "LXXX"; break;
	case 9:std::cout << "XC"; break;
	}

	switch (thirdDigit)
	{
	case 1:std::cout << "I"; break;
	case 2:std::cout << "II"; break;
	case 3:std::cout << "III"; break;
	case 4:std::cout << "IV"; break;
	case 5:std::cout << "V"; break;
	case 6:std::cout << "VI"; break;
	case 7:std::cout << "VII"; break;
	case 8:std::cout << "VIII"; break;
	case 9:std::cout << "IX"; break;
	}

	return 0;
}

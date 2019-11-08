#include <iostream>

// Declare functions that print the roman numerals for each different digit.
// We need to have the declarations before the place we use the functions (in our case the main function).
// We add the definitions below the main function in order to reduce clutter.
void printThousands(short thousands);
void printHundreds(short hundreds);
void printTens(short tens);
void printOnes(short ones);

int main()
{
	// We want to avoid magic numbers in our code, so we add constants for min and max values for our number.
	const short MIN_NUMBER = 1;
	const short MAX_NUMBER = 3000;

	short number;

	std::cout << "Please enter a number in the range [1, 3000]: ";
	std::cin >> number;

	// The first thing we do after we get the number from the console is validation.
	// If the validation fails we stop the program.
	if (number < MIN_NUMBER || number > MAX_NUMBER)
	{
		std::cout << "Invalid number!" << std::endl;
		return 1;
	}
	
	// At this in the execution of the program we know that the number is valid because we have already done the check.
	// This lets us write our code with style that work as if the input is always correct.
	short firstDigit = number / 1000;
	short secondDigit = (number / 100) % 10;
	short thirdDigit = (number / 10) % 10;
	short fourthDigit = number % 10;

	// Call the functions that print the roman numerals with the diffent digits of the number.
	printThousands(firstDigit);
	printHundreds(secondDigit);
	printTens(thirdDigit);
	printOnes(fourthDigit);

	std::cout << std::endl;
	return 0;
}

// The definitions(bodies) of the functions.
void printThousands(short thousands)
{
	switch (thousands)
	{
	case 1: std::cout << "M"; break;
	case 2: std::cout << "MM"; break;
	case 3: std::cout << "MMM"; break;
	}
}

void printHundreds(short hundreds)
{
	switch (hundreds)
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
}

void printTens(short tens)
{
	switch (tens)
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
}

void printOnes(short ones)
{
	switch (ones)
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
}

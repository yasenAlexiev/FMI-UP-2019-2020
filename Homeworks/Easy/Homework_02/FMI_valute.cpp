#include <iostream>

unsigned short calculateEvenOddSum(int cardNumber);
unsigned short getFirstMask(unsigned short octalNumber);
unsigned short getSecondMask(unsigned short octalNumber);

int main()
{
	int cardNumber;
	std::cout << "Please enter a 9-digit card number: ";
	std::cin >> cardNumber;

	unsigned short secondDigit = (cardNumber / 10000000) % 10;
	unsigned short checkDigit = cardNumber % 10;

	unsigned short evenOddSum = calculateEvenOddSum(cardNumber);
	unsigned short firstMask = getFirstMask(secondDigit);
	unsigned short secondMask = getSecondMask(secondDigit);

	evenOddSum = evenOddSum | firstMask;
	evenOddSum = evenOddSum ^ secondMask;

	unsigned short calculatedCheckDigit = evenOddSum >> 12;
	calculatedCheckDigit = calculatedCheckDigit % 10;

	if (secondDigit == 8 || secondDigit == 9 || calculatedCheckDigit != checkDigit)
	{
		std::cout << "Imitative." << std::endl;
	}
	else
	{
		std::cout << "Authentic" << std::endl;
	}

	return 0;
}

unsigned short calculateEvenOddSum(int cardNumber)
{
	short ninthDigit = cardNumber % 10;
	cardNumber = cardNumber / 10;
	short eigthDigit = cardNumber % 10;
	cardNumber = cardNumber / 10;
	short seventhDigit = cardNumber % 10;
	cardNumber = cardNumber / 10;
	short sixthDigit = cardNumber % 10;
	cardNumber = cardNumber / 10;
	short fifthDigit = cardNumber % 10;
	cardNumber = cardNumber / 10;
	short fourthDigit = cardNumber % 10;
	cardNumber = cardNumber / 10;
	short thirdDigit = cardNumber % 10;
	cardNumber = cardNumber / 10;
	short secondDigit = cardNumber % 10;
	cardNumber = cardNumber / 10;
	short firstDigit = cardNumber % 10;

	short evenSum = secondDigit + fourthDigit + sixthDigit + eigthDigit;
	short oddSum = firstDigit + thirdDigit + fifthDigit + seventhDigit + ninthDigit;

	return evenSum * oddSum;
}

unsigned short getFirstMask(unsigned short octalNumber)
{
	const unsigned short darkEyesAndHairMask = 0xCAFE;
	const unsigned short lightEyesAndHairMask = 0xBABE;
	const unsigned short defaultMask = 0xC001;

	bool userHasDarkEyes = (octalNumber >> 2) & 1;
	bool userHasDarkHair = (octalNumber >> 1) & 1;

	if (userHasDarkEyes && userHasDarkHair)
	{
		return darkEyesAndHairMask;
	}

	if (!userHasDarkEyes && !userHasDarkHair)
	{
		return lightEyesAndHairMask;
	}

	return defaultMask;
}

unsigned short getSecondMask(unsigned short octalNumber)
{
	const unsigned short userIsFemaleMask = 0xFACE;
	const unsigned short userIsMaleMask = 0xC0DE;

	bool userIsMale = octalNumber & 1;

	if (userIsMale)
	{
		return userIsMaleMask;
	}

	return userIsFemaleMask;
}

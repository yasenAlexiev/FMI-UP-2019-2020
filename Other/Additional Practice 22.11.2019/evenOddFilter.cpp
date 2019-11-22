#include <iostream>

const int MAX_ARRAY_SIZE = 1024;
const int MIN_ARRAY_SIZE = 1;

bool arraySizeIsValid(int arraySize);
bool codeIsValid(char code);
void filterAndPrintSequnce(int sequenceSize, int sequence[], char filterCode);
void filterForOdd(int sequenceSize, int sequence[]);
void filterForEven(int sequenceSize, int sequence[]);
int calculatePrimeSum(int number);
bool isPrime(int number);

int main()
{
	// Initialize array with set size from compilation.
	int sequence[MAX_ARRAY_SIZE];

	// Read arguments related to the task.
	int arraySize;
	char code;
	std::cin >> arraySize >> code;

	// Validate the arguments' values.
	if (!arraySizeIsValid(arraySize) || !codeIsValid(code))
	{
		std::cout << "Invalid arguments." << std::endl;
		return 1;
	}

	// Read the sequence of number into the array.
	for (int i = 0; i < arraySize; i++)
	{
		std::cin >> sequence[i];
	}

	// Filter the array depending on the 'code'.
	filterAndPrintSequnce(arraySize, sequence, code);
}

bool arraySizeIsValid(int arraySize)
{
	return arraySize >= MIN_ARRAY_SIZE && arraySize <= MAX_ARRAY_SIZE;
}
bool codeIsValid(char code)
{
	return code == 'E' || code == 'O';
}

void filterAndPrintSequnce(int sequenceSize, int sequence[], char filterCode)
{
	if (filterCode == 'E')
	{
		filterForEven(sequenceSize, sequence);
	}
	else
	{
		filterForOdd(sequenceSize, sequence);
	}
}

void filterForOdd(int sequenceSize, int sequence[])
{
	int currentPrimeSum;
	for (int i = 0; i < sequenceSize; i++)
	{
		currentPrimeSum = calculatePrimeSum(sequence[i]);
		if (currentPrimeSum % 2 == 1)
		{
			std::cout << sequence[i] << " ";
		}
	}

	std::cout << std::endl;
}
void filterForEven(int sequenceSize, int sequence[])
{
	int currentPrimeSum;
	for (int i = 0; i < sequenceSize; i++)
	{
		currentPrimeSum = calculatePrimeSum(sequence[i]);
		if (currentPrimeSum % 2 == 0)
		{
			std::cout << sequence[i] << " ";
		}
	}

	std::cout << std::endl;
}

int calculatePrimeSum(int number)
{
	number = abs(number);
	int primeSum = 0;
	for (int i = 2; i <= number; i++)
	{
		if (isPrime(i))
		{
			primeSum += i;
		}
	}

	return primeSum;
}

bool isPrime(int number)
{
	if (number == 1)
	{
		return false;
	}

	for (int i = 2; i <= number / 2; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}
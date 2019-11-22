#include <iostream>
#include <cassert>

const int MAX_ARRAY_SIZE = 1024;
const int MIN_ARRAY_SIZE = 1;

void printReccuringNumbers(int size, int sequence[], int k);
int getOccurances(int size, int sequnce[], int value);
bool contains(int size, int sequnce[], int value);
void add(int& size, int sequnce[], int value);

int main()
{
	// Initialize array with set size from compilation.
	int sequence[MAX_ARRAY_SIZE];

	//// Read array size and this 'k' number.
	int arraySize, k;
	std::cin >> arraySize >> k;

	// Validate sequence length
	if (arraySize < MIN_ARRAY_SIZE || arraySize > MAX_ARRAY_SIZE)
	{
		std::cout << "Invalid sequence length." << std::endl;
		return 1;
	}

	// Read the sequence of number into the array.
	for (int i = 0; i < arraySize; i++)
	{
		std::cin >> sequence[i];
	}

	printReccuringNumbers(arraySize, sequence, k);
}

void printReccuringNumbers(int size, int sequence[], int k)
{
	int minOccurances = size / k;

	int printedNumbers[MAX_ARRAY_SIZE];
	int printedNumbersSize = 0;

	int currentOccurancesCount;
	for (int i = 0; i < size; i++)
	{
		currentOccurancesCount = getOccurances(size, sequence, sequence[i]);
		if (currentOccurancesCount > minOccurances && !contains(printedNumbersSize, printedNumbers, sequence[i]))
		{
			add(printedNumbersSize, printedNumbers, sequence[i]);
			std::cout << sequence[i] << " ";
		}
	}
}

int getOccurances(int size, int sequence[], int value)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (sequence[i] == value)
		{
			count++;
		}
	}

	return count;
}

bool contains(int size, int sequence[], int value)
{
	for (int i = 0; i < size; i++)
	{
		if (sequence[i] == value)
		{
			return true;
		}
	}

	return false;
}

void add(int& size, int sequence[], int value)
{
	if (contains(size, sequence, value) || size >= MAX_ARRAY_SIZE)
	{
		return;
	}

	sequence[size] = value;
	size++;
}
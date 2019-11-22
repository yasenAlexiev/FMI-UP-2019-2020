#include <iostream>
#include <cassert>

const int MAX_ARRAY_SIZE = 1024;
const int MIN_ARRAY_SIZE = 1;

void printSymbols(int size, char sequence[]);

void printNumbers(int size, char sequence[]);
void printLowerLetters(int size, char sequence[]);
void printUpperLetters(int size, char sequence[]);

bool isNumber(char symbol);
bool isLowerLetter(char symbol);
bool isUpperLetter(char symbol);

void printArray(int size, char sequence[]);
int main()
{
	// Initialize array with set size from compilation.
	char sequence[MAX_ARRAY_SIZE];

	//// Read array size and this 'k' number.
	int arraySize;
	std::cin >> arraySize;

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

	printSymbols(arraySize, sequence);
}

void printSymbols(int size, char sequence[])
{
	printNumbers(size, sequence);
	printLowerLetters(size, sequence);
	printUpperLetters(size, sequence);
}

void printNumbers(int size, char sequence[])
{
	for (int i = 0; i < size; i++)
	{
		if (isNumber(sequence[i]))
		{
			std::cout << sequence[i] << " ";
		}
	}

	std::cout << std::endl;
}
void printLowerLetters(int size, char sequence[])
{
	for (int i = 0; i < size; i++)
	{
		if (isLowerLetter(sequence[i]))
		{
			std::cout << sequence[i] << " ";
		}
	}

	std::cout << std::endl;
}
void printUpperLetters(int size, char sequence[])
{
	for (int i = 0; i < size; i++)
	{
		if (isUpperLetter(sequence[i]))
		{
			std::cout << sequence[i] << " ";
		}
	}

	std::cout << std::endl;
}

bool isNumber(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}
bool isLowerLetter(char symbol)
{
	return symbol >= 'a' && symbol <= 'z';
}
bool isUpperLetter(char symbol)
{
	return symbol >= 'A' && symbol <= 'Z';
}

void printArray(int size, char sequence[])
{
	for (int i = 0; i < size; i++)
	{
		std::cout << sequence[i] << " ";
	}

	std::cout << std::endl;
}

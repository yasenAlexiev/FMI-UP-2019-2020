#include <iostream>

const int MAX_ARRAY_SIZE = 1024;
const int MIN_ARRAY_SIZE = 1;

bool isUnique(int arraySize, int sequence[], int value);
void printArray(int size, int sequence[]);
void printUniqueElement(int arraySize, int sequence[]);

int main()
{
	// Initialize array with set size from compilation.
	int sequence[MAX_ARRAY_SIZE];

	// Read array size.
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

	printUniqueElement(arraySize, sequence);
}

void printUniqueElement(int arraySize, int sequence[])
{
	for (int i = 0; i < arraySize; i++)
	{
		if (isUnique(arraySize, sequence, sequence[i]))
		{
			std::cout << "Unique: " << sequence[i] << std::endl;
		}
	}
}

bool isUnique(int arraySize, int sequence[], int value)
{
	int occurencesCount = 0;
	for (int i = 0; i < arraySize; i++)
	{
		if (sequence[i] == value)
		{
			occurencesCount++;
		}
	}

	return occurencesCount == 1;
}

void printArray(int size, int sequence[])
{
	for (int i = 0; i < size; i++)
	{
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
}
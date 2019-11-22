#include <iostream>

const int MAX_ARRAY_SIZE = 1024;
const int MIN_ARRAY_SIZE = 1;

void removeDuplicates(int& arraySize, int sequence[]);
bool isDuplicate(int arraySize, int sequence[], int value);
void removeAllOccurences(int& arraySize, int sequence[], int value);
void removeElement(int& size, int sequence[], int index);
void printArray(int size, int sequence[]);

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

	printArray(arraySize, sequence);
	removeDuplicates(arraySize, sequence);
	printArray(arraySize, sequence);
}

void removeDuplicates(int& arraySize, int sequence[])
{
	int currentNumber;
	for (int i = 0; i < arraySize; i++)
	{
		currentNumber = sequence[i];
		/*if (isDuplicate(arraySize, sequence, currentNumber))
		{
			removeAllOccurences(arraySize, sequence, currentNumber);
		}*/

		if (!isDuplicate(arraySize, sequence, currentNumber))
		{
			std::cout << currentNumber << " ";
		}
	}
}

bool isDuplicate(int arraySize, int sequence[], int value)
{
	int occurencesCount = 0;
	for (int i = 0; i < arraySize; i++)
	{
		if (sequence[i] == value)
		{
			occurencesCount++;
		}
	}

	return occurencesCount > 1;
}

void removeAllOccurences(int& arraySize, int sequence[], int value)
{
	for (int i = arraySize - 1; i >= 0; i--)
	{
		if (sequence[i] == value)
		{
			removeElement(arraySize, sequence, i);
		}
	}
}

void removeElement(int& size, int sequence[], int index)
{
	if (index >= size || index < 0)
	{
		return;
	}

	for (int i = index; i < size - 1; i++)
	{
		sequence[i] = sequence[i + 1];
	}
	size--;
}

void printArray(int size, int sequence[])
{
	for (int i = 0; i < size; i++)
	{
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
}
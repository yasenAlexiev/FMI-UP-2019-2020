#include <iostream>
#include <cassert>

const int MAX_ARRAY_SIZE = 1024;
const int MIN_ARRAY_SIZE = 1;

int findLongestSubsequence(int arraySize, int sequence[]);


int main()
{
	// Initialize array with set size from compilation.
	int sequence[MAX_ARRAY_SIZE];

	//// Read array size.
	//int arraySize;
	//std::cin >> arraySize;

	//// Validate sequence length
	//if (arraySize < MIN_ARRAY_SIZE || arraySize > MAX_ARRAY_SIZE)
	//{
	//	std::cout << "Invalid sequence length." << std::endl;
	//	return 1;
	//}

	//// Read the sequence of number into the array.
	//for (int i = 0; i < arraySize; i++)
	//{
	//	std::cin >> sequence[i];
	//}

	//int length = findLongestSubsequence(arraySize, sequence);
	//std::cout << length << std::endl;

	int testArray[] = { 1,2,3,2,1,4,5,6 };
	assert(findLongestSubsequence(8, testArray) == 4);

	int testArray2[] = { 1,2,3,4,3,2,1 };
	assert(findLongestSubsequence(7, testArray2) == 4);

	int testArray3[] = { 1,2,1,2,1,2,3 };
	assert(findLongestSubsequence(7, testArray3) == 3);

	int testArray4[] = { 3, 2, 1 };
	assert(findLongestSubsequence(3, testArray4) == 1);

	std::cout << "Works!" << std::endl;
}
int findLongestSubsequence(int arraySize, int sequence[])
{
	if (arraySize == 0 || arraySize == 1)
	{
		return arraySize;
	}

	int current = 1;
	int longest = 1;
	for (int i = 1; i < arraySize; i++)
	{
		if (sequence[i] > sequence[i - 1])
		{
			current++;
		}
		else
		{
			current = 1;
		}

		if (longest < current)
		{
			longest = current;
		}
	}

	return longest;
}
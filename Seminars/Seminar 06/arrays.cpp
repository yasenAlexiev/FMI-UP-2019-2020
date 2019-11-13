#include <iostream>

void solutions();
void solutionsCommented();
bool isPrime(int);
void printArray(int[], int);

int main()
{
	// Declaration of a variable.
	int number;

	// Declaration of an array - <type> <name>[<how much elements we want this array to have>]
	int numbers[10];

	// Reading a number from the console.
	std::cin >> number;

	// Reading a number from the console, but now we store this number in the elements of the array.
	// Acessing the first element is done with the [] operator - numbers[0] gives us the first element of the array.
	// So we start from 0, this means that an array with 10 elements will have 10 numbers in it -
	// numbers[0], numbers[1], ..., numbers[9] 
	// numbers[10] is not defined and will break you program 100%, be careful.
	std::cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3] >> numbers[4] >> numbers[5] >> numbers[6] >> numbers[7];


	// Setting values with operator =.
	numbers[0] = 0;
	numbers[1] = 1;
	numbers[2] = 2;
	numbers[3] = 3;
	numbers[4] = 4;
	numbers[5] = 5;
	numbers[6] = 6;
	numbers[7] = 7;
	numbers[8] = 8;
	numbers[9] = 9;

	// wrong, this is the 11th element and we created an array with only 10. The program asked our computer only for 10x4 bytes.
	// numbers[10] = 10;

	// What happens in memory? Single block versus multiple blocks.

	// Save the numbers from 0 to 9 with for loop.
	// Print array.
	// Read number N and make array with values [1,N].
	// Print array with function.
	// Read n numbers from the console.
	// Read N and make an array with the first N prime numbers.
	// What happens when we try to return an array from a function? Why? Scopes, memory, variables life span.

	return 0;
}


void solutions()
{
	const unsigned int MAX_ARRAY_SIZE = 1024;
	int numbers[MAX_ARRAY_SIZE];

	// Save the numbers from 0 to 9 with a for loop.
	for (int i = 0; i <= 9; i++)
	{
		numbers[i] = i;
	}

	// Print array.
	for (int i = 0; i <= 9; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;


	// Read number N and make array with values [1,N].
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		numbers[i] = i + 1;
	}

	// Print array with function.
	printArray(numbers, N);

	// Read n numbers from the console.
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> numbers[i];
	}

	// Read N and make an array with the first N prime numbers.
	std::cin >> N;
	int primesFound = 0;
	int currentNumber = 2;
	int currentIndex = 0;
	while (primesFound < N)
	{
		if (isPrime(currentNumber))
		{
			numbers[currentIndex] = currentNumber;
			primesFound++;
			currentIndex++;
		}

		currentNumber++;
	}

}
void solutionsCommented()
{
	const unsigned int MAX_ARRAY_SIZE = 1024;
	int numbers[MAX_ARRAY_SIZE];

	// Save the numbers from 0 to 9 with a for loop.
	// Loop over the values we need to save - 0,1,2,...,9
	for (int i = 0; i <= 9; i++)
	{
		// Since the value of i is the same as the index we just use numbers[i] = i;
		// This does the same as the 9 lines of code in the main function.
		numbers[i] = i;
	}


	// Print array.
	// We know that we have 9 elements in it, so we make the loop go up to 9, no more, no less.
	for (int i = 0; i <= 9; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	// Read number N and make array with values [1,N].
	// Since the values are from 1 to N, we now have to add one since value = index + 1;
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		numbers[i] = i + 1;
	}

	// Since we have to know when to stop the loop - we do not have some kind of built-in function in C++, which gives us the
	// size of the array, we need to keep this information updated at all times, and when we need it, use it.
	printArray(numbers, N);


	// Read n numbers from the console.
	// Read how much elements will be coming from the console - N.
	// For loop N times - from 0 up to N - 1.
	// On each loop save one number in the corresponding box in the array.
	// In other words - the first number gets the index 0, second - index 1, ... nth - index n-1
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> numbers[i];
	}

	// Read N and make an array with the first N prime numbers.
	// While loop will stop if we have found N primes, we start with primesFound = 0;
	// if we find a prime - we increase this counter by 1. We also put the prime in the array at the corresponding index.
	// Since we are using a while loop, we also have to manually take care to increase the index counter.
	// The while loop goes over the natural numbers starting at 2 to infinity
	// each iteration we check if the current number is prime.
	std::cin >> N;
	int primesFound = 0;
	int currentNumber = 2;
	int currentIndex = 0;
	while (primesFound < N)
	{
		if (isPrime(currentNumber))
		{
			numbers[currentIndex] = currentNumber;
			primesFound++;
			currentIndex++;
		}

		currentNumber++;
	}
}

void printArray(int arrayOfNumbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arrayOfNumbers[i] << " ";
	}

	std::cout << std::endl;
}

bool isPrime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

//#include <iostream>
//
//// Reads a number from console, checks if it is even and returns it as 'result'.
//void readEvenNumber(unsigned int& result);
//
//// Prints all pairs of prime numbers which add to 'number'.
//void printPrimePairs(int number);
//
//// Checks if a number is prime.
//bool isPrime(int number);
//
//int main()
//{
//	unsigned int evenNumber;
//	readEvenNumber(evenNumber);
//	printPrimePairs(evenNumber);
//	
//	return 0;
//}
//
//// Reads until the number is even.
//void readEvenNumber(unsigned int& result)
//{
//	do
//	{
//		std::cout << "Please enter an even number: ";
//		std::cin >> result;
//
//	} while (result % 2 != 0);
//}
//
//// In order to escape duplicating pairs, the loop goes over only half of the range [2, number].
//void printPrimePairs(int number)
//{
//	int pairFirst, pairSecond;
//	for (int current = 2; current <= number / 2; current++)
//	{
//		pairFirst = current;
//		pairSecond = number - current;
//
//		if (isPrime(pairFirst) && isPrime(pairSecond))
//		{
//			std::cout << "(" << pairFirst << ", " << pairSecond << ") ";
//		}
//	}
//
//	std::cout << std::endl;
//}
//
//bool isPrime(int number)
//{
//	if (number == 1)
//	{
//		return false;
//	}
//
//	for (int divisor = 2; divisor <= number / 2; divisor++)
//	{
//		if (number % divisor == 0)
//		{
//			return false;
//		}
//	}
//
//	return true;
//}
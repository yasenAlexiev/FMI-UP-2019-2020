#include <iostream>
#include <math.h>

typedef unsigned int u_int;

u_int firstNSum(u_int N) {
	if(N == 0) {
		return N;
	}
	return N + firstNSum(N-1);
}

bool isPrimeRecursive(u_int number, u_int d) {
	if(d < 2)
		return true;

	if(number%d == 0) {
		return false;
	} else {
		isPrimeRecursive(number, d-1);
	}
}

// This is the wrapper funtion of the real recursive function
bool isPrime(u_int number) {
	return number > 1 && isPrimeRecursive(number, sqrt(number));
}

u_int primeProductRecursive(u_int count, u_int number) {
	if(count == 0)
		return 0;

	if(count == 1 && isPrime(number)) {
		return number;
	}
	if(isPrime(number)) {
		return number * primeProductRecursive(count-1, number+1);
	} else {
		return primeProductRecursive(count, number+1);
	}
}

u_int primeProduct(u_int count) {
	return primeProductRecursive(count, 2);
}

u_int factorial(u_int number) {
	if(number == 0) {
		return 1;
	}

	return number * factorial(number - 1);
}

u_int digitSum(u_int number) {
	if(number < 10) {
		return number;
	}

	return number%10 + digitSum(number/10);
}

u_int nthFibonacci(u_int number) {
	if(number < 2) {
		return number;
	}

	return nthFibonacci(number-1) + nthFibonacci(number-2);
}

int main() {

	/* Task 1
	for(int i = 0; i < 100; ++i) {	
		std::cout << i << ": " << firstNSum(i) << std::endl;
	}
	*/

	/* Task 2
	for(int i = 0; i < 100; ++i) {	
		std::cout << i << ": " << ((isPrime(i)) ? "Is prime" : "Is not prime") << std::endl;
	}
	*/
	
	/* Task 3
	*/
	for(int i = 0; i < 10; ++i) {	
		std::cout << "Product of the first " << i << " numbers is: " << primeProduct(i) << std::endl;
	}

	/* Task 4
	for(int i = 0; i < 10; ++i) {	
		std::cout << "Factorial of " << i << " is: " << factorial(i) << std::endl;
	}
	*/
	
	/* Task 5
	for(int i = 900; i < 1000; ++i) {	
		std::cout << "Sum of digits of " << i << " is: " << digitSum(i) << std::endl;
	}
	*/

	/* Task 6		
	for(int i = 0; i < 10; ++i) {	
		std::cout << i << " number of fibonacii is " << nthFibonacci(i) << std::endl;
	}
	*/

	return 0;
}

#include <iostream>

bool isPalindrome(unsigned number) {

	unsigned reverseNumber = 0;
	unsigned buff = number;
	while(buff > 0) {
		reverseNumber += buff % 10;
		reverseNumber *= 10;
		buff /= 10;
	}
	reverseNumber /= 10;

	return (number == reverseNumber);
}

int main() {
	unsigned number;
	std::cin >> number;

	std::cout << (isPalindrome(number) ? "Yup" : "Nope") << std::endl;

	return 0;
}

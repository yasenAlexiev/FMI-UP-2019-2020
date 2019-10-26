#include <iostream>


int main() {
	unsigned year;
	std::cout << "Enter your year:" << std::endl;
	std::cin >> year;
	bool leap_year = false;
	if(year % 4 == 0) {
		if(year % 100 == 0) {
			leap_year = (year % 400 == 0);	
		} else {
			leap_year = true;
		}
	}

	std::cout << (leap_year ? "Leap Year!\n" : "Not leap year!\n") << std::endl;

	return 0;
}

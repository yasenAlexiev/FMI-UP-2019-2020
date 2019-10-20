#include <iostream>
#include <iomanip>


void variables()
{	
	int five = 5;
	int number = five = 6;

	std::cout << number << " " << five << std::endl;
	std::cout << " 25 / 2 = " << 25 / 2 << std::endl; // 12
	std::cout << " 25 + 25 / 2 = " << 25 + 25 / 2 << std::endl; // 37
	std::cout << " 25 + 25 % 2 = " << 25 + 25 % 2 << std::endl; // 26

	std::cout << std::endl;

	std::cout << " 0 + '0' = " << 0 + '0' << std::endl; // 48
	std::cout << " 9 + '9' = " << 9 + '9' << std::endl; // 66
	std::cout << "'9' - '0' = " << '9' - '0' << std::endl; // 9
	std::cout << "'9' < '0' = " << ('9' < '0') << std::endl; // 0 

	std::cout << std::endl;

	
	bool whatIsTheValue = -199999993;
	bool three = true;
	bool three2 = false;
	//
	std::cout << " whatIsTheValue = " << whatIsTheValue << std::endl; // 0 1
	std::cout << " !whatIsTheValue = " << !whatIsTheValue << std::endl;
	std::cout << " !!whatIsTheValue = " << !!whatIsTheValue << std::endl;
	std::cout << " three + 3 = " << three + 3 << std::endl;

	std::cout << std::endl;

	std::cout << " 2 * 2.20001 = " << 2 * 2.20001 << std::endl; // 4.40002 

	std::streamsize secret = std::cout.precision();
	std::cout << " 3.9  " << std::setprecision(2) << 2 * 2.223 << std::endl;
	std::cout << " 2 * 2.20001 = " << std::setprecision(2) << std::fixed << 2 * 2.20001 << std::endl;
	std::cout << " 0.00003 - 0.00002 = " << 0.00003 - 0.00002 << std::endl;
}

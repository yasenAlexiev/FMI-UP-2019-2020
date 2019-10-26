#include <iostream>

int main() {
	unsigned short player_number;
	std::cout << "Enter football player number: " << std::endl;
	std::cin >> player_number;

	if(player_number == 11) {
		std::cout << "Forward" << std::endl;
		return 0;
	}

	switch(player_number%10) {
		case 1: {
			std::cout << "Goalkeeper" << std::endl;
			break;		
		}
		case 2:
		case 3:
		case 4:
			std::cout << "Guard" << std::endl;
			break;
		case 5:
		case 6:
		case 7:
		case 8:
			std::cout << "Semi-guard" << std::endl;
			break;
		default:
			std::cout << "Forward" << std::endl;
			break;	
	}

	return 0;
}

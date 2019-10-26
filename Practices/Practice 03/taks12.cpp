#include <iostream>


int main() {
	unsigned short number;
	std::cout << "Enter your card number: " << std::endl;
	std::cin >> number;


	switch((number-1)%13) {
		case 0:
			std::cout << "2 of ";
			break;
		case 1:
			std::cout << "3 of ";
			break;
		case 2:
			std::cout << "4 of ";
			break;
		case 3:
			std::cout << "5 of ";
			break;
		case 4:
			std::cout << "6 of ";
			break;
		case 5:
			std::cout << "7 of ";
			break;
		case 6:
			std::cout << "8 of ";
			break;
		case 7:
			std::cout << "9 of ";
			break;
		case 8:
			std::cout << "10 of ";
			break;	
		case 9:
			std::cout << "Jack of ";
			break;
		case 10:
			std::cout << "Queen of ";
			break;
		case 11:
			std::cout << "King of ";
			break;
		case 12:
			std::cout << "Ace of ";
			break;
		default:
			std::cout << "Invalid card!" << std::endl;
			break;
	}

	switch((number-1)/13) {
		case 0:
			std::cout << "Spades" << std::endl;
			break;
		case 1:
			std::cout << "Heards" << std::endl;
			break;
		case 2:
			std::cout << "Diamonds" << std::endl;
			break;
		case 3:
			std::cout << "Clubs" << std::endl;
			break;	
		default:
			std::cout << "Invalid card!" << std::endl;
			break;
	}


	return 0;
}

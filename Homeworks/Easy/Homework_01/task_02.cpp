#include <iostream>

int main()
{
	int number;
	std::cout << "Please enter card number: ";
	std::cin >> number;

	short version = number / 100000000;
	short spec = (number / 1000000) % 10;
	int id = (number / 10) % 100000;

	bool versionIsValid = version >= 1 && version <= 9;
	bool specIsValid = spec != 7 && spec != 9;
	bool idIsValid = id != 0;

	if (!versionIsValid || !specIsValid || !idIsValid)
	{
		std::cout << "Invalid card number." << std::endl;
		return 0;
	}

	std::cout << "{ \"card_version\": " << version;
	std::cout << ", \"owner_spec\": \"";

	switch (spec)
	{
	case 0: std::cout << "Informatics"; break;
	case 1: std::cout << "Computer Science"; break;
	case 2: std::cout << "Information Systems"; break;
	case 3: std::cout << "Software Engineering"; break;
	case 4: std::cout << "Applied Mathematics"; break;
	case 5: std::cout << "Mathematics"; break;
	case 6: std::cout << "Statistics"; break;
	case 8: std::cout << "Mathematics and Informatics"; break;
	default:
		break;
	}

	std::cout << "\", \"owner_id\": " << id << " }" << std::endl;

	return 0;
}


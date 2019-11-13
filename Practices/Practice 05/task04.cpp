#include <iostream>

int main() {
	int current;
	std::cin >> current;
	int min = current, max = current, sum = 0, count = 0;

	while(current > 0) {
		if(current < min){
			min = current;
		}

		if(current > max) {
			max = current;
		}
		++count;
		sum += current;

		std::cin >> current;
	}

	std::cout << "Minimum: " << min << "\nMaximum: " << max << "\nAverage: " << sum/count << std::endl;

	return 0;
}

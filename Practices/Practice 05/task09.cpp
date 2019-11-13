#include <iostream>

int main() {
	int a, b, c, n;
	std::cin >> n >> a >> b >> c;
	bool check;	
	if(a >= b && b <= c) {
		check = true;				
	} else if(a <= b && b >= c) {
		check = false;
	} else {
		std::cout << "Nope" << std::endl;
		return -1;
	}

	for(int i = 0; i < n-3; ++i) {
		
		if(!check && a >= b && b <= c) {
			check = true;
		} else if(check && a <= b && b >= c) {
			check = false;
		} else {
			std::cout << "Nope" << std::endl;
			return -1;
		}

		a = b;
		b = c;
		std::cin >> c;
	}
	
	std::cout << "Yup" << std::endl;

	return 0;
}

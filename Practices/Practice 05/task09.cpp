#include <iostream>

int main() {
	int a, b, c, n;
	std::cin >> n >> a >> b;
	bool check;	
	if(a >= b) {
		check = true;				
	} else {
		check = false;
	}

	for(int i = 0; i < n-2; ++i) {
		std::cin >> c;	
		if(check && b <= c) {
			check = false;
		} else if(!check && b >= c) {
			check = true;
		} else {
			std::cout << "Nope" << std::endl;
			return -1;
		}

		a = b;
		b = c;
	}
	
	std::cout << "Yup" << std::endl;

	return 0;
}

#include <iostream>

int max(int a, int b) {
	return (a > b ? a : b);
}

double max(double a, double b) {
	return (a > b ? a : b);
}

int max(int a, int b, int c) {
	return max(a, max(b, c));
}

int max(int a, int b, int c, int d) {
	return max(a, max(b, c, d));
}
void task01() {
	int a, b;
	std::cout << "Enter two numbers: ";
	std::cin >> a >> b;

	std::cout << "Max between numbers is: " << max(a, b) << std::endl;
}

void task02() {
	double num1, num2;
	std::cout << "Enter two floating point numbers: ";
	std::cin >> num1 >> num2;
	
	std::cout << "Max between numbers is: " << max(num1, num2) << std::endl;
}

void task03() {
	int a, b, c;
	std::cout << "Enter three numbers: ";
	std::cin >> a >> b >> c;

	std::cout << "Max between numbers is: " << max(a, b, c) << std::endl;
}

void task04() {
	int a, b, c, d;
	std::cout << "Enter four numbers: ";
	std::cin >> a >> b >> c >> d;

	std::cout << "Max between numbers is: " << max(a, b, c, d) << std::endl;
}

int main() {
	task01();
	task02();
	task03();
	task04();

	return 0;
}

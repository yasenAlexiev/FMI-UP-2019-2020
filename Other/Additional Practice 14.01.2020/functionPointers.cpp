#include <iostream>
#include <math.h>

/*
Напишете функция която получава като аргументи затворен интервал ([a, b]),
допустима грешка (ε > 0) и указател към функция на един аргумент. Тя трябва 
чрез рекусия да намери всички корени на функцията, намиращи се в поддадения ви
итервал и да ги изведете на екрана (в резултата може да има грешка не надвишаваща
допустимата). Може теоремата на Болцано – Вайерщрас да ви помогне. :)
*/


typedef double(*MathFunction)(double);

double simpleSin(double x) {
	return sin(x);
}

double doubleSin(double x) {
	return 2*sin(x);
}

void findRoots(const double a, const double b, const double epsilon, MathFunction f) {
	if(a > b) {
		std::cout << std::endl;
		return;
	}
	if(f(a) - epsilon < 0) {
		std::cout << "root: " << a << std::endl;
	}
	findRoots(a+1, b, epsilon, f);
}


int main() {
	const double epsilon = 0.01;

	MathFunction f1 = simpleSin;
	MathFunction f2 = doubleSin;
	double a, b;
	std::cin >> a >> b;
	
	findRoots(a, b, epsilon, f1);
	findRoots(a, b, epsilon, f2);

	return 0;
}

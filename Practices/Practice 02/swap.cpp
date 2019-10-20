#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cout << "a = ";
	cin >> a;

	cout << "b = ";
	cin >> b;

	//swap with arithmetic operations
	a += b;
	b = a - b;
	a -= b;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;


	//swap with help varible
	c = a;
	a = b;
	b = c;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}

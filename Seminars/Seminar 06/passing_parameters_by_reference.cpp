#include <iostream>

// Tries to read input in the format - (1,3)
// If the reading is successful the functions returns true, we can use this to determine that first and second
// have meaningful values.
// If the reading fails the function return false, we can take appropiate measures - maybe show error message and stop the program.
bool tryReadInput(int& first, int& second)
{
	char leftParen, comma, rightParen;

	std::cin >> leftParen >> first >> comma >> second >> rightParen;

	if (leftParen != '(' || comma != ',' || rightParen != ')')
	{
		return false;
	}

	return true;
}

// If we want to use functions in main, we first have to declare them, putting all the functions above the main()
// creates clutter and blocks readability of the code. We can put the bodies of the functions below the main functions
// and declare only the type, name and parameters of the functions. After the compiling and linking the code will work even if the body
// is defined elsewhere.
void swap(int& a, int& b);
void print(int a, int b);
// What happens in the memory - draw a picture.

int main()
{
	int first, second;

	if (!tryReadInput(first, second))
	{
		std::cout << "Invalid input." << std::endl;
		return 1;
	}

	print(first, second);
	swap(first, second);
	print(first, second);
	
	return 0;
}

void swap(int& a, int& b)
{
	int temporary = a;
	a = b;
	b = temporary;
}

void print(int a, int b)
{
	std::cout << "first: " << a << std::endl << "second: " << b << std::endl << std::endl;
}

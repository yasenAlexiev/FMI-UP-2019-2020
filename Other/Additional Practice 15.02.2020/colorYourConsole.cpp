#include <iostream>



#if WIN32
	#define WIN_RED 12
	#define PRINT_RED_TEXT(x)	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);\
								SetConsoleTextAttribute(hConsole, WIN_RED);\
								std::cout << x << std::endl;
#else
	#define PRINT_RED_TEXT(x) std::cout << "\033[1;31m" << x << " \033[0m\n"
#endif

int main() {



	PRINT_RED_TEXT("Hello");

	return 0;
}

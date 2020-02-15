#include <iostream>

#if WIN32
	#define WIN_RED 12
	#define WIN_WHITE 23
	#define PRINT_RED_TEXT(x)	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);\
								SetConsoleTextAttribute(hConsole, WIN_RED);\
								std::cout << x << std::endl;
	
	#define PRINT_WHITE_TEXT(x)	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);\
								SetConsoleTextAttribute(hConsole, WIN_WHITE);\
								std::cout << x << std::endl;
#else
	#define LINUX_RED 31
	#define LINUX_WHITE 37
	#define PRINT_RED_TEXT(x) std::cout << "\033[1;" << LINUX_RED << "m" << x << " \033[0m\n"
	#define PRINT_WHITE_TEXT(x) std::cout << "\033[1;" << LINUX_WHITE << "m" << x << " \033[0m\n"
#endif

#define UP_ARROW 'w'
#define DOWN_ARROW 's'

int main() {
	size_t size = 5;
	const char* menu[size] = {"New game", "Load game", "High score", "Settings", "Exit"};
	int current = 0;

	char arrow;
	while(true) {
		for(int i = 0; i < size; ++i) {
			if(i == current) {
				PRINT_RED_TEXT(menu[i]);	
			} else {
				PRINT_WHITE_TEXT(menu[i]);
			}
		}

		std::cin >> arrow;
		if(arrow == UP_ARROW) {
			current--;
		} else if(arrow == DOWN_ARROW) {
			current++;
		}
		if(current < 0) {
			current = size-1;
		}
		if(current == size) {
			current = 0;
		}
	}

	return 0;
}

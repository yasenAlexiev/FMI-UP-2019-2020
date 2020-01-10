#include <iostream>
#include <string.h>

#define MAX_SIZE 1024

int main() {
	// А) Въведете абсолютен път на файл (примерно /D/Programming/FMI/UP/Practice/strings.cpp)
	// Запишете го в буферен статичен масив. След това го прехвърлете
	// в динамично заделен масив с точната дължина.

	char path[MAX_SIZE];
	std::cin >> path;
	size_t length_path = strlen(path);
	char* dynamic_path = new(std::nothrow) char[length_path + 1]; // +1 for terminate zero
	if(dynamic_path != nullptr) {	
		strcpy(dynamic_path, path);
		std::cout << dynamic_path << std::endl;
	}

	// Б) Изпишете имената на директориите в пътя

	char* buff = new(std::nothrow) char[length_path + 1];
	if(buff != nullptr) {	
		strcpy(buff, dynamic_path);

		char* token = strtok(dynamic_path, "/");
		while(token != nullptr) {
			std::cout << token << std::endl;
			token = strtok(nullptr, "/");
		}

		std::cout << dynamic_path << std::endl; // this pointer is invalid here
		// strtok change the dynamic_path pointer and we can't use it any more.
		// That's why we allocate other memory to hold on the original string
		// and after iteration with strtok:	
		delete[] dynamic_path;
		dynamic_path = buff;
		std::cout << dynamic_path << std::endl;
	}

	// В) Въведете име на търсена директория. Потърсете дали тя съществува
	// в пътя на файла.
	
	char directory[MAX_SIZE];
	std::cin >> directory;
	char* dynamic_dir = new(std::nothrow) char[strlen(directory) + 1];
	if(dynamic_dir != nullptr) {
		strcpy(dynamic_dir, directory);
		char* buff = new(std::nothrow) char[length_path + 1];
		if(buff != nullptr) {	
			strcpy(buff, dynamic_path);
		}

		char* token = strtok(dynamic_path, "/");
		while(token != nullptr) {
			if(strcmp(token, dynamic_dir) == 0) {
				std::cout << "Found directory" << std::endl;
				break;
			}
			token = strtok(nullptr, "/");
		}
		delete[] dynamic_path;
		dynamic_path = buff;

		delete[] dynamic_dir;
	}
	
	// Г) Въведете тип на файл, демек неговият extension.
	// Проверете дали файла е с този тип, който преди малко сте въвели.

	char extention[MAX_SIZE];
	std::cin >> extention;
	size_t length_ext = strlen(extention);
	char* dynamic_ext = new(std::nothrow) char[length_ext + 1];
	if(dynamic_ext != nullptr) {
		strcpy(dynamic_ext, extention);
		bool isValidExt = true;	
		for(int i = 0; i < length_ext; ++i) {
			if(dynamic_ext[length_ext - i - 1] != dynamic_path[length_path - i - 1]) {
				isValidExt = false;
				break;
			}	
		}

		if(isValidExt) {	
			std::cout << "Valid!" << std::endl;
		} else {
			std::cout << "Not valid!" << std::endl;	
		}

		delete[] dynamic_ext;
		delete[] dynamic_path;
	}

	return 0;
}

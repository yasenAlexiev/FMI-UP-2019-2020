#include <iostream>

#define WAIT std::cin.get()

#ifdef DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

#define ALLOC_SUCCEEDED(ptr) ptr != nullptr

#ifndef __FUNCTION_NAME__
	#if WIN32 // WINDOWS
		#define __FUNCTION_NAME__ __FUNCTION__
	#else
		#define __FUNCTION_NAME__ __func__
	#endif
#endif



int main() {

	LOG("Hello");

	int* ptr = new(std::nothrow) int[10];
	if( ALLOC_SUCCEEDED(ptr)) {
		std::cout << "Allocated successfully!" << std::endl;
		// do something
		delete[] ptr;	
	}

	std::cout << "Line: " << __LINE__ << std::endl;
	std::cout << "File: " << __FILE__ << std::endl;
	std::cout << "Date: " << __DATE__ << std::endl;
	std::cout << "Time: " << __TIME__ << std::endl;
	std::cout << "Function: " << __FUNCTION_NAME__ << std::endl;
	std::cout << "C++ Standart: " << __cplusplus << std::endl;


	WAIT;
	return 0;
}

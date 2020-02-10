#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision, std::setw

enum EType
{
	Char = 0,
	Bool,
	Int,
	Double,
	Float
};

void print(void* arr, size_t size, EType type) {
	switch(type) {
		case Char : {
			char* string = (char*)arr;
			std::cout << string << std::endl; 
			break;
		}
		case Bool : {
			bool* boolArr = (bool*)arr;
			for (int i = 0; i < size; ++i) {
				std::cout << (boolArr[i] ? "True " : "False ");
			}
			std::cout << std::endl;
			break;
		}
		case Int : {
			int* intArr = (int*)arr;
			for (int i = 0; i < size; ++i) {
				std::cout << intArr[i] << " ";
			}
			std::cout << std::endl;
			break;
		}
		case Double : {
			double* doubleArr = (double*)arr;
			for (int i = 0; i < size; ++i) {
				std::cout << std::setw(16);
				std::cout << std::setprecision(16) << doubleArr[i] << " ";
			}
			std::cout << std::endl;
			break;
		}
		case Float : {
			float* floatArr = (float*)arr;
			for (int i = 0; i < size; ++i) {
				std::cout << std::setw(16);
				std::cout << std::setprecision(8) << floatArr[i] << " ";
			}
			std::cout << std::endl;
			break;
		}
		default : {
			std::cout << "Unknown type" << std::endl;
		}
	}
}

void* alloc(size_t size, EType type) {
	switch(type) {	
		case Char : {
			return new(std::nothrow) char[size];
		}
		case Bool : {
			return new(std::nothrow) bool[size];
		}
		case Int : {
			return new(std::nothrow) int[size];
		}
		case Double : {
			return new(std::nothrow) double[size];
		}
		case Float : {
			return new(std::nothrow) float[size];
		}
		default : {
			std::cout << "Unknown type" << std::endl;
			return nullptr;
		}	
	}
}

int main() {
	{	
		size_t size		= 10;
		char* str		= (char*)alloc(size, Char);
		bool* boo		= (bool*)alloc(size, Bool);
		int* nums		= (int*)alloc(size, Int);
		double* doubles	= (double*)alloc(size, Double);
		float* floats	= (float*)alloc(size, Float);

		delete[] str;
		delete[] boo;
		delete[] nums;
		delete[] doubles;
		delete[] floats;
	}

	std::cout << "size void*: "			<< sizeof(void*) << std::endl;
	std::cout << "size double*: "		<< sizeof(double*) << std::endl;
	std::cout << "size const int*: "	<< sizeof(const int*) << std::endl;
	std::cout << "size const void*: "	<< sizeof(const void*) << std::endl;

	char str[]		= {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd' };
	bool boo[]		= {true, false, true, true, true, false, false, true, false };
	int nums[]		= {0, 1, -10, 2, 37, 42, -4, 2 };
	double doubles[]= {3.141542312, 2.71432342, .50000000001, -.1213123123, 4.21412598412, 2412.42817 };
	float floats[]	= {3.141542312f, 2.71432342f, .50000000001f, -.1213123123f, 4.21412598412f, 2412.42817f };

	print(str,		11,		Char);
	print(boo,		9,		Bool);
	print(nums,		8,		Int);
	print(doubles,	6,		Double);
	print(floats,	6, 		Float);

	return 0;
}

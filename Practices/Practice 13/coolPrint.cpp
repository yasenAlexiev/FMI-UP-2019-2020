#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

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
		case EType::Char : {
			char* string = (char*)arr;
			std::cout << string << std::endl; 
			break;
		}
		case EType::Bool : {
			bool* boolArr = (bool*)arr;
			for (int i = 0; i < size; ++i) {
				std::cout << (boolArr[i] ? "True " : "False ");
			}
			break;
		}
		case EType::Int : {
			int* intArr = (int*)arr;
			for (int i = 0; i < size; ++i) {
				std::cout << intArr[i] << std::endl;
			}
			break;
		}
		case EType::Double : {
			double* doubleArr = (double*)arr;
			for (int i = 0; i < size; ++i) {
				std::cout << std::setprecision(16) << doubleArr[i] << std::endl;
			}
			break;
		}
		case EType::Float : {
			float* floatArr = (float*)arr;
			for (int i = 0; i < size; ++i) {
				std::cout << std::setprecision(8) << floatArr[i] << std::endl;
			}
			break;
		}
	}

}

int main() {


	return 0;
}

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int* CreateArray(unsigned long long size)
{
	int * a = new int[size];
	return a;
}

int* CopyArray(int* arr, unsigned long long size)
{
	int* a = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		a[i] = arr[i];
	}

	return a;
}


// if we dont have MoveArray we can just do:
// Release(int * arr) { delete[] arr }
void Release(int*& arr)
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = nullptr;
}

void MoveArray(int*& dst, int*& src)
{
	dst = src;
	src = nullptr;
}

int main()
{
	{
		int* global = CreateArray(30);
		{
			int* a = CreateArray(10);
			int* b = CopyArray(a, 10);
			int* c = nullptr;
			MoveArray(c, global); // moving the ownership

			Release(a);
			Release(b);
			Release(c); // releasing c ( that is global ) because now c is the owner
		}
		Release(global);// releasing global
	}
	return 0;
}

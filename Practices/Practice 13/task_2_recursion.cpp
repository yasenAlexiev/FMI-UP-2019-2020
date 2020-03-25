#include <iostream>

void print(int *begin, int * end)
{
    for (int * i = begin; i != end; i++)
    {
        std::cout << *i;
    }
    std::cout << std::endl;
}

void f(int * begin, int * end, int c)
{
    for (size_t i = 0; i < 10; i++)
    {
        *(begin + c) = i;

        if (begin + c + 1 == end)
        {
            print(begin, end);
        }
        else
        {
            f(begin, end, c + 1);
        }
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    f(arr, arr + 5, 0);
    return 0;
}

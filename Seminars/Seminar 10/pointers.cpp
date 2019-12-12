#include <iostream>
using namespace std;

int main () {

    int a = 5, b = 6;
    int *p = &a;

    // p holds the address of a. p is a pointer
    cout<< a<< " at address "<< p<< endl;

    // referencing a and *p is more or less the same. This is the reason we can assign values to *p
    a += 1;
    cout<< a<< " = "<< *p<< endl;
    *p -= 1;
    cout<< a<< " = "<< *p<< endl;

    // this won't compile as pointers can't be assigned literals
    //p = 15;

    cout<< sizeof(p)<< endl;

    //p = NULL;
    p = nullptr;

    // at address 0
    cout<< p<< endl;
    // pointer arithmetic
    cout<< p+1<< endl;

    return 0;
}

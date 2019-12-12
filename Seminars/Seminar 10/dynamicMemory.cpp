#include <iostream>
using namespace std;

int main () {
    int* n = new int;
    *n = 5;

    cout<< *n<< endl;

    delete n;
    //cout<< *n<< endl;
    //delete n;
    n = nullptr;

    n = new (std::nothrow) int;
    if(n == nullptr) {
        cout<< "memory allocation failed\n";
        return 0;
    }
    delete n;
    n = nullptr;

    // dangling pointer
    n = new int;
    int* n1 = n;
    delete n;
    n = nullptr;

    // memory leak
    n = new int;
    n = new int;

    return 0;
}

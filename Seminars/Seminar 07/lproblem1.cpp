#include <iostream>
using namespace std;

// програмата трябва да дефинира масив
// и да го принтне наобратно (но има грешка)

int main () {
    int arr[8] = {15, 12, 14, 11};

    int s = sizeof(arr) / sizeof(int);
    int i = s;
    for(; i >= 0; --i) {
        cout<< arr[i]<< endl;
    }

    return 0;
}

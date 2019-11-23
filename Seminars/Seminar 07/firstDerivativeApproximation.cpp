#include <iostream>
using namespace std;

// апроксимация на първа производна
// yi = (xi+1 - xi-1)/2h

int main() {

    float x[] = {1, 4, 9, 16, 25, 36};
    float y[6];
    float h = 1;
    y[0] = 2;
    y[5] = 12;

    for(int i = 1; i< 5; ++i) {
        y[i] = (x[i+1] - x[i-1]) / 2*h;
    }

    for(int i = 0; i< 6; ++i) {
        cout<< y[i]<< " ";
    }
    cout<< endl;

    return 0;
}


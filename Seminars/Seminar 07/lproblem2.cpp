#include <iostream>
using namespace std;

// апроксимация на втора производна
// yi = (x[i+1] - 2x[i] + x[i-1])/h^2

int main() {

    float x[] = {1, 9, 27, 64, 125, 216};
    float y[6];
    float h = 1;
    y[0] = 6;
    y[5] = 36;

    for(int i = 1; i< 5; ++i) {
        // това ни дава апроксимацията на втората производна
        y[i] = (x[i+1] + (-2)*x[i] + x[i-1]) / h*h;
    }

    for(int i = 0; i< 6; ++i) {
        cout<< y[i]<< " ";
    }
    cout<< endl;

    return 0;
}

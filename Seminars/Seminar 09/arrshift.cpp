#include <iostream>
using namespace std;

void insertIntoArr(int arr[], int& n, int pos, int element) {
    for(int i=n-1; i>= pos; --i) {
        arr[i+1] = arr[i];
    }
    arr[pos] = element;
    n++;
}

int main () {

    int arr[15] = {1, 2, 182, -13, 56, 391, 473, 123, -7190, 13};
    int arrSize = 10;
    insertIntoArr(arr, arrSize, 3, 5);
    for(int i=0; i< arrSize; ++i) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;

    return 0;
}

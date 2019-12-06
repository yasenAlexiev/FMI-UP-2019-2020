#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int currEl;
    int j;
    for(int i=0; i< n; ++i) {
        currEl = arr[i];
        for(j=i; (j>0) && (currEl < arr[j-1]); --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = currEl;
    }
}

int main () {

    int arr[] = {1, 2, 182, -13, 56, 391, 473, 123, -7190, 13};
    int arrSize = sizeof(arr)/sizeof(int);
    insertionSort(arr, arrSize);
    for(int i=0; i< arrSize; ++i) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;

    return 0;
}

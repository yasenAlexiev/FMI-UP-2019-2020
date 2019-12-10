#include <iostream>
using namespace std;

void swapEl(int& v1, int& v2) {
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

int minIndex(int arr[], int startIndex, int endIndex) {
    int minInd = startIndex;
    for(int i=startIndex; i< endIndex; ++i) {
        if(arr[i] < arr[minInd]) {
            minInd = i;
        }
    }
    return minInd;
}

void selectionSort(int arr[], int n) {
    int minInd;
    int temp;
    for(int i=0; i< n; ++i) {
        minInd = minIndex(arr, i, n);
        swapEl(arr[i], arr[minInd]);
    }
}

int main () {

    int arr[] = {1, 2, 182, -13, 56, 391, 473, 123, -7190, 13};
    int arrSize = sizeof(arr)/sizeof(int);
    selectionSort(arr, arrSize);
    for(int i=0; i< arrSize; ++i) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;

    return 0;
}

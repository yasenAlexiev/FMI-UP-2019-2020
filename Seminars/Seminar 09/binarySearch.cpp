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

int findIndex(int arr[], int n, int value) {
    int left = 0;
    int right = n-1;
    int mid;
    while(right-left >= 0) {
            for(int i = left; i< right+1; ++i) {
                cout<< arr[i]<< " ";
            }
            cout<< endl;
        mid = left + (right-left)/2;
        if(arr[mid] == value) {
            return mid;
        }

        if(arr[mid] < value) {
            left = mid+1;
            continue;
        } else {
            right = mid-1;
            continue;
        }
    }

    return -1;
}

int main () {

    int arr[] = {1, 2, 182, -13, 56, 391, 473, 123, -7190, 13};
    int arrSize = sizeof(arr)/sizeof(int);
    insertionSort(arr, arrSize);
    for(int i=0; i< arrSize; ++i) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
    cout<< findIndex(arr, arrSize, 123)<< endl;

    return 0;
}

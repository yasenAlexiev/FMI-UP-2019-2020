#include <iostream>
using namespace std;

// prints the common elements to two arrays

int main () {
    int arr1[] = {1, 3, 5, 7, 9, 10};
    int arr2[] = {4, 5, 6, 7, 8};

    for(int i = 0; i< 5; ++i) {
        for(int j = 0; j< 4; ++j) {
            if(arr1[i] == arr2[j]) {
                cout<< arr1[i]<< " ";
                continue;
            }
        }
    }

    return 0;
}

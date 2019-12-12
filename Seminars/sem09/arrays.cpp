#include <iostream>
using namespace std;

void change(int arr[], int i, int value) {
    arr[i] = value;
}

int main () {

    const int n = 7;
    int arr[] = {15, 18, -7, 16, 8, 1267, 89};
    cout<< *arr<< endl;
    cout<< *(arr+2)<< endl;

    change(arr, 1, 87);
    for(int i = 0; i< n; ++i) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;

    int* arrp = arr;
    cout<< sizeof(arrp)<< " =/= "<< sizeof(arr)<< endl;

    for(int* iter = arr; iter< (arr+n); ++iter) {
        cout<< *iter<< " ";
    }
    cout<< endl;

    return 0;
}

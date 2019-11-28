
#include<iostream>
using namespace std;

int main () {

    int A[2][3] = {{1,2,3}, {4,5,6}};
    int B[3][2] = {{1,2}, {3,4}, {5,6}};
    int result[2][2] = {};

    for(int i=0; i< 2; ++i) {
        for(int j=0; j< 2; ++j) {
            for(int l=0; l< 3; ++l) {
                result[i][j] += A[i][l]*B[l][j];
            }
        }
    }

    for(int i=0; i< 2; ++i) {
        for(int j=0; j< 2; ++j) {
            cout<< result[i][j]<< " ";
        }
        cout<< endl;
    }

    return 0;
}

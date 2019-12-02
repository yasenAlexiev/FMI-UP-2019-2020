#include<iostream>
using namespace std;

int main () {

    double weekHours[7][24];

    for(int i=0; i< 7; ++i) {
        for(int j=0; j< 24; ++j) {
            cin>> weekHours[i][j];
        }
    }

    return 0;
}
